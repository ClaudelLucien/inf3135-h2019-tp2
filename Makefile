CP= $(shell cat cp.txt)

RAC=-Wall -pedantic -std=c99

default:tp2



outils.o: outils.h outils.c
	gcc $(RAC) -c outils.c
tp2.o: tp2.c
	gcc $(RAC) -c tp2.c

tp2: outils.o tp2.o
	gcc $(RAC) -o tp2 tp2.o outils.o 


test:
	./tp2

test1:
	
	for file in data/* ; do ./tp2 -c $(CP) -i $$file -o sortie; done ; cat sortie;


clean:
	
	rm -f data.zip
	rm -f code.txt
	rm -f resultat.txt
data:
	wget  https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip
	unzip data
	mkdir data
	mv data.txt ./data

resultat:
	./tp2 -c CLAL12049707 -i data.txt -o resultat.txt
	git add resultat.txt
	git commit
	git push


