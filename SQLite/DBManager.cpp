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

	const char sql[] = "insert into Runner (idRunner, DNI, Name, Telephone, email, Birthdate, Password) values (?, ?, ?, ?, ?, ?, ?)";
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
	result = sqlite3_bind_text(stmt, 2, r.getDni(), strlen(r.getDni()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 2" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 3, r.getName(), strlen(r.getName()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 4, r.getTlfn(), strlen(r.getTlfn()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 5, r.getEmail(), strlen(r.getEmail()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 5" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 6, r.getBirthdate(), strlen(r.getBirthdate()), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 6" << endl;
		cout << sqlite3_errmsg(db);
		
		return result;
	}
	result = sqlite3_bind_text(stmt, 7, r.getPassword(), strlen(r.getPassword()), SQLITE_STATIC);
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
int insertTest()
{
	/*
	sqlite3_stmt *stmt;
	const char *sql = "INSERT INTO TEST (NUM) VALUES(?)";
	cout << "SQL created" << endl;
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	cout << "SQL prepared" << endl;
	sqlite3_bind_int(stmt, 1, num);
	cout << "SQL bind" << endl;
	if(rc == SQLITE_OK)
	{
		sqlite3_step(stmt);
		sqlite3_finalize(stmt);
		return SQLITE_OK;
	}
	return SQLITE_WARNING;
	*/
	sqlite3* DB;
	string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"id	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
		"num	INTEGER NOT NULL"
		");";
	try
	{
		int exit = 0;
		char* messaggeError;
		exit = sqlite3_open("test.db", &DB);
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
		if (exit!=SQLITE_OK)
		{
			cerr << "Error insert" << endl;
			cerr << messaggeError << endl;
			sqlite3_free(messaggeError);
		}
		else
		{
			cout << "Insert realizado correctamente" << endl;
			return SQLITE_OK;
		}
		sqlite3_close(DB);
		return SQLITE_OK;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return SQLITE_OK;
}
int createDB()
{
	sqlite3* DB;
	int exit = 0;

	exit = sqlite3_open("test.db", &DB);
	sqlite3_close(DB);

	return 0;
}