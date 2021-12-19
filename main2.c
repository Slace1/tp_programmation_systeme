# include <string.h>

# include <stdlib.h>

# include <stdio.h>

# include <unistd.h>





void commande (void){

	char* prompt="enseash % ";

	char *stringIn=malloc(256*sizeof(char)); // allocation dynamique de mémoire

	while(1){

		write(STDOUT_FILENO, prompt, strlen(prompt));

		read(STDIN_FILENO, stringIn,256); // lecture du texte entré dans le descripteur de fichier (clavier)

		if (strncmp(stringIn, "fortune", strlen("fortune"))==0){

			write(STDOUT_FILENO,"Today is what happened to yesterday.\n", strlen("Today is what happened to yesterday.\n"));

			write(STDOUT_FILENO, prompt, strlen(prompt));

		}

	}

}





int main(void){

	commande();

}





// Lecture d'une commande saisie par l'utilisateur à l'aide de la fonction read

// Si l'on écrit "fortune", on valide la condition du "if" puis on exécute le code à l'intérieur de cette condition.

// strncmp est une fonction qui compare deux chaînes de caractère, ces arguments en entrée sont les 2 chaînes à comparer et la taille du comparant (la 2ème chaîne de caractère)

// Retour au prompt peu importe la commande écrite en attendant la commande suivante.

