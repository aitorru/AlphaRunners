/*
 * Employee.h
 *
 *  Created on: 13 abr. 2020
 *      Author: amaia
 */

#ifndef USERS_EMPLOYEE_H_
#define USERS_EMPLOYEE_H_

namespace users
{
	class Employee
	{
	protected:
		char nss[12];
		char name[20];
		int salary;
		char state[5];
	public:
		/*CONSTRUCTORES Y DESTRUCTOR*/
		Employee();
		Employee(char nss[12], char name[20], int salary, char state[5]);
		~Employee();
		/*GET Y SET*/
		char* getNss();
		char* getName();
		int getSalary();
		char* getState();
		void setNss(char nss[12]);
		void setName(char name[20]);
		void setSalary(int salary);
		void setState(char state[5]);
		/*RESTO DE MÉTODOS*/
		void registerEmployee(); //???
		void modifyEmployee();	//???
		void modifyEmployeeA();	//???
	};
}

#endif /* USERS_EMPLOYEE_H_ */
