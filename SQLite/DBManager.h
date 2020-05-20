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
int updateEmployee(int campo, char *dato, char *nss);
int modifyState(char* nss, char* state);
//TABLA RACE
int showAllRaces();
int incomingRaces();
int showRace(sqlite3 *db, int idRace);
int insertRace(char *name, char *date, char *time, char *location, int km, char *nss);
int deleteRace(int id);
int updateRace(int entrada, char *datos, int id);
//TABLA PARTICIPANT
int joinRace(char* dni, int id, int number);
int showJoinedRaces(char* dni);
int introduceResults(int id);
int deleteParticipant(char* dni, int idRace);
int selectTiempos(char *dni, vector<string> *tiempos);
int selectPosiciones(char *dni, vector<int> *pos);
int isJoined(char* dni, int idRace, bool & joined);
//TABLA TASK
int showTask(char* nss);
int showTask(sqlite3 *db, char* nss);
int insertTask(char* nss, int idRace);
//TABLA NOTIFICATION
int sendNotification(char* nss, char* title, char* desc);
int checkNotifications();
int removeNotification(char* nss, char* title);
// UTILS

#endif /* DBMANAGER_H_ */
