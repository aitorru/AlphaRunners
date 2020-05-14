/*
 * Employee.h
 *
 *  Created on: 13 abr. 2020
 *      Author: amaia
 */

#ifndef USERS_EMPLOYEE_H_
#define USERS_EMPLOYEE_H_

namespace users {
class Employee {
protected:
	char *nss;
	char *name;
	int salary;
	char *state;
public:
	/*CONSTRUCTORES Y DESTRUCTOR*/
	Employee();
	Employee(const Employee & e);
	Employee(char *nss, char *name, int salary, char *state);
	~Employee();
	/*GET Y SET*/
	char* getNss();
	char* getName();
	int getSalary();
	char* getState();
	void setNss(char* nss);
	void setName(char *name);
	void setSalary(int salary);
	void setState(char *state);
	/*RESTO DE MÉTODOS*/
	void getInformation();
	void modifyEmployee(char* nss);
};
}

#endif /* USERS_EMPLOYEE_H_ */
