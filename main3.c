# include <string.h>

# include <stdlib.h>

# include <stdio.h>

# include <unistd.h>





void sortie (void){

	char* prompt="enseash % ";

	char *stringIn=malloc(256*sizeof(char));

	int continuer=1;

	while(continuer){

		write(STDOUT_FILENO, prompt, strlen(prompt));

		int entree=read(STDIN_FILENO, stringIn,256);

		if ((strncmp(stringIn, "exit", strlen("exit"))==0) || (entree==0)){

			write(STDOUT_FILENO,"Bye bye...\n$\n", strlen("Bye bye...\n$\n"));

			continuer=0;

		}

	}

}



int main(void){

	sortie();

}



// cette fonction permet de sortir du Shell de deux manières soit en
//écrivant "exit" soit en faisant un contrôle D.

// La première méthode repose sur la comparaison entre la chaîne de caractères
//rentrée et "exit" à l'aide de strncmp et l'autreutilise la valeur de
//retour de read EOF=End Of File (aucun caractère entré)
