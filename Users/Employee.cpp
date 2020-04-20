/*
 * Employee.cpp
 *
 *  Created on: 13 abr. 2020
 *      Author: amaia
 */

#include "Employee.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace users;

/*CONSTRUCTORES Y DESTRUCTOR*/
Employee::Employee() {
	this->nss = new char[1];
	this->nss[0] = '\0';
	this->name = new char[1];
	this->name[0] = '\0';
	this->salary = 0;
	this->state = new char[1];
	this->state[0] = '\0';
}
Employee::Employee(char *nss, char *name, int salary, char *state) {

	this->nss = new char[strlen(nss) + 1];
	strcpy(this->nss, nss);
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->salary = salary;
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, state);
}
Employee::~Employee() {
	delete[] nss;
	delete[] name;
	delete[] state;
}

/*GET Y SET*/
char* Employee::getNss() {
	return this->nss;
}
char* Employee::getName() {
	return this->name;
}
int Employee::getSalary() {
	return this->salary;
}
char* Employee::getState() {
	return this->state;
}
void Employee::setNss(char *nss) {
	delete[] nss;
	this->nss = new char[strlen(nss) + 1];
	strcpy(this->nss, nss);
}
void Employee::setName(char *name) {
	delete[] name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Employee::setSalary(int salary) {
	this->salary = salary;
}
void Employee::setState(char *state) {
	delete[] state;
	this->state = new char[strlen(state) + 1];
	strcpy(this->state, state);
}
