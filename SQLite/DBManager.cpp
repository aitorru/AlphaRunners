/*
 * DBManager.cpp
 *
 *  Created on: 1 may. 2020
 *      Author: amaia
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <limits>
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
const char *dir = "AlphaRunners.db3";

int nRunner = 4;

/*
 * TABLA RUNNER
 */
int insertNewRunner(Runner r)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] = "insert into Runner (idRunner, DNI, Name, Telephone, email, Birthdate, Password) values ( NULL, ?, ?, ?, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, r.getDni(), strlen(r.getDni()), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 2, r.getName(), strlen(r.getName()), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 3, r.getTlfn(), strlen(r.getTlfn()), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 4, r.getEmail(), strlen(r.getEmail()), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 5" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 5, r.getBirthdate(), strlen(r.getBirthdate()), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 6" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 6, r.getPassword(), strlen(r.getPassword()), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 7" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "Error inserting new data into Runner table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int updateRunner(int campo, char *dato, char *DNI)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	switch (campo)
	{
	case 2:
	{
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
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 3:
	{
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
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 4:
	{
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
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 5:
	{
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
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 6:
	{
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
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, DNI, strlen(DNI),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	}
	return 0;
}
int getPassword(char *dni, char *password)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] = "select Password from Runner where DNI = ?;";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << "Error preparing statement (SELECT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;

		return result;
	}

	result = sqlite3_step(stmt);
	if (result == SQLITE_ROW)
	{
		strcpy(password, (char *)sqlite3_column_text(stmt, 0));
	}
	else
	{
		cout << "Error selecting new data from Runner table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
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
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] =
		"insert into Employee (idEmployee, NSS, Name, Salary, State) values ( NULL, ?, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, e.getNss(), strlen(e.getNss()),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 2, e.getName(), strlen(e.getName()),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_int(stmt, 3, e.getSalary());
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 4, e.getState(), strlen(e.getState()),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 5" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "Error inserting new data into Employee table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int foundEmployee(char *nss)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select * from Employee where NSS = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	bool found = true;
	result = sqlite3_step(stmt);
	if (result != SQLITE_ROW)
	{
		found = false;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);

	if (!found)
	{
		return SQLITE_ERROR;
	}
	return SQLITE_OK;
}
int updateEmployee(int campo, char *dato, char *nss)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	switch (campo)
	{
	case 1:
	{
		// Edit de nss
		const char sql[] = "UPDATE EMPLOYEE SET NSS = ? WHERE NSS = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, nss, strlen(nss),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);

		break;
	}
	case 2:
	{
		// Edit de nombre
		const char sql2[] = "UPDATE EMPLOYEE SET NAME = ? WHERE NSS = ?";
		result = sqlite3_prepare_v2(db, sql2, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, nss, strlen(nss),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);

		break;
	}
	case 3:
	// Edit del salario
		const char sql2[] = "UPDATE EMPLOYEE SET SALARY = ? WHERE NSS = ?";
		result = sqlite3_prepare_v2(db, sql2, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_int(stmt, 1, atoi(dato));
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_text(stmt, 2, nss, strlen(nss),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
		break;
	}
	return 0;
}
int modifyState(char* nss, char* state)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql2[] = "UPDATE EMPLOYEE SET STATE = ? WHERE NSS = ?";
	result = sqlite3_prepare_v2(db, sql2, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, state, strlen(state),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	result = sqlite3_bind_text(stmt, 2, nss, strlen(nss),
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

	sqlite3_close (db);
	return SQLITE_OK;
}

/*
 * TABLA RACE
 */
int showAllRaces()
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select idRace, name, date, location, km from Race where date>date('now')";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
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
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			idRace = sqlite3_column_int(stmt, 0);
			strcpy(name, (char *)sqlite3_column_text(stmt, 1));
			strcpy(date, (char *)sqlite3_column_text(stmt, 2));
			strcpy(location, (char *)sqlite3_column_text(stmt, 3));
			km = sqlite3_column_int(stmt, 4);
			printf("Carrera %d: %s(%dkm) (%s) (%s)\n", idRace, name, km, date, location);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
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
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_int(stmt, 1, idRace);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	char name[100];
	char date[100];
	char location[100];
	int km;

	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			strcpy(name, (char *)sqlite3_column_text(stmt, 1));
			strcpy(date, (char *)sqlite3_column_text(stmt, 2));
			strcpy(location, (char *)sqlite3_column_text(stmt, 3));
			km = sqlite3_column_int(stmt, 4);
			printf("Carrera %d: %s(%dkm) (%s) (%s)\n", idRace, name, km, date,
				   location);
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int insertRace(char *name, char *date, char *time, char *location, int km, char *nss)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "INSERT INTO RACE (idRace, NAME, DATE, TIME, LOCATION, KM, ORGANIZER) VALUES (NULL, ?, ?, ?, ?, ?, ?)";

	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, name, strlen(name),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 2, date, strlen(date),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 3, time, strlen(time),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 4, location, strlen(location),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_int(stmt, 5, km);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 6, nss, strlen(nss),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 4" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "Error inserting new data into Race table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);

	return SQLITE_OK;
}
int deleteRace(int id)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "DELETE FROM RACE WHERE IDRACE=?";

	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << "Error preparing statement (DELETE)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	result = sqlite3_bind_int(stmt, 1, id);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "Error inserting new data into Race table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		cout << "Error finalizing statement (DELETE)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);

	return SQLITE_OK;
}
int updateRace(int campo, char *dato, int id)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	switch (campo)
	{
	case 2:
	{
		// Edit de nombre
		const char sql[] = "UPDATE RACE SET NAME = ? WHERE IDRACE = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_int(stmt, 2, id);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 3:
	{
		// Edit de telefono
		const char sql[] = "UPDATE RACE SET DATE = ? WHERE IDRACE = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_int(stmt, 2, id);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 4:
	{
		// Edit de time
		const char sql[] = "UPDATE RACE SET TIME = ? WHERE IDRACE = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_int(stmt, 2, id);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 5:
	{
		// Edit de localizacion
		const char sql[] = "UPDATE RACE SET LOCATION = ? WHERE IDRACE = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_int(stmt, 2, id);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	case 6:
	{
		// Edit de KM
		const char sql[] = "UPDATE RACE SET KM = ? WHERE IDRACE = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		int datoINT = atoi(dato);
		result = sqlite3_bind_int(stmt, 1, datoINT);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_int(stmt, 2, id);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	} break;
	case 7:
	{
		// Edit de organizador
		const char sql[] = "UPDATE RACE SET ORGANIZER = ? WHERE IDRACE = ?";
		result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
		if (result != SQLITE_OK)
		{
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		result = sqlite3_bind_text(stmt, 1, dato, strlen(dato),
								   SQLITE_STATIC);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 1" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_bind_int(stmt, 2, id);
		if (result != SQLITE_OK)
		{
			cout << "Error binding parameters" << endl;
			cout << "Linea 2" << endl;
			cout << sqlite3_errmsg(db);
			return result;
		}
		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE)
		{
			cout << "Error inserting new data into table" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK)
		{
			cout << "Error finalizing statement (INSERT)" << endl;
			cout << sqlite3_errmsg(db) << endl;
			return result;
		}

		sqlite3_close(db);
	}
	break;
	}
	return 0;
}

/*
 * TABLA PARTICIPANT
 */
int joinRace(char *dni, int idRace, int number)
{
	bool joined;
	isJoined(dni, idRace, joined);
	if (!joined) {
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
	}else{
		cout << "Ya estas apuntad@ a esa carrera." << endl;
	}
	return SQLITE_OK;
}
int showJoinedRaces(char *dni)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select idRace from Participant where DNI = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	printf("Lista de carreras en las que estas apuntad@\n");
	printf("-------------------------------------------\n");
	bool found = false;
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			int idRace = sqlite3_column_int(stmt, 0);
			showRace(db, idRace);
			found = true;
		}
		else if (!found)
		{
			cout << "No se ha encontrado ninguna." << endl;
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int introduceResults(int id)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	const char sql[] = "select dni from participant where idRace = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_int(stmt, 1, id);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	bool found = false;
	bool again = false;
	do {
		again = false;
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			again = true;
			char dni[100];
			strcpy(dni, (char *)sqlite3_column_text(stmt, 0));
			sqlite3_stmt *stmt2;
			const char sql2[] =
					"UPDATE PARTICIPANT SET POSITION = ?, TIME = ? WHERE idRace = ? AND DNI = ?";
			result = sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL);
			if (result != SQLITE_OK) {
				printf("Error preparing statement (SELECT)\n");
				printf("%s\n", sqlite3_errmsg(db));
				return result;
			}
			int position;
			char* time;
			string str;
			cout << "Corredor con DNI: " << dni << endl;
			cout << "Introduzca la posicion: " << endl;
			cin >> position;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			result = sqlite3_bind_int(stmt2, 1, position);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
				return result;
			}
			cout << "Introduzca el tiempo (hh:mm:ss): " << endl;
			getline(cin, str);
			time = new char[strlen(str.c_str())+1];
			strcpy(time, str.c_str());
			result = sqlite3_bind_text(stmt2, 2, time, strlen(time),
			SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
				return result;
			}
			delete time;
			result = sqlite3_bind_int(stmt2, 3, id);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 1" << endl;
				cout << sqlite3_errmsg(db);
				return result;
			}
			result = sqlite3_bind_text(stmt2, 4, dni, strlen(dni),
			SQLITE_STATIC);
			if (result != SQLITE_OK) {
				cout << "Error binding parameters" << endl;
				cout << "Linea 2" << endl;
				cout << sqlite3_errmsg(db);
				return result;
			}
			result = sqlite3_step(stmt2);
			if (result != SQLITE_DONE) {
				cout << "Error inserting new data into table" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}

			result = sqlite3_finalize(stmt2);
			if (result != SQLITE_OK) {
				cout << "Error finalizing statement (INSERT)" << endl;
				cout << sqlite3_errmsg(db) << endl;
				return result;
			}
			found = true;
		} else if (!found) {
			cout << "No se ha encontrado ninguna." << endl;
		}
	} while (again);


	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);

	return SQLITE_OK;
}
int deleteParticipant(char *dni, int idRace)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "delete from Participant where DNI = ? and idRace = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	result = sqlite3_bind_int(stmt, 2, idRace);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "Error deleting data from table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int selectTiempos(char *dni, vector<string> *tiempos)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	const char sql[] = "SELECT TIME FROM PARTICIPANT WHERE DNI=?";
	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	bool found = false;
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			if(sqlite3_column_bytes(stmt, 0) != 0){
				found = true;
				string s = string(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
				tiempos->push_back(s);
			}
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);

	if (found) {
		return SQLITE_OK;
	} else {
		return SQLITE_ERROR;
	}
}
int selectPosiciones(char *dni, vector<int> *pos)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;
	const char sql[] = "SELECT POSITION FROM PARTICIPANT WHERE DNI=?";
	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	result = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}
	bool found = false;
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			if(sqlite3_column_bytes(stmt, 0) != 0){
				found = true;
				int posTMP = sqlite3_column_int(stmt, 0);
				pos->push_back(posTMP);
			}
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);

	if(found){
		return SQLITE_OK;
	}else{
		return SQLITE_ERROR;
	}

}
int isJoined(char* dni, int idRace, bool & joined)
{
	joined = false;
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	sqlite3_stmt *stmt;

	char sql[] =
			"select * from Participant where DNI = ? and idRace = ?";

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
	result = sqlite3_bind_int(stmt, 2, idRace);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			joined = true;
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
 * TABLA TASK
 */
int showTask(char *nss)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	sqlite3_stmt *stmt;

	char sql[] =
		"select idRace, name, date, location, km from Race where organizer = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
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
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			found = true;
			idRace = sqlite3_column_int(stmt, 0);
			strcpy(name, (char *)sqlite3_column_text(stmt, 1));
			strcpy(date, (char *)sqlite3_column_text(stmt, 2));
			strcpy(location, (char *)sqlite3_column_text(stmt, 3));
			km = sqlite3_column_int(stmt, 4);
			printf("Carrera %d: %s(%dkm) (%s) (%s)\n", idRace, name, km, date,
				   location);
		}
	} while (result == SQLITE_ROW);
	if (!found)
	{
		cout << "Ninguna." << endl;
	}

	showTask(db, nss);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int showTask(sqlite3 *db, char *nss)
{
	sqlite3_stmt *stmt;

	char sql[] =
		"select idRace from Task where NSS = ?";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	int idRace;
	bool found = false;
	cout << "Empleado en las carreras:" << endl;
	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			found = true;
			idRace = sqlite3_column_int(stmt, 0);
			showRace(db, idRace);
		}
	} while (result == SQLITE_ROW);
	if (!found)
	{
		cout << "Ninguna." << endl;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int insertTask(char* nss, int idRace)
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
			"insert into Task (idTask, NSS, idRace) values ( NULL, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_int(stmt, 1, idRace);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		cout << "Error inserting new data into Notification table" << endl;
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

/*
 * TABLA NOTIFICATION
 */
int sendNotification(char *nss, char *title, char *desc)
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	const char sql[] =
		"insert into Notification (idNotification, NSS, title, description) values ( NULL, ?, ?, ?)";
	result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << "Error preparing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 1" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	result = sqlite3_bind_text(stmt, 2, title, strlen(title),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 3" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}
	result = sqlite3_bind_text(stmt, 3, desc, strlen(desc),
							   SQLITE_STATIC);
	if (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << "Linea 5" << endl;
		cout << sqlite3_errmsg(db);

		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "Error inserting new data into Notification table" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		cout << "Error finalizing statement (INSERT)" << endl;
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int checkNotifications()
{
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK)
	{
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "select NSS, title, description from Notification";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
	{
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char nss[100];
	char title[100];
	char description[100];
	bool found = false;

	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			found = true;
			strcpy(nss, (char *)sqlite3_column_text(stmt, 0));
			strcpy(title, (char *)sqlite3_column_text(stmt, 1));
			strcpy(description, (char *)sqlite3_column_text(stmt, 2));
			printf("/ %s del empleado con NSS = %s por %s. /\n", title, nss, description);
		}
	} while (result == SQLITE_ROW);

	if (!found)
	{
		cout << "/ No hay nuevas notificaciones. /" << endl;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK)
	{
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_close(db);
	return SQLITE_OK;
}
int removeNotification(char* nss, char* title)
 {
	sqlite3 *db;
	int result = sqlite3_open(dir, &db);
	if (result != SQLITE_OK) {
		printf("Error opening DB\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	sqlite3_stmt *stmt;

	char sql[] = "delete from Notification where NSS = ? and title = ?";

	result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (DELETE)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, nss, strlen(nss), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
		return result;
	}

	result = sqlite3_bind_text(stmt, 2, title, strlen(title), SQLITE_STATIC);
	if (result != SQLITE_OK) {
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db);
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
