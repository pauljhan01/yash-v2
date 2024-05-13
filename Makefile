yash: main.o jobs/jobs.o parse/parse.o pipe/pipe.o redirect/redirect.o signal/signal.o
	gcc -o yash main.o jobs/jobs.o parse/parse.o pipe/pipe.o redirect/redirect.o signal/signal.o -lreadline

main.o: main.c
	gcc -c main.c

jobs.o: jobs/jobs.c
	gcc -c jobs/jobs.c

parse.o: parse/parse.c
	gcc -c parse/parse.c

pipe.o: pipe/pipe.c
	gcc -c pipe/pipe.c

redirect.o: redirect/redirect.c
	gcc -c redirect/redirect.c

signals.o: signal/signalc.c
	gcc -c signal/signal.c

clean:
	rm -f yash *.o */*.o