#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits>
#include <iostream>
using namespace std;
#include "Users/Runner.h"
#include "Users/Participant.h"
#include "Users/Employee.h"
using namespace users;
#include "Race/race.h"
using namespace race;
#include "SQLite/sqlite3.h"
#include "SQLite/DBManager.h"

int main(void)
{
    sqlite3 *db;
    openDB(db);
    char *pass;
    char *DNI = "78994862M";
    getPassword(db, DNI, pass);
    //  SQLITE_BUSY, SQLITE_DONE, SQLITE_ROW, SQLITE_ERROR, or SQLITE_MISUSE
    cout << "SQLITE_BUSY: " << SQLITE_BUSY << " SQLITE_DONE: " << SQLITE_DONE << " SQLITE_ROW: " << SQLITE_ROW << " SQLITE_ERROR: " << SQLITE_ERROR << " SQLITE_MISUSE: " << SQLITE_MISUSE << endl;
    cout << "La password es: " << pass << endl;
    return 0;
}