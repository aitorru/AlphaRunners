#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

typedef struct{
    char nss[12];
    char name[20];
    int salary;
    char state[5];
} Employee;

void registerEmployee(void);
void modifyEmployee(char nss[12]);
void modifyEmployeeA(char nss[12]);

#endif
