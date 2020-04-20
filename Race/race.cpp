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
	this->organizer = NULL;
	this->nW = 0;
	this->workers = NULL;
	this->nP = 0;
	this->participants = NULL;
}
Race::Race(int id, char* name, char* date, char* time, char* location,
		int km, Employee organizer, int nW, Employee *workers, int nP,
		Participant *participants)
{

}
Race::~Race()
{

}
/*GET Y SET*/
int Race::getId()
{

}
char* Race::getName()
{

}
char* Race::getDate()
{

}
char* Race::getTime()
{

}
char* Race::getLocation()
{

}
int Race::getKm()
{

}
Employee Race::getOrganizer()
{

}
int Race::getNW()
{

}
Employee* Race::getWorkers()
{

}
int Race::getNP()
{

}
Participant* Race::getParticipants()
{

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
