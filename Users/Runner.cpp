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
using namespace users;

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
void Runner::setDni(char *dni) {
	delete[] this->dni;
	this->dni = new char[strlen(dni) + 1];
	strcpy(this->dni, dni);
}
void Runner::setName(char *name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Runner::setTlfn(char *tlfn) {
	delete[] this->tlfn;
	this->tlfn = new char[strlen(tlfn) + 1];
	strcpy(this->tlfn, tlfn);
}
void Runner::setEmail(char *email) {
	delete[] this->email;
	this->email = new char[strlen(email) + 1];
	strcpy(this->email, email);
}
void Runner::setBirthdate(char *birthdate) {
	delete[] this->birthdate;
	this->birthdate = new char[strlen(birthdate) + 1];
	strcpy(this->birthdate, birthdate);
}
void Runner::setPassword(char *password) {
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

/*RESTO DE MÉTODOS*/
void runnerRegister() {
	//TODO
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

//CLASE PARTICIPANT
/*CONSTRUCTORES Y DESTRUCTOR*/
Participant::Participant() {
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
	this->number = 0;
	this->position = 0;
	this->time = new char[1];
	this->time[0] = '\0';
}
Participant::Participant(char *dni, char *name, char *tlfn, char *email, char *birthdate,
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
	this->number = 0;
	this->position = 0;
	this->time = new char[1];
	this->time[0] = '\0';
}
Participant::Participant(char *dni, char *name, char *tlfn, char *email,
		char *birthdate, char *password, int number, int position, char *time) {
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
	this->number = number;
	this->position = position;
	this->time = new char[strlen(time) + 1];
	strcpy(this->time, time);
}
Participant::~Participant() {
	delete[] dni;
	delete[] name;
	delete[] tlfn;
	delete[] email;
	delete[] birthdate;
	delete[] password;
	delete[] time;
}
/*GET Y SET*/
void Participant::setNumber(int number) {
	this->number = number;
}
void Participant::setPosition(int position) {
	this->position = position;
}
void Participant::setTime(char *time) {
	delete[] this->time;
	this->time = new char[strlen(time) + 1];
	strcpy(this->time, time);
}
