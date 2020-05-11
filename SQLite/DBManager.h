/*
 * DBManager.h
 *
 *  Created on: 1 may. 2020
 *      Author: amaia
 */

#ifndef DBMANAGER_H_
#define DBMANAGER_H_

int insertNewRunner(Runner r);
int getPassword(char* dni, char* password);
int insertNewEmployee(Employee e);
int showAllRaces();
int getRace(sqlite3 *db, int idRace);
int joinRace(char* dni, int id, int number);
int showJoinedRaces(char* dni);
int updateRunner(int pos, char *dato, char *DNI);

#endif /* DBMANAGER_H_ */
