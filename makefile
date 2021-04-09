CC=g++
CFLAGS=-I.

make:
	$(CC)  test.cpp -o test


clean:
	rm -f test.o test