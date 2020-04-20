/*
 * Race.h
 *
 *  Created on: 19 abr. 2020
 *      Author: amaia
 */

#ifndef RACE_RACE_H_
#define RACE_RACE_H_

namespace Race {
class Race {
private:

public:
	/*CONSTRUCTORES Y DESTRUCTOR*/
	Race();
	Race(int id, char name[20], char date[11], char time[6], char location[20],
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
	void getWorkers(Employee *workers);
	void getNP(int nP);
	void getParticipants(Participant *participants);
};
}

#endif /* RACE_RACE_H_ */
