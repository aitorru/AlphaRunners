CXX=g++
CC=gcc

CFLAGS=
LDFLAGS= -ldl -lpthread
MAINC=main.cpp
SQLITE=SQLite/sqlite3.c
SQLITEO=SQLite/sqlite3.o
DBMANAGER=SQLite/DBManager.cpp
USERS=Users/*.cpp
RACE=Race/race.cpp
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
	CFLAGS= -ldl -lpthread
endif


build:  $(MAINC) $(SQLITE) $(DBMANAGER) $(USERS) $(RACE)
	@echo Target build: $(PLATFORM) Using ext: $(EXT)
	$(CXX) -o $(TREE)$(OUTPUT)$(EXT) $(MAINC) $(DBMANAGER) $(USERS) $(RACE) $(SQLITEO) $(CFLAGS)
	

sqlite3.o: $(SQLITE)
	$(CC) -c $(SQLITE) -o $(SQLITEO)

buildT: $(MAINC) $(EMPLOY) $(RUNNER) $(RACE)
	$(CC) -c $(SQLITE) -o $(SQLITEO)
	$(CXX) -o $(OUTPUT)$(EXT) $(MAINC) $(DBMANAGER) $(USERS) $(RACE) $(SQLITEO) $(LDFLAGS)


run: 
	./$(TREE)$(OUTPUT)$(EXT)

clean:
	rm -fr Debug/*