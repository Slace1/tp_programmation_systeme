# include <string.h>

# include <stdlib.h>

# include <stdio.h>

# include <unistd.h>

# include <sys/types.h>

# include <sys/stat.h>

#include <sys/wait.h>



void retour(void){

	char *prompt="enseash % ";

	write(1, prompt, strlen(prompt));

	while (1){

		pid_t pid=fork();
//creation d'un fils
		int status;

		char stringIn[20];

		read(STDIN_FILENO, stringIn,strlen(stringIn));

		if (pid==-1)//gestion de l'erreur

			write(STDOUT_FILENO,"erreur sur le fork\n",strlen("erreur sur le fork\n"));

		else if (pid!=0){ // code père

			if(WIFEXITED(status)){

				write(STDOUT_FILENO,"enseash [exit:0] % ", strlen("enseash [exit:0] % "));

			}

			if(WIFSIGNALED(status)){

				write(STDOUT_FILENO,"enseash [sign:9] %", strlen("enseash [sign:9] %"));

			}

		}

		else{  // code fils (pid==0)

			write(STDOUT_FILENO, prompt, strlen(prompt));

		}

	}

}



int main(){

	retour();

}



// WIFEXITED (status) est vrai si le fils s'est terminé normalement

// WIFSIGNALED (status) est vrai si le fils s'est terminé à cause d'un signal
//(ex: kill, ctrl-C, ...)

// fork crée un nouveau processus

// On affiche le code de la commande précédente
