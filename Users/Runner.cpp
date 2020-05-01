/*
 * Runner.cpp
 *
 *  Created on: 8 abr. 2020
 *      Author: amaia
 */

#include "Runner.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <limits>
using namespace users;
using namespace std;

//CLASE RUNNER
/*CONSTRUCTORES Y DESTRUCTORES*/
Runner::Runner() {
	this->dni = new char[1];
	this->dni[0] = '\0';
	this->name = new char[1];
	this->name[0] = '\0';
	this->tlfn = new char[1];
	this->tlfn[0] = '\0';
	this->email = new char[1];
	this->email[0] = '\0';
	this->birthdate = new char[1];
	this->birthdate[0] = '\0';
	this->password = new char[1];
	this->password[0] = '\0';
}
Runner::Runner(const Runner &r) {
	this->dni = new char[strlen(r.dni) + 1];
	strcpy(this->dni, r.dni);
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->tlfn = new char[strlen(r.tlfn) + 1];
	strcpy(this->tlfn, r.tlfn);
	this->email = new char[strlen(r.email) + 1];
	strcpy(this->email, r.email);
	this->birthdate = new char[strlen(r.birthdate) + 1];
	strcpy(this->birthdate, r.birthdate);
	this->password = new char[strlen(r.password) + 1];
	strcpy(this->password, r.password);
}
Runner::Runner(char *dni, char *name, char *tlfn, char *email, char *birthdate,
		char *password) {
	this->dni = new char[strlen(dni) + 1];
	strcpy(this->dni, dni);
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->tlfn = new char[strlen(tlfn) + 1];
	strcpy(this->tlfn, tlfn);
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
	this->birthdate = new char[strlen(birthdate) + 1];
	strcpy(this->birthdate, birthdate);
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}
Runner::~Runner() {
	delete[] dni;
	delete[] name;
	delete[] tlfn;
	delete[] email;
	delete[] birthdate;
	delete[] password;
}

/*GET Y SET*/
char* Runner::getDni() {
	return this->dni;
}
char* Runner::getName() {
	return this->name;
}
char* Runner::getTlfn() {
	return this->tlfn;
}
char* Runner::getEmail() {
	return this->email;
}
char* Runner::getBirthdate() {
	return this->birthdate;
}
char* Runner::getPassword() {
	return this->password;
}
void Runner::setDni(const char *dni) {
	delete[] this->dni;
	this->dni = new char[strlen(dni) + 1];
	strcpy(this->dni, dni);
}
void Runner::setName(const char *name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Runner::setTlfn(const char *tlfn) {
	delete[] this->tlfn;
	this->tlfn = new char[strlen(tlfn) + 1];
	strcpy(this->tlfn, tlfn);
}
void Runner::setEmail(const char *email) {
	delete[] this->email;
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}
void Runner::setBirthdate(const char* birthdate) {
	delete[] this->birthdate;
	this->birthdate = new char[strlen(birthdate) + 1];
	strcpy(this->birthdate, birthdate);
}
void Runner::setPassword(const char* password) {
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

/*RESTO DE M�TODOS*/
void Runner::getInformation() {
	string str;

	cout << "Introduzca el DNI: " << endl;
	getline(cin, str);
	this->dni = new char[strlen(str.c_str())+1];
	strcpy(this->dni, str.c_str());
	cout << "Introduzca nombre y apellidos: " << endl;
	getline(cin, str);
	this->name = new char[strlen(str.c_str())+1];
	strcpy(this->name, str.c_str());
	cout << "Introduzca el n�mero de tel�fono: " << endl;
	getline(cin, str);
	this->tlfn = new char[strlen(str.c_str())+1];
	strcpy(this->tlfn, str.c_str());
	cout << "Introduzca el email: " << endl;
	getline(cin, str);
	this->email = new char[strlen(str.c_str())+1];
	strcpy(this->email, str.c_str());
	cout << "Introduzca el fecha de nacimiento (AAAA/MM/DD): " << endl;
	getline(cin, str);
	this->birthdate = new char[strlen(str.c_str())+1];
	strcpy(this->birthdate, str.c_str());
	cout << "Introduzca una contrase�a: " << endl;
	getline(cin, str);
	this->password = new char[strlen(str.c_str())+1];
	strcpy(this->password, str.c_str());
}

void modifyRunner() {
	//TODO
}
void apuntarteACarrera() {
	//TODO
}
void desapuntarteDeCarrera() {
	//TODO
}
