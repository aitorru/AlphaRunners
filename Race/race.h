#ifndef _RACE_H_
#define _RACE_H_

typedef struct
{
    int id;
    char name[20];
    char date[11];
    char time[6];
    char location[20];
    int km;
    Employee organizer;
    int nW;
    Employee* workers;
    int nP;
    Runner* participants;
} Race;

void createRace(void);
void modifyRace(int id);
void deleteRace(int id);
void introduceResults(int id);

#endif