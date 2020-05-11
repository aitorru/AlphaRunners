/*
 * Runner.h
 *
 *  Created on: 8 abr. 2020
 *      Author: amaia
 */

#include <iostream>
using namespace std;

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
	Runner(const Runner & r);
	Runner(char *dni, char *name, char *tlfn, char *email, char *birthdate,
			char *password);
	virtual ~Runner();
	/*GET Y SET*/
	char* getDni();
	char* getName();
	char* getTlfn();
	char* getEmail();
	char* getBirthdate();
	char* getPassword();
	void setDni(const char *dni);
	void setName(const char *name);
	void setTlfn(const char *tlfn);
	void setEmail(const char *email);
	void setBirthdate(const char *birthdate);
	void setPassword(const char *password);
	/*RESTO DE M�TODOS*/
	void getInformation();
	void modifyRunner(char *DNI);
	void apuntarteACarrera();
	void desapuntarteDeCarrera();

};
}

#endif /* USERS_RUNNER_H_ */
