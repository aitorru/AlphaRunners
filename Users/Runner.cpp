/*
 * Runner.cpp
 *
 *  Created on: 8 abr. 2020
 *      Author: amaia
 */

#include "Runner.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <limits>
#include <climits>
#include <vector>
#include "../SQLite/DBManager.h"
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
	cout.flush();
	getline(cin, str);
	this->dni = new char[strlen(str.c_str())+1];
	strcpy(this->dni, str.c_str());
	cout << this->dni;
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
	cout << "Introduzca el fecha de nacimiento (DD/MM/AAAA): " << endl;
	getline(cin, str);
	this->birthdate = new char[strlen(str.c_str())+1];
	strcpy(this->birthdate, str.c_str());
	cout << this->birthdate;
	cout << "Introduzca una contrase�a: " << endl;
	getline(cin, str);
	this->password = new char[strlen(str.c_str())+1];
	strcpy(this->password, str.c_str());
}

void Runner::modifyRunner() {
	string str;
	char *datos;
	cout << "Que quieres modificar:" << endl;
	cout << "------------------" << endl;
	cout << "2: Nombre" << endl;
	cout << "3: Telefono" << endl;
	cout << "4: Email" << endl;
	cout << "5: Cumpleaños" << endl;
	cout << "6: Password" << endl;
	cout << ">";
	cout.flush();
	char opcionCorredor;
	scanf("%c", &opcionCorredor);
	switch (opcionCorredor)
		{
		case '2':
			cout << "\nIntroduce nombre: " << endl;
			cout.flush();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			getline(cin, str);
			datos =  new char[strlen(str.c_str())+1];
			strcpy(datos, str.c_str());
			cout << "Updating" << endl;
			updateRunner(2,datos,this->dni);
			break;
		
		case '3':
			cout << "\nIntroduce telefono: " << endl;
			cout.flush();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			getline(cin, str);
			datos =  new char[strlen(str.c_str())+1];
			strcpy(datos, str.c_str());
			cout << "Updating" << endl;
			updateRunner(3,datos,this->dni);
			break;

		case '4':
			cout << "\nIntroduce Email: " << endl;
			cout.flush();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			getline(cin, str);
			datos =  new char[strlen(str.c_str())+1];
			strcpy(datos, str.c_str());
			cout << "Updating" << endl;
			updateRunner(4,datos,this->dni);
			break;
		case '5':
			cout << "\nIntroduce Birthdate (DD/MM/AAAA): " << endl;
			cout.flush();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			getline(cin, str);
			datos =  new char[strlen(str.c_str())+1];
			strcpy(datos, str.c_str());
			cout << "Updating" << endl;
			updateRunner(5,datos,this->dni);

		case '6':
			cout << "\nIntroduce contraseña: " << endl;
			cout.flush();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.clear();
			getline(cin, str);
			datos =  new char[strlen(str.c_str())+1];
			strcpy(datos, str.c_str());
			cout << "Updating" << endl;
			updateRunner(6,datos,this->dni);
			break;
		default:
			break;
		}
}

void Runner::verEstadisticas()
{	
	vector<string> tiempos;
	int result = selectTiempos(this->dni, &tiempos);
	if(result == SQLITE_OK){
		cout << "me emto dentro" << endl;
		vector<int> horas;
		vector<int> minutos;
		vector<int> segundos;
		for (int i = 0; i < tiempos.size(); i++) {
			char *time = (char*) malloc(8 * sizeof(char));
			strcpy(time, tiempos.at(i).c_str());
			char horaCH[] = { time[0], time[1] };
			int horaIN = atoi(horaCH);
			horas.push_back(horaIN);
			char minutosCH[] = { time[3], time[4] };
			int minutosIN = atoi(minutosCH);
			minutos.push_back(minutosIN);
			char segundosCH[] = { time[6], time[7] };
			int segundosIN = atoi(segundosCH);
			segundos.push_back(segundosIN);
		}
		int mediaHoras = 0, mediaMinutos = 0, mediaSegundos = 0;
		for (int i = 0; i < tiempos.size(); i++) {
			mediaHoras = mediaHoras + horas.at(i);
			mediaMinutos = mediaMinutos + minutos.at(i);
			mediaSegundos = mediaSegundos + segundos.at(i);
		}
		mediaHoras = mediaHoras / tiempos.size();
		mediaMinutos = mediaMinutos / tiempos.size();
		mediaSegundos = mediaSegundos / tiempos.size();
		cout << "Tus tiempos en las carreras han sido de media: " << mediaHoras
				<< "h|" << mediaMinutos << "m|" << mediaSegundos << "s" << endl;
	}


	vector<int> pos;
	result = selectPosiciones(this->dni, &pos);
	if(result == SQLITE_OK){
		int mediaPosiciones = 0;
		for (int i = 0; i < pos.size(); i++) {
			mediaPosiciones = mediaPosiciones + pos.at(i);
		}
		mediaPosiciones = mediaPosiciones / pos.size();
		cout << "Has quedado de media en la posicion: " << mediaPosiciones << endl;
	}else{
		cout << "No se han encontrado los resultados de tus carreras." << endl;
	}

}
