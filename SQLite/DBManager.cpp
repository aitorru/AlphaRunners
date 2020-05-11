/*
 * DBManager.cpp
 *
 *  Created on: 1 may. 2020
 *      Author: amaia
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "../Users/Runner.h"
#include "../Users/Participant.h"
#include "../Users/Employee.h"
using namespace users;
#include "../Race/race.h"
using namespace race;
#include "sqlite3.h"

#include "DBManager.h"
const char* dir = "AlphaRunners.db3";

int nRunner = 4;

int openDB(sqlite3 *db){
	int result = sqlite3_open("AlphaRunners.db3", &db);
	if (result != SQLITE_OK) {
		printf("Error opening database\n");
		return result;
	}

	cout << "Database opened" << endl;
	sqlite3_close(db);
	return SQLITE_OK;
}
int closeDB(sqlite3 *db){
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		cout << "Error opening database" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	cout << "Database closed" << endl ;

	return SQLITE_OK;
}
int insertNewRunner(sqlite3* dbd, Runner r){
	sqlite3* db;
	int result = sqlite3_open(dir, &db);
	
	sqlite3_stmt *stmt;

	const char sql[] = "insert into Runner (idRunner, DNI, Name, Telephone, email, Birthdate, Password) values ( NULL, ?, ?, ?, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	cout << "SQL query prepared (INSERT)" << endl;

	result = sqlite3_bind_text(stmt, 1, r.getDni(), strlen(r.getDni()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, r.getName(), strlen(r.getName()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, r.getTlfn(), strlen(r.getTlfn()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, r.getEmail(), strlen(r.getEmail()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 5" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, r.getBirthdate(), strlen(r.getBirthdate()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 6" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, r.getPassword(), strlen(r.getPassword()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 7" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error inserting new data into Runner table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (INSERT)" << endl;
	sqlite3_close(db);
	return SQLITE_OK;
}
int getPassword(sqlite3 *dbd, char* dni, char* password)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);

	sqlite3_stmt *stmt;

	const char sql[] = "select Password from Runner where DNI = ?;";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	cout << "SQL query prepared (SELECT)" << endl;

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return result;
	}

	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW) {
		strcpy(password, (char *) sqlite3_column_text(stmt, 0));
	}else{
		cout << "Error selecting new data from Runner table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (SELECT)" << endl;
	sqlite3_close(db);
	return SQLITE_OK;
}
int insertNewEmployee(sqlite3 *dbd, Employee e)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);

	sqlite3_stmt *stmt;

	const char sql[] =
			"insert into Employee (idEmployee, NSS, Name, Salary, State) values ( NULL, ?, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	cout << "SQL query prepared (INSERT)" << endl;

	result = sqlite3_bind_text(stmt, 1, e.getNss(), strlen(e.getNss()),
			SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 2, e.getName(), strlen(e.getName()),
			SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 3, ""+e.getSalary(), sizeof(e.getSalary()),
			SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 4, e.getState(), strlen(e.getState()),
			SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 5" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error inserting new data into Employee table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (INSERT)" << endl;
	sqlite3_close(db);
	return SQLITE_OK;
}
