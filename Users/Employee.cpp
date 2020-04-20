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
	strcpy(this->nss, "");
	strcpy(this->name, "");
	this->salary = 0;
	strcpy(this->state, "");
}
Employee::Employee(char nss[12], char name[20], int salary, char state[5]) {
	this->nss = nss;
	this->name = name;
	this->salary = salary;
	this->state = state;
}
Employee::~Employee() {
	/*Nada que hacer*/
}

/*GET Y SET*/
char* Employee::getNss()
{
	return this->nss;
}
char* Employee::getName()
{
	return this->name;
}
int Employee::getSalary()
{
	return this->salary;
}
char* Employee::getState()
{
	return this->state;
}
void Employee::setNss(char nss[12])
{
	this->nss = nss;
}
void Employee::setName(char name[20])
{
	this->name = name;
}
void Employee::setSalary(int salary)
{
	this->salary = salary;
}
void Employee::setState(char state[5])
{
	this->state = state;
}
