/*
 * Participant.cpp
 *
 *  Created on: 27 abr. 2020
 *      Author: amaia
 */
#include "Runner.h"
#include "Participant.h"
using namespace users;
#include <string.h>

//CLASE PARTICIPANT
/*CONSTRUCTORES Y DESTRUCTOR*/
Participant::Participant() :
		Runner() {
	this->number = 0;
	this->position = 0;
	this->time = new char[1];
	this->time[0] = '\0';
}
Participant::Participant(const Participant & p) : Runner(p)
{
	this->number = p.number;
	this->position = p.position;
	this->time = new char[strlen(p.time) + 1];
	strcpy(this->time, p.time);
}
Participant::Participant(char *dni, char *name, char *tlfn, char *email,
		char *birthdate, char *password) :
		Runner(dni, name, tlfn, email, birthdate, password) {
	this->number = 0;
	this->position = 0;
	this->time = new char[1];
	this->time[0] = '\0';
}
Participant::Participant(char *dni, char *name, char *tlfn, char *email,
		char *birthdate, char *password, int number, int position, char *time) :
		Runner(dni, name, tlfn, email, birthdate, password) {
	this->number = number;
	this->position = position;
	this->time = new char[strlen(time) + 1];
	strcpy(this->time, time);
}
Participant::~Participant() {
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
