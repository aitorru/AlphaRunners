CC=gcc
CFLAGS=
MAINC=main.c
EMPLOY=Employee.c
RUNNER=Runner.c
OUTPUT=a.out

build: main.c Employee/Employee.c Runner/Runner.c
	$(CC) -o Debug/$(OUTPUT) $(MAINC) Employee/$(EMPLOY) Runner/$(RUNNER) $(CFLAGS)

buildT: main.c Employee/Employee.c Runner/Runner.c
	$(CC) -o $(OUTPUT) $(MAINC) Employee/$(EMPLOY) Runner/$(RUNNER) $(CFLAGS)


run: 
	./Debug/a.out

clean:
	rm -fr Debug/*