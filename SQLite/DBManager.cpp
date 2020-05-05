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

int nRunner = 4;

int openDB(sqlite3 *db){
	int result = sqlite3_open("../AlphaRunners.s3db", &db);
	if (result != SQLITE_OK || db == NULL) {
		printf("Error opening database\n");
		return result;
	}

	cout << "Database opened" << endl;

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
int insertNewRunner(sqlite3* db, Runner r){
	sqlite3_stmt *stmt;

	//Poner aqui con + r.get() + ""
	const char sql[] = "insert into Runner (DNI, Name, Telephone, email, Birthdate, Password) values (?, ?, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	cout << "SQL query prepared (INSERT)" << endl;

	result = sqlite3_bind_text(stmt, 0, r.getDni(), strlen(r.getDni()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, r.getDni(), strlen(r.getDni()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, r.getName(), strlen(r.getName()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, r.getTlfn(), strlen(r.getTlfn()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, r.getEmail(), strlen(r.getEmail()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, r.getBirthdate(), strlen(r.getBirthdate()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, r.getPassword(), strlen(r.getPassword()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error inserting new data into Runner table" << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (INSERT)" << endl;

	return SQLITE_OK;
}
int insertNewEmployee(sqlite3 *db, Employee e)
{
	sqlite3_stmt *stmt;

	char sql[] = "insert into Employee (idEmployee, NSS, Name, Salary, State) values (NULL, ?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	cout << "SQL query prepared (INSERT)" << endl;

	result = sqlite3_bind_text(stmt, 1, e.getNss(), strlen(e.getNss()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, e.getName(), strlen(e.getName()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, (char*) e.getSalary(), sizeof(e.getSalary()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, e.getState(), strlen(e.getState()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error inserting new data into Employee table" << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	cout << "Prepared statement finalized (INSERT)" << endl;

	return SQLITE_OK;
}
