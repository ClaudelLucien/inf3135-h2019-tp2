CP= $(shell cat cp.txt)



default:tp2.c
	gcc tp2.c -Wall -pedantic -std=c99 -o tp2  

	

test:
	./tp2

test1:
	
	./tp2 -c $(CP) -i data.txt -o sortie	

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


