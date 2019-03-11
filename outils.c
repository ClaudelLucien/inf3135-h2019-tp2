

int recherche(int argc, char * argv[]){
  int i;
    int j;
    int k;
    if (argc % 2 == 0) {
      printf("Mauvais nombre d'arguments\n");
      return 1;
    }

    for (i = 0; i < argc; i++)

    {


        if (strcmp(argv[i], "-c") == 0 && strlen(argv[i + 1]) == 12) {

        FILE * code = NULL;
        code = fopen("code.txt","w+");
        fprintf(code,"%s\n",argv[i+1]);
        fclose(code);
          for (j = 0; j < argc; j++) {
            if ((strcmp(argv[j], "-i") == 0 || strcmp(argv[j],"<")==0)  && strcmp(argv[j + 1], "data.txt") == 0) {

              for (k = 0; k < argc; k++) {
                if ((strcmp(argv[k], "-o") == 0 || strcmp(argv[k],">") ==0) && strcmp(argv[k + 1], "") != 0) {

                  FILE * fichier = NULL;

                  fichier = fopen("./data/data.txt", "r+");
                  int tableau[2] = {
                    0
                  };
                  int borneInf;
                  int borneSup;
                  if (fichier != NULL)

                  {
                    fscanf(fichier, "%d %d", & tableau[0], & tableau[1]);
                    borneInf = tableau[0];
                    borneSup = tableau[1];
                    fclose(fichier);

                  } else

                  {

                    printf("Impossible d'ouvrir le fichier test.txt");
                    return 5;
                  }
                  if (borneInf <0 || borneSup<0 ) {
                    return 4;
                  }

                  int l = 0;
                  int m = 0;
                  int somme = 0;
                  FILE * sortie = NULL;
                  sortie = fopen(argv[k + 1], "w+");
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
                  return 0;

                }

              }

            }

          }

        } else if (strcmp(argv[i], "-c") == 0 && strlen(argv[i + 1]) != 12) {
        printf("pas12caract");
 
         return 2;
        }       

    }
return 0;
}

