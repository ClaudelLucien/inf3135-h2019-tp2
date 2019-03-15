
#include "outils.h"


  //note : argc compte les arguments
  //le premier est toujours l'executable
  int main(int argc, char * argv[]) {

    if (argc==1) {
      printf("Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
      return 1;
    }

 if (argc==3){
verifierCP(argc,argv);
rechercher(LireEntree());
}

if (argc==5){
verifierCP(argc,argv);

 for (int j = 0; j < argc; j++) {
     if (strcmp(argv[j], "-i") == 0 ) {
     int indice = j+1;
     rechercher(LireFichier(indice,argv));
     }
     else if(strcmp(argv[j], "-o") == 0){
     rechercheFichier(LireEntree(),argv[j+1]);
     
     }
 }
}

if(argc==7){
verifierCP(argc,argv);
	for (int j = 0; j < argc; j++) {
	     if (strcmp(argv[j], "-i") == 0 && strcmp(argv[j+1],"") != 0) {
	     int indice = j+1;
	        for (int k=0;k<argc;k++){
		   if(strcmp(argv[k],"-o") == 0 && strcmp(argv[k+1],"") != 0) {
	           rechercheFichier(LireFichier(indice,argv),argv[k+1]);
		   }
		}
     	     }
	    
	}
}



}//Fin du main


