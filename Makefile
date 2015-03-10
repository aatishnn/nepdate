all: example.o date.o
	gcc example.o date.o -o example

clean:
	rm -rf *.o
	rm example
