/*
 * race.cpp
 *
 *  Created on: 20 abr. 2020
 *      Author: amaia
 */

#include "../Users/Employee.h"
#include "../Users/Runner.h"
#include "race.h"
using namespace race;
using namespace users;
#include <stdio.h>
#include <string.h>

/*CONSTRUCTORES Y DESTRUCTOR*/
Race::Race()
{
	this->id = 0;
	this->name = new char[1];
	this->name[0] = '\0';
	this->date = new char[1];
	this->date[0] = '\0';
	this->time = new char[1];
	this->time[0] = '\0';
	this->location = new char[1];
	this->location[0] = '\0';
	this->km = 0;
	Employee employee;
	this->organizer = employee;
	this->nW = 0;
	this->workers = NULL;
	this->nP = 0;
	this->participants = NULL;
}
Race::Race(int id, char* name, char* date, char* time, char* location,
		int km, Employee organizer, int nW, Employee *workers, int nP,
		Participant *participants)
{
	this->id = id;
	this->name = new char[strlen(name)];
	strcpy(this->name, name);
	this->date = new char[strlen(date)];
	strcpy(this->date, date);
	this->time = new char[strlen(time)];
	strcpy(this->time, time);
	this->location = new char[strlen(location)];
	strcpy(this->location, location);
	this->km = km;
	this->organizer = organizer;
	this->nW = nW;
	this->workers = workers;
	this->nP = nP;
	this->participants = participants;
}
Race::~Race()
{
	delete[] name;
	delete[] date;
	delete[] time;
	delete[] location;
}
/*GET Y SET*/
int Race::getId()
{
	return this->id;
}
char* Race::getName()
{
	return this->name;
}
char* Race::getDate()
{
	return this->date;
}
char* Race::getTime()
{
	return this->time;
}
char* Race::getLocation()
{
	return this->location;
}
int Race::getKm()
{
	return this->km;
}
Employee Race::getOrganizer()
{
	return this->organizer;
}
int Race::getNW()
{
	return this->nW;
}
Employee* Race::getWorkers()
{
	return this->workers;
}
int Race::getNP()
{
	return this->nP;
}
Participant* Race::getParticipants()
{
	return this->participants;
}
void Race::setId(int id)
{

}
void Race::setName(char *name)
{

}
void Race::setDate(char *date)
{

}
void Race::setTime(char *time)
{

}
void Race::setLocation(char *location)
{

}
void Race::setKm(int km)
{

}
void Race::setOrganizer(Employee organizer)
{

}
void Race::setNW(int nW)
{

}
void Race::setWorkers(Employee *workers)
{

}
void Race::setNP(int nP)
{

}
void Race::setParticipants(Participant *participants)
{

}
