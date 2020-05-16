/*
 * Race.h
 *
 *  Created on: 19 abr. 2020
 *      Author: amaia
 */

#ifndef RACE_RACE_H_
#define RACE_RACE_H_

#include "../Users/Employee.h"
#include "../Users/Participant.h"
using namespace users;

namespace race {
class Race {
private:
	int id;
	char* name;
	char* date;
	char* time;
	char* location;
	int km;
	Employee organizer;
	int nW;
	Employee *workers;
	int nP;
	Participant *participants;
public:
	/*CONSTRUCTORES Y DESTRUCTOR*/
	Race();
	Race(const Race & r);
	Race(int id, char* name, char* date, char* time, char* location,
			int km, Employee organizer, int nW, Employee *workers, int nP,
			Participant *participants);
	~Race();
	/*GET Y SET*/
	int getId();
	char* getName();
	char* getDate();
	char* getTime();
	char* getLocation();
	int getKm();
	Employee getOrganizer();
	int getNW();
	Employee* getWorkers();
	int getNP();
	Participant* getParticipants();
	void setId(int id);
	void setName(char *name);
	void setDate(char *date);
	void setTime(char *time);
	void setLocation(char *location);
	void setKm(int km);
	void setOrganizer(Employee organizer);
	void setNW(int nW);
	void setWorkers(int nW, Employee *workers);
	void setNP(int nP);
	void setParticipants();
	void createRace();
	void modifyRace(int id);
};
}

#endif /* RACE_RACE_H_ */
