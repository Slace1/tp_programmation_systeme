# include <string.h>

# include <stdlib.h>

# include <stdio.h>

# include <unistd.h>





void accueil (void){

	char *debut="$./enseash\n";

	char *bienvenue="Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";

	char *prompt="enseash % ";

	write(STDOUT_FILENO, debut, strlen(debut));
//STDOUT_FILENO correspond au terminal que l'on utilise
	write(STDOUT_FILENO, bienvenue, strlen(bienvenue));

	write(STDOUT_FILENO, prompt, strlen(prompt));

	write(STDOUT_FILENO, "\n", strlen("\n"));

}





int main(void){

	accueil();

}



// Cette fonction permet d'afficher le message d'accueil demandé à l'aide de la fonction write




