/*
 * Participant.h
 *
 *  Created on: 27 abr. 2020
 *      Author: amaia
 */

#ifndef USERS_PARTICIPANT_H_
#define USERS_PARTICIPANT_H_

namespace users
{
class Participant : public Runner
{
private:
	int number, position;
	char *time;
public:
	/*CONSTRUCTORES Y DESTRUCTOR*/
	Participant();
	Participant(const Participant & p);
	Participant(char *dni, char *name, char *tlfn, char *email, char *birthdate,
				char *password);
	Participant(char *dni, char *name, char *tlfn, char *email, char *birthdate,
			char *password, int number, int position, char *time);
	virtual ~Participant();
	/*GET Y SET*/
	int getNumber();
	int getPosition();
	char* getTime();
	void setNumber(int number);
	void setPosition(int position);
	void setTime(char *time);
};
}

#endif /* USERS_PARTICIPANT_H_ */
