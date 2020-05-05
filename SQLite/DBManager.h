/*
 * DBManager.h
 *
 *  Created on: 1 may. 2020
 *      Author: amaia
 */

#ifndef DBMANAGER_H_
#define DBMANAGER_H_

int openDB(sqlite3 *db);
int closeDB(sqlite3 *db);
int insertNewRunner(sqlite3 *dbd, Runner r);
int getPassword(sqlite3 *dbd, char* dni, char* password);
int insertNewEmployee(sqlite3 *dbd, Employee e);

#endif /* DBMANAGER_H_ */
