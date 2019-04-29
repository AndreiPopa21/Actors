build: movies.c labirint.c
	gcc -g -Wall -ansi movies.c -o movies
	gcc -g -Wall -ansi labirint.c -o labirint
clean:
	rm -f movies
	rm -f labirint
run movies:
	./movies
run labirint:
	./labirint
