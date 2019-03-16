#!/bin/bash
# evaluer.sh
wget -q https://github.com/guyfrancoeur/INF3135_H2019_TP2/raw/master/inf3135-h2019-tp2.correction -O inf3135-h2019-tp2.correction
if [ ! -f inf3135-h2019-tp2.correction ]
then
  exit 1

fi



note=0
compteur=0
while read line
do
commande=${line:29}
eval $commande
retour=$?

retourprof=${line:5:1}



if [ "$retour" = "$retourprof" ]; then 
echo -e "$compteur:reussi 1 point"
note=$((note+1))
else echo -e "$compteur:echec"
fi
compteur=$((compteur+1))



done < inf3135-h2019-tp2.correction
echo "$note"
