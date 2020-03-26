#ifndef _RUNNER_H_
#define _RUNNER_H_

typedef struct
{
    char dni[10];
    char name[20];
    char tlfn[9];
    char email[30];
    char birthdate[11];
    char password[10];
    int number, position;
    float time;
} Runner;

void runnerRegister (void);
void modifyRunner(char dni[10]);

#endif