CC=gcc
SRC=./src/

example1_decide: $(SRC)example1_decide.o $(SRC)decide.o
	$(CC) -o example1_decide $(SRC)example1_decide.o $(SRC)decide.o -lm
	make removeO

example1_decide.o: $(SRC)example1_decide.c
	$(CC) -c $(SRC)example1_decide.c

example2_decide: $(SRC)example2_decide.o $(SRC)decide.o
	$(CC) -o example2_decide $(SRC)example2_decide.o $(SRC)decide.o -lm
	make removeO

example2_decide.o: $(SRC)example2_decide.c
	$(CC) -c $(SRC)example2_decide.c

testing_decide: $(SRC)testing_decide.o $(SRC)decide.o
	$(CC) -o testing_decide $(SRC)testing_decide.o $(SRC)decide.o -lm
	make removeO

testing_decide.o: $(SRC)testing_decide.c
	$(CC) -c $(SRC)testing_decide.c

decide.o: $(SRC)decide.c
	$(CC) -c $(SRC)decide.c

clean:
	rm -f *.o $(SRC)*.o hello  example1_decide example2_decide testing_decide

removeO:
	rm -f *.o
