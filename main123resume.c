# include <string.h>

# include <stdlib.h>

# include <stdio.h>

# include <unistd.h>

 

 

int main(void){

               char *debut="$./enseash\n";

               char *bienvenue="Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n";

               char *prompt="enseash % ";

               write(STDOUT_FILENO, debut, strlen(debut));

               write(STDOUT_FILENO, bienvenue, strlen(bienvenue));

               char *stringIn=malloc(256*sizeof(char)); // allocation dynamique de mémoire

               int continuer=1;

               while(continuer){

                              write(STDOUT_FILENO, prompt, strlen(prompt));

                              int entree=read(STDIN_FILENO, stringIn,256); // lecture du texte entré dans le descripteur de fichier (clavier)

                              if ((strncmp(stringIn, "exit", strlen("exit"))==0) || (entree==0)){

                                            write(STDOUT_FILENO,"Bye bye...\n$\n", strlen("Bye bye...\n$\n"));

                                            continuer=0;

                              }

                              else if (strncmp(stringIn, "fortune", strlen("fortune"))==0){

                                            write(STDOUT_FILENO,"Today is what happened to yesterday.\n", strlen("Today is what happened to yesterday.\n"));

                              }

               }

}

 

 

// résumé des premières questions en un fichier

// On pourrait utiliser " # define" pour le code d'accueil et de sortie

// #define BIENVENUE "Bienvenue dans le Shell ENSEA.\nPour quitter, tapez 'exit'.\n"

// #define PROMPT "enseash % "

// #define BYEBYE "Bye bye...\n$\n"