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
#include <limits>
#include "../SQLite/DBManager.h"
#include <iostream>
using namespace users;
using namespace std;

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
Employee::Employee(const Employee & e)
{
	this->nss = new char[strlen(e.nss) + 1];
	strcpy(this->nss, e.nss);
	this->name = new char[strlen(e.name) + 1];
	strcpy(this->name, e.name);
	this->salary = e.salary;
	this->state = new char[strlen(e.state) + 1];
	strcpy(this->state, e.state);
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
	modifyState(this->nss, this->state);
}
void Employee::getInformation()
{
	string str;
	getline(cin, str);

	cout << "Introduzca el NSS: " << endl;
	cout.flush();
	getline(cin, str);
	this->nss = new char[strlen(str.c_str()) + 1];
	strcpy(this->nss, str.c_str());
	cout << "Introduzca nombre y apellidos: " << endl;
	getline(cin, str);
	this->name = new char[strlen(str.c_str()) + 1];
	strcpy(this->name, str.c_str());
	cout << "Introduzca el salario: " << endl;
	cin >> this->salary;
}
void Employee::modifyEmployee() {
	string str;
	char *datos;
	cout << "Que quieres modificar:" << endl;
	cout << "------------------" << endl;
	cout << "1: NSS" << endl;
	cout << "2: Nombre" << endl;
	cout << ">";
	cout.flush();
	char opcionCorredor;
	scanf("%c", &opcionCorredor);
	switch (opcionCorredor) {
	case '1':
		cout << "\nIntroduce el nss corregido: " << endl;
		cout.flush();
		cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		cin.clear();
		getline(cin, str);
		datos = new char[strlen(str.c_str()) + 1];
		strcpy(datos, str.c_str());
		cout << "Updating" << endl;
		updateEmployee(1, datos, this->nss);
		break;
	case '2':
		cout << "\nIntroduce nombre: " << endl;
		cout.flush();
		cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		cin.clear();
		getline(cin, str);
		datos = new char[strlen(str.c_str()) + 1];
		strcpy(datos, str.c_str());
		cout << "Updating" << endl;
		updateEmployee(2, datos, this->nss);
		break;
	default:
		break;
	}
}
