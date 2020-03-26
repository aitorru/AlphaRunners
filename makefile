CC=gcc
CFLAGS=
MAINC=main.c
EMPLOY=Employee/Employee.c
RUNNER=Runner/Runner.c
TREE=Debug/
OUTPUT=a.
WINEXT=exe
UNIXEXT=out
PLATFORM := $(shell uname) # WIP OS detect
ifeq  ($(PLATFORM),Linux)
	EXT=out
else
	EXT=exe
endif

build: main.c Employee/Employee.c Runner/Runner.c
	$(CC) -o $(TREE)$(OUTPUT)$(EXT) $(MAINC) $(EMPLOY) $(RUNNER) $(CFLAGS)
	

buildT: main.c Employee/Employee.c Runner/Runner.c
	$(CC) -o $(OUTPUT)$(EXT) $(MAINC) $(EMPLOY) $(RUNNER) $(CFLAGS)


run: 
	./$(TREE)$(OUTPUT)$(EXT)

clean:
	rm -fr Debug/*