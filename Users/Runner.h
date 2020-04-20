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
	char *dni;
	char *name;
	char *tlfn;
	char *email;
	char *birthdate;
	char *password;
public:
	/* CONSTRUCTORES Y DESTRUCTOR*/
	Runner();
	Runner(char *dni, char *name, char *tlfn, char *email, char *birthdate,
			char *password);
	~Runner();
	/*GET Y SET*/
	char* getDni();
	char* getName();
	char* getTlfn();
	char* getEmail();
	char* getBirthdate();
	char* getPassword();
	void setDni(char *dni);
	void setName(char *name);
	void setTlfn(char *tlfn);
	void setEmail(char *email);
	void setBirthdate(char *birthdate);
	void setPassword(char *password);
	/*RESTO DE MÉTODOS*/
	void runnerRegister();
	void modifyRunner();
	void apuntarteACarrera();
	void desapuntarteDeCarrera();
};

class Participant: public Runner {
private:
	int number, position;
	char *time;
public:
	/*CONSTRUCTORES Y DESTRUCTOR*/
	Participant();
	Participant(char *dni, char *name, char *tlfn, char *email, char *birthdate,
				char *password);
	Participant(char *dni, char *name, char *tlfn, char *email, char *birthdate,
			char *password, int number, int position, char *time);
	~Participant();
	/*GET Y SET*/
	int getNumber();
	int getPosition();
	char* getTime();
	void setNumber(int number);
	void setPosition(int position);
	void setTime(char *time);
};
}

#endif /* USERS_RUNNER_H_ */
