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
    Employee* workers;
    Runner* participants;
} Race;

void createRace(void);
void modifyRace(int id);
void deleteRace(int id);

#endif