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
	strcpy(this->dni, "");
	strcpy(this->name, "");
	strcpy(this->tlfn, "");
	strcpy(this->email, "");
	strcpy(this->birthdate, "");
	strcpy(this->password, "");
}
Runner::Runner(char dni[10], char name[20], char tlfn[9], char email[30],
		char birthdate[11], char password[10]) {
	this->dni = dni;
	this->name = name;
	this->tlfn = tlfn;
	this->email = email;
	this->birthdate = birthdate;
	this->password = password;
}
Runner::~Runner() {
	/*Nada que hacer*/
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
void Runner::setDni(char dni[10]) {
	this->dni = dni;
}
void Runner::setName(char name[20]) {
	this->name = name;
}
void Runner::setTlfn(char tlfn[9]) {
	this->tlfn = tlfn;
}
void Runner::setEmail(char email[30]) {
	this->email = email;
}
void Runner::setBirthdate(char birthdate[11]) {
	this->birthdate = birthdate;
}
void Runner::setPassword(char password[10]) {
	this->password = password;
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
	this->dni = "";
	this->name = "";
	this->tlfn = "";
	this->email = "";
	this->birthdate = "";
	this->password = "";
	this->number = 0;
	this->position = 0;
	this->time = "";
}
Participant::Participant(char dni[10], char name[20], char tlfn[9],
		char email[30], char birthdate[11], char password[10], int number,
		int position, char time[9]) {
	this->dni = dni;
	this->name = name;
	this->tlfn = tlfn;
	this->email = email;
	this->birthdate = birthdate;
	this->password = password;
	this->number = number;
	this->position = position;
	this->time = time;
}
Participant::~Participant() {
	/*Nada que hacer*/
}
/*GET Y SET*/
void Participant::setNumber(int number) {
	this->number = number;
}
void Participant::setPosition(int position) {
	this->position = position;
}
void Participant::setTime(char time[9]) {
	this->time = time;
}
