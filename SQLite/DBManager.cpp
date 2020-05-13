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

/*
 * TABLA RUNNER
 */
int insertNewRunner(Runner r){
	sqlite3* db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	
	sqlite3_stmt *stmt;

	const char sql[] = "insert into Runner (idRunner, DNI, Name, Telephone, email, Birthdate, Password) values ( NULL, ?, ?, ?, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}


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


	sqlite3_close(db);
	return SQLITE_OK;
}
int getPassword(char* dni, char* password)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] = "select Password from Runner where DNI = ?;";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}


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


	sqlite3_close(db);
	return SQLITE_OK;
}

/*
 * TABLA EMPLOYEE
 */
int insertNewEmployee(Employee e)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] =
			"insert into Employee (idEmployee, NSS, Name, Salary, State) values ( NULL, ?, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}


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
	result = sqlite3_bind_int(stmt, 3, e.getSalary());
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


	sqlite3_close(db);
	return SQLITE_OK;
}
int foundEmployee(char* nss)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select * from Employee where NSS = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}



	bool found = true;
	result = sqlite3_step(stmt);
	if (result != SQLITE_ROW) {
		found = false;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	sqlite3_close (db);

	if(!found){
		return SQLITE_ERROR;
	}
	return SQLITE_OK;
}

/*
 * TABLA RACE
 */
int showAllRaces()
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select idRace, name, date, location, km from Race";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}



	int idRace;
	char name[100];
	char date[100];
	char location[100];
	int km;

	printf("Lista de carreras\n");
	printf("-----------------\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			idRace = sqlite3_column_int(stmt, 0);
			strcpy(name, (char *) sqlite3_column_text(stmt, 1));
			strcpy(date, (char *) sqlite3_column_text(stmt, 2));
			strcpy(location, (char *) sqlite3_column_text(stmt, 3));
			km = sqlite3_column_int(stmt, 4);
			printf("Carrera %d: %s(%dkm) (%s) (%s)\n", idRace, name, km, date, location);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	sqlite3_close(db);
	return SQLITE_OK;

}
int showRace(sqlite3 *db, int idRace)
{
	sqlite3_stmt *stmt;

	char sql[] = "select idRace, name, date, location, km from Race where idRace = ?";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 1, idRace);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}



	char name[100];
	char date[100];
	char location[100];
	int km;

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			strcpy(name, (char*) sqlite3_column_text(stmt, 1));
			strcpy(date, (char*) sqlite3_column_text(stmt, 2));
			strcpy(location, (char*) sqlite3_column_text(stmt, 3));
			km = sqlite3_column_int(stmt, 4);
			printf("Carrera %d: %s(%dkm) (%s) (%s)\n", idRace, name, km, date,
					location);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	sqlite3_close(db);
	return SQLITE_OK;
}

/*
 * TABLA PARTICIPANT
 */
int joinRace(char* dni, int idRace, int number)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] =
				"insert into Participant (idParticipant, DNI, Number, idRace) values ( NULL, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}


	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni),
			SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);
			return result;
	}
	result = sqlite3_bind_int(stmt, 2, number);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 2" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_int(stmt, 3, idRace);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error inserting new data into Participant table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}


	sqlite3_close(db);
	return SQLITE_OK;
}
int showJoinedRaces(char* dni)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select idRace from Participant where DNI = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	printf("Lista de carreras en las que estas apuntad@\n");
	printf("-------------------------------------------\n");
	bool found = false;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			int idRace = sqlite3_column_int(stmt, 0);
			showRace(db, idRace);
			found = true;
		}else if(!found){
			cout << "No se ha encontrado ninguna." << endl;
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	sqlite3_close(db);
	return SQLITE_OK;
}
/*
 *Update datos runner
 */
