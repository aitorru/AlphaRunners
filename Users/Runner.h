/*
 * Runner.h
 *
 *  Created on: 8 abr. 2020
 *      Author: amaia
 */

#ifndef USERS_RUNNER_H_
#define USERS_RUNNER_H_

namespace users {
class Runner {
protected:
	char dni[10];
	char name[20];
	char tlfn[9];
	char email[30];
	char birthdate[11];
	char password[10];
public:
	/* CONSTRUCTORES Y DESTRUCTOR*/
	Runner();
	Runner(char dni[10], char name[20], char tlfn[9], char email[30],
			char birthdate[11], char password[10]);
	~Runner();
	/*GET Y SET*/
	char* getDni();
	char* getName();
	char* getTlfn();
	char* getEmail();
	char* getBirthdate();
	char* getPassword();
	void setDni(char dni[10]);
	void setName(char name[20]);
	void setTlfn(char tlfn[9]);
	void setEmail(char email[30]);
	void setBirthdate(char birthdate[11]);
	void setPassword(char password[10]);
	/*RESTO DE MÉTODOS*/
	void runnerRegister();
	void modifyRunner();
	void apuntarteACarrera();
	void desapuntarteDeCarrera();
};

class Participant: public Runner {
public:
	int number, position;
	char time[9];
private:
	/*CONSTRUCTORES Y DESTRUCTOR*/
	Participant();
	Participant(char dni[10], char name[20], char tlfn[9], char email[30],
			char birthdate[11], char password[10], int number, int position,
			char time[9]);
	~Participant();
	/*GET Y SET*/
	int getNumber();
	int getPosition();
	char* getTime();
	void setNumber(int number);
	void setPosition(int position);
	void setTime(char time[9]);
};
}

#endif /* USERS_RUNNER_H_ */
