CC=gcc
CFLAGS=-lm

build: main.c Employee/Employee.c Runner/Runner.c
	$(CC) -o Debug/a.out main.c Employee/Employee.c Runner/Runner.c $(CFLAGS)

run: 
	./Debug/a.out

clean:
	rm -fr Debug/*