
#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>

#include <string.h>

#include <sys/wait.h>

#include <time.h>



#define CONV_NS_MS 1000000





void retourTime(void){

	char *prompt="enseash % ";

	write(1, prompt, strlen(prompt));

	struct timespec time_start, time_stop;

	clock_gettime(CLOCK_REALTIME, &time_start); // récupère le temps de départ

	while (1){

		pid_t pid=fork();

		int status=0;

		char *stringIn=malloc(256*sizeof(char));

		read(STDIN_FILENO, stringIn,strlen(stringIn));

		if (pid==-1)

			write(STDOUT_FILENO,"erreur sur le fork\n",strlen("erreur sur le fork\n"));

		else if (pid==0){  // code fils

			write(STDOUT_FILENO, prompt, strlen(prompt));

		}

		else{ // code père: pid>0

			clock_gettime(CLOCK_REALTIME, &time_stop);// récupère le temps de fin d'exécution

			unsigned long long int duree = time_stop.tv_nsec - time_start.tv_nsec ; // temps d'exécution

			if(WIFEXITED(status)){

				sprintf(prompt, "enseash [exit:%d|%lldns] %% ", WEXITSTATUS(status), (duree/CONV_NS_MS));

			}

			if(WIFSIGNALED(status)){

				sprintf(prompt, "enseash [sign:%d|%lldns] %% ", WTERMSIG(status), (duree/CONV_NS_MS));

			}

		}

	}

}



int main(){

	retourTime();

}



// clock_gettime permet de récupérer un temps à l'aide de cette fonction on calcule le temps d'exécution d'un programme

// le define permet de faire la conversion ns en ms
//ATTENTION : il faut appuyer sur entrée deux fois pour que le programme fonctionne !