int updateRunner(int campo, char *dato, char *DNI)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if(result != SQLITE_OK){
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	switch (campo)
	{
		case 2:{
			// Edit de nombre
			const char sql[] = "UPDATE RUNNER SET NAME = ? WHERE DNI = ?";
			result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
			if (result != SQLITE_OK)
			{
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error inserting new data into table" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (INSERT)" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}


			sqlite3_close(db);
		}break;
		case 3:{
			// Edit de telefono
			const char sql[] = "UPDATE RUNNER SET TELEPHONE = ? WHERE DNI = ?";
			result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
			if (result != SQLITE_OK)
			{
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error inserting new data into table" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (INSERT)" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}


			sqlite3_close(db);
		}break;
		case 4:{
			// Edit de email
			const char sql[] = "UPDATE RUNNER SET EMAIL = ? WHERE DNI = ?";
			result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
			if (result != SQLITE_OK)
			{
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error inserting new data into table" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (INSERT)" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}


			sqlite3_close(db);
		}break;
		case 5:{
			// Edit de Birthdate
			const char sql[] = "UPDATE RUNNER SET BIRTHDATE = ? WHERE DNI = ?";
			result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
			if (result != SQLITE_OK)
			{
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error inserting new data into table" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (INSERT)" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}


			sqlite3_close(db);
		}break;
		case 6:{
			// Edit de Password
			const char sql[] = "UPDATE RUNNER SET PASSWORD = ? WHERE DNI = ?";
			result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
			if (result != SQLITE_OK)
			{
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
				SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
					return result;
			}
			result = sqlite3_step(stmt);
			if (result != SQLITE_DONE) {
				cout << "Error inserting new data into table" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			result = sqlite3_finalize(stmt);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (INSERT)" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}


			sqlite3_close(db);
		}break;
	}
	return 0;
}
int deleteParticipant(char* dni, int idRace)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if(result != SQLITE_OK){
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "delete from Participant where DNI = ? and idRace = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	result = sqlite3_bind_int(stmt, 2, idRace);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error deleting data from table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}

/*
 * TABLA TASK
 */
int showTask(char* nss)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if(result != SQLITE_OK){
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	sqlite3_stmt *stmt;

	char sql[] =
			"select idRace, name, date, location, km from Race where organizer = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	int idRace;
	char name[100];
	char date[100];
	char location[100];
	int km;
	bool found = false;

	cout << "Organizador en las carreras: " << endl;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			found = true;
			idRace = sqlite3_column_int(stmt, 0);
			strcpy(name, (char*) sqlite3_column_text(stmt, 1));
			strcpy(date, (char*) sqlite3_column_text(stmt, 2));
			strcpy(location, (char*) sqlite3_column_text(stmt, 3));
			km = sqlite3_column_int(stmt, 4);
			printf("Carrera %d: %s(%dkm) (%s) (%s)\n", idRace, name, km, date,
					location);
		}
	} while (result == SQLITE_ROW);
	if(!found){
		cout << "Ninguna." << endl;
	}

	showTask(db, nss);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int showTask(sqlite3 *db, char* nss)
{
	sqlite3_stmt *stmt;

	char sql[] =
			"select idRace from Task where NSS = ?";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}


	int idRace;
	bool found = false;
	cout << "Empleado en las carreras:" << endl;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			found = true;
			idRace = sqlite3_column_int(stmt, 0);
			showRace(db, idRace);
		}
	} while (result == SQLITE_ROW);
	if(!found){
		cout << "Ninguna." << endl;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int selectEstadisticas(char *dni)
{	
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if(result != SQLITE_OK){
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	const char sql[] = "SELECT * FROM PARTICIPANT WHERE DNI=?";
	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 2" << endl;
		cout << sqlite3_errmsg(db);
			return result;
	}
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			cout << "DATA: " << sqlite3_column_text(stmt, 0) << endl;
			cout << "DATA: " << sqlite3_column_int(stmt, 1) << endl;
			cout << "DATA: " << sqlite3_column_int(stmt, 2) << endl;
			cout << "DATA: " << sqlite3_column_text(stmt, 3) << endl;
			cout << "DATA: " << sqlite3_column_text(stmt, 4) << endl;
			cout << "DATA: " << sqlite3_column_text(stmt, 5) << endl;
		}
	} while (result == SQLITE_ROW);
	return SQLITE_OK;
}