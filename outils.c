#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "outils.h"



//Début des Fonctions



unsigned long* LireFichier(int indice, char * argv[]){
	FILE * fichier = NULL;
	fichier = fopen(argv[indice], "r+");
	static unsigned long tableau[2]={0};
	if (fichier != NULL){
	fscanf(fichier, "%lu%lu", & tableau[0], & tableau[1]);
	  if(tableau[1]<tableau[0]){
	  unsigned long a=tableau[1];
	  tableau[1]=tableau[0];
	  tableau[0]=a;
	  }
	fclose(fichier);
	}
	else{ 
	printf("le fichier en entrée est vide");
	exit(5);
	}
	return tableau;
}

unsigned long* LireEntree(){

	static unsigned long tableauval[2]= {0};
	scanf("%lu%lu",& tableauval[0], & tableauval[1]);
 	if(tableauval[1]<tableauval[0]){
  	  unsigned long a=tableauval[1];
	  tableauval[1]=tableauval[0];
	  tableauval[0]=a;
	  }

	return tableauval;
}




void rechercheFichier(unsigned long tableau[], char argv[]){
    		int l = 0;
                  int m = 0;
                  int somme = 0;
		  unsigned long borneInf = tableau[0];
		  unsigned long borneSup = tableau[1];
                  FILE * sortie = NULL;
                  sortie = fopen(argv, "w+");
                  for (l = borneInf; l <= borneSup; l++) {
                    somme = 0;
                    for (m = 1; m < l; m++) {
                      if (l % m == 0) {
                        somme = somme + m;
                      }
                    }
                    if (somme == l) {
                      fprintf(sortie, "%d\n", l);
                    }
                  }
                  fclose(sortie);
}

void rechercher(unsigned long tableau[]){
                int l = 0;
                  int m = 0;
                  int somme = 0;
                  unsigned long borneInf = tableau[0];
                  unsigned long borneSup = tableau[1];
                  for (l = borneInf; l <= borneSup; l++) {
                    somme = 0;
                    for (m = 1; m < l; m++) {
                      if (l % m == 0) {
                        somme = somme + m;
                      }
                    }
                    if (somme == l) {
                      printf("%d\n", l);
                    }
                  }

}


int verifierCP(int argc, char * argv[]){
 for (int i = 0; i < argc; i++)

    {
        if (strcmp(argv[i], "-c") == 0 && strlen(argv[i + 1]) == 12) {
        FILE * code = NULL;
        code = fopen("code.txt","w+");
        fprintf(code,"%s\n",argv[i+1]);
        fclose(code);
	return 0;
        }
	else if (strcmp(argv[i], "-c") == 0 && strlen(argv[i + 1]) != 12) {
        printf("pas12caract");
         return 2;
        }
    }
return 0;
}


