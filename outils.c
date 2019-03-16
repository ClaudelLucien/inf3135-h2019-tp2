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
	if(fscanf(fichier, "%lld%lld", & tableau[0], & tableau[1])==0){
	  if(tableau[1]<tableau[0]){
	  long long a=tableau[1];
	  tableau[1]=tableau[0];
	  tableau[0]=a;
	  }
	  else if(tableau[0]<0 || tableau[1]<0){
	  exit(4);
	  }
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
	if(scanf("%lld%lld",& tableauval[0], & tableauval[1])==0){
 	if(tableauval[1]<tableauval[0]){
  	  long long a=tableauval[1];
	  tableauval[1]=tableauval[0];
	  tableauval[0]=a;
	  }
	else if(tableauval[0]<0 || tableauval[1]<0){
          exit(4);
          }
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
        //printf("pas12caract");
         return 2;
        }
    }
return 0;
}

int EstPremier(unsigned long nombre){

	if(nombre ==1){
	return 1;
	}
	if(nombre==2){
	return 0;
	}
	unsigned long rac_nombre=sqrt(nombre)+1;
		for (unsigned long i =2 ; i<=rac_nombre-1;i++){
			if (nombre%i==0){
			return 1;
    			}
		}
return 0;
}

void rechercher(long long tableau[]){
	long long borneInf = tableau[0];
        long long borneSup = tableau[1];
	for(long long i = borneInf ; i<=borneSup; i++){
		if (EstPremier(i)==0){
		long long premier=puiss(2,(i-1))*(puiss(2,i)-1);
			if(premier<borneSup){
			printf("%lld\n",premier);
			}
			else{
			break;
			}
		}
	}
}



long long puiss (long long x, unsigned long n){
   long long y = 1;
   unsigned long m = 1;
   while (m <= n) {
      y *= x;
      m++;
   }
   return y;
}
