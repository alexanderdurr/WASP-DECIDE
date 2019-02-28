CC=gcc

hello: hello.o
	$(CC) -o hello hello.o
	make removeO

hello.o: hello.c
	$(CC) -c hello.c

example1_decide: example1_decide.o decide.o
	$(CC) -o example1_decide example1_decide.o decide.o -lm
	make removeO

example1_decide.o: example1_decide.c
	$(CC) -c example1_decide.c

example2_decide: example2_decide.o decide.o
	$(CC) -o example2_decide example2_decide.o decide.o -lm
	make removeO

example2_decide.o: example2_decide.c
	$(CC) -c example2_decide.c

testing_decide: testing_decide.o decide.o
	$(CC) -o testing_decide testing_decide.o decide.o -lm
	make removeO

testing_decide.o: testing_decide.c
	$(CC) -c testing_decide.c

decide.o: decide.c
	$(CC) -c decide.c

clean:
	rm -f *.o hello  example1_decide example2_decide testing_decide

removeO:
	rm -f *.o
