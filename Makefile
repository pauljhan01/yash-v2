yash: main.c jobs/jobs.c parse/parse.c pipe/pipe.c redirect/redirect.c signal/signal.c
	gcc -g -o yash main.c jobs/jobs.c parse/parse.c pipe/pipe.c redirect/redirect.c signal/signal.c -lreadline

clean:
	rm -f yash *.o */*.o