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
	this->workers = new Employee[nW];
	this->nP = 0;
	this->participants = new Participant[nP];
}
Race::Race(const Race & r)
{
	this->id = r.id;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->date = new char[strlen(r.date) + 1];
	strcpy(this->date, r.date);
	this->time = new char[strlen(r.time) + 1];
	strcpy(this->time, r.time);
	this->location = new char[strlen(r.location) + 1];
	strcpy(this->location, r.location);
	this->km = r.km;
	this->organizer = r.organizer;
	this->nW = r.nW;
	this->workers = new Employee[nW];
	for(int i = 0; i < r.nW; i++)
	{
		this->workers[i] = r.workers[i];
	}
	this->nP = r.nP;
	this->participants = new Participant[nP];
	for(int i = 0; i < r.nW; i++)
	{
		this->participants[i] = r.participants[i];
	}
}
Race::Race(int id, char* name, char* date, char* time, char* location,
		int km, Employee organizer, int nW, Employee *workers, int nP,
		Participant *participants)
{
	this->id = id;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->date = new char[strlen(date) + 1];
	strcpy(this->date, date);
	this->time = new char[strlen(time) + 1];
	strcpy(this->time, time);
	this->location = new char[strlen(location) + 1];
	strcpy(this->location, location);
	this->km = km;
	this->organizer = organizer;
	this->nW = nW;
	this->workers = new Employee[nW];
	for(int i = 0; i < nW; i++)
	{
		this->workers[i] = workers[i];
	}
	this->nP = nP;
	this->participants = new Participant[nP];
	for(int i = 0; i < nW; i++)
	{
		this->participants[i] = participants[i];
	}
}
Race::~Race()
{
	delete[] name;
	delete[] date;
	delete[] time;
	delete[] location;
	delete[] workers;
	delete[] participants;
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
	this->id = id;
}
void Race::setName(char *name)
{
	this->name = new char[strlen(name)+ 1];
	strcpy(this->name, name);
}
void Race::setDate(char *date)
{
	this->date = new char[strlen(date)+ 1];
	strcpy(this->date, date);
}
void Race::setTime(char *time)
{
	this->time = new char[strlen(time)+ 1];
	strcpy(this->time, time);
}
void Race::setLocation(char *location)
{
	this->location = new char[strlen(location)+ 1];
	strcpy(this->location, location);
}
void Race::setKm(int km)
{
	this->km = km;
}
void Race::setOrganizer(Employee organizer)
{
	this->organizer = organizer;
}
void Race::setNW(int nW)
{
	this->nW = nW;
}
void Race::setWorkers(int nW, Employee *workers)
{
	this->workers = new Employee[nW];
	for(int i = 0; i < nW; i++)
	{
		this->workers[i] = workers[i];
	}
}
void Race::setNP(int nP)
{
	this->nP = nP;
}
void Race::setParticipants(int nP, Participant *participants)
{
	this->participants = new Participant[nP];
	for(int i = 0; i < nW; i++)
	{
		this->participants[i] = participants[i];
	}
}