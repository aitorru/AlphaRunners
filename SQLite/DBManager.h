/*
 * DBManager.h
 *
 *  Created on: 1 may. 2020
 *      Author: amaia
 */

#ifndef DBMANAGER_H_
#define DBMANAGER_H_
#include "../Users/Runner.h"
#include "../Users/Employee.h"
#include <vector>
#include "sqlite3.h"
using namespace users;

//TABLA RUNNER
int insertNewRunner(Runner r);
int updateRunner(int pos, char *dato, char *DNI);
int getPassword(char* dni, char* password);
//TABLA EMPLOYEE
int insertNewEmployee(Employee e);
int foundEmployee(char* nss);
//TABLA RACE
int showAllRaces();
int showRace(sqlite3 *db, int idRace);
//TABLA PARTICIPANT
int joinRace(char* dni, int id, int number);
int showJoinedRaces(char* dni);
int deleteParticipant(char* dni, int idRace);
int selectTiempos(char *dni, vector<string> *tiempos);
//TABLA TASK
int showTask(char* nss);
int showTask(sqlite3 *db, char* nss);
// UTILS

#endif /* DBMANAGER_H_ */
