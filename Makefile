build: movies.c labirint.c
	gcc -g -Wall -ansi movies.c Tasks.h Utils.c Graph.c -o movies
	gcc -g -Wall -ansi labirint.c -o labirint

clean:
	rm -f movies
	rm -f labirint

run_movies: movies
	./movies

run_labirint: labirint
	./labirint

leaks_movies: movies
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./movies

leaks_labirint: labirint
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./labirint

movies:
	gcc -g -Wall -ansi movies.c Tasks.h Utils.c Graph.c -o movies
labirint:
	gcc -g -Wall -ansi labirint.c -o labirint
