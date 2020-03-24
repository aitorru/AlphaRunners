CC=gcc
CFLAGS=-lm

build: main.c Employee/Employee.c Runner/Runner.c
	./check.out
	$(CC) -o Debug/a.out main.c $(CFLAGS)

run: 
	./Debug/a.out

clean:
	rm -fr Debug/*