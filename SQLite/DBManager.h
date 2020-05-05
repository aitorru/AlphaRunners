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
int createDB();
int insertTest();

#endif /* DBMANAGER_H_ */
