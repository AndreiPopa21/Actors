all: clean build

build: movies.c labirint.c
	gcc -g  -Wall -ansi movies.c Tasks.c Utils.c Graph.c Queue.c -o movies
	gcc -g  -Wall -ansi labirint.c -o labirint

clean:
	rm -f movies
	rm -f labirint

run_movies: movies
	./movies -c1 test1.in r.out

run_labirint: labirint
	./labirint

leaks_movies: movies
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./movies -c3 test24.in r.out

leaks_labirint: labirint
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./labirint

movies:
	gcc -g -Wall -ansi movies.c Tasks.c Utils.c Graph.c Queue.c -o movies
labirint:
	gcc -g -Wall -ansi labirint.c -o labirint

push_m:
	git push origin movies
push_l:
	git push origin labirint
