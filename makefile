CC=gcc
CFLAGS=
MAINC=main.c
EMPLOY=Employee/Employee.c
RUNNER=Runner/Runner.c
RACE=Race/race.c
TREE=Debug/
OUTPUT=a.
WINEXT=exe
UNIXEXT=out
PLATFORM = $(shell uname -s) # WIP OS detect
EXT = $(osdetected)
ifeq  ($(OS),Windows_NT)
	PLATFORM = Windows
	osdetected = exe
else
	osdetected = out
endif

build:  $(MAINC) $(EMPLOY) $(RUNNER) $(RACE)
	@echo Target build: $(PLATFORM) Using ext: $(EXT)
	$(CC) -o $(TREE)$(OUTPUT)$(EXT) $(MAINC) $(EMPLOY) $(RUNNER) $(RACE) $(CFLAGS)
	

buildT: $(MAINC) $(EMPLOY) $(RUNNER) $(RACE)
	$(CC) -o $(OUTPUT)$(EXT) $(MAINC) $(EMPLOY) $(RUNNER) $(RACE) $(CFLAGS)


run: 
	./$(TREE)$(OUTPUT)$(EXT)

clean:
	rm -fr Debug/*