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
int joinRace(char* dni, int id, int number);

#endif /* DBMANAGER_H_ */
