#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "outils.h"
#include <math.h>


//Début des Fonctions



long long* LireFichier(int indice, char * argv[]){
	FILE * fichier = NULL;
	fichier = fopen(argv[indice], "r+");
	static long long tableau[2]={0};
	if (fichier != NULL){
	fscanf(fichier, "%lld%lld", & tableau[0], & tableau[1]);
	  if(tableau[1]<tableau[0]){
	  long long a=tableau[1];
	  tableau[1]=tableau[0];
	  tableau[0]=a;
	  }
	  else if(tableau[0]<0 || tableau[1]<0){
	  exit(4);
	  }
	fclose(fichier);
	}
	else{ 
	exit(5);
	}
	return tableau;
}

long long* LireEntree(){

	static long long tableauval[2]= {0};
	scanf("%lld%lld",& tableauval[0], & tableauval[1]);
 	if(tableauval[1]<tableauval[0]){
  	  long long a=tableauval[1];
	  tableauval[1]=tableauval[0];
	  tableauval[0]=a;
	  }
	else if(tableauval[0]<0 || tableauval[1]<0){
          exit(4);
          }

	return tableauval;
}




void rechercheFichier(long long tableau[], char argv[]){

       	long long borneInf = tableau[0];
	long long borneSup = tableau[1];
        FILE * sortie = NULL;
        sortie = fopen(argv, "w+");
        	for(int i = borneInf ; i<=borneSup; i++){
                	if (EstPremier(i)==0){
                  	int premier=puiss(2,(i-1))*(puiss(2,i)-1);
                        	if(premier<borneSup){
                        	fprintf(sortie,"%d\n",premier);
                        	}
                        	else{
                        	break;
                        	}
                        }
		}
                fclose(sortie);
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

int EstPremier(int nombre){

	if(nombre ==1){
	return 1;
	}
	if(nombre==2){
	return 0;
	}
		for (int i =2 ; i<=nombre-1;i++){
			if (nombre%i==0){
			return 1;
    			}
		}
return 0;
}

void rechercher(long long tableau[]){
	long long borneInf = tableau[0];
        long long borneSup = tableau[1];
	for(int i = borneInf ; i<=borneSup; i++){
		if (EstPremier(i)==0){
		int premier=puiss(2,(i-1))*(puiss(2,i)-1);
			if(premier<borneSup){
			printf("%d\n",premier);
			}
			else{
			break;
			}
		}
	}
}



int puiss (int x, unsigned int n){
   int y = 1;
   unsigned int m = 1;
   while (m <= n) {
      y *= x;
      m++;
   }
   return y;
}
