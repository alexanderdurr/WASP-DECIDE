CC=gcc

outputHello: hello.o
	$(CC) -o hello hello.o
	make removeO

outputHello.o: hello.c
	$(CC) -c hello.c

outputExample1: example1_decide.o decide.o
	$(CC) -o example1_decide example1_decide.o decide.o
	make removeO

outputExample1.o: example1_decide.c
	$(CC) -c example1_decide.c

outputDecide.o: decide.c
	$(CC) -c decide.c

clean:
	rm -f *.o hello  example1_decide

removeO:
	rm -f *.o
