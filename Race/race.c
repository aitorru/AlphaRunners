#include "../Employee/Employee.h"
#include "../Runner/Runner.h"
#include "race.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createRace(void)
{
    FILE* f;
    char str[50];
    int num = 0;
    char back;
    char nss[12];
    char dni[10];
    int id;
    char name[20];
    char date[11];
    char time[6];
    char location[20];
    int km;
    Employee organizer;
    int nW;
    Employee* employees1;
    Employee* workers;
    int nP;
    Runner* runners;
    Runner *participants;
    Race* races1;
    Race* races2;

    printf("\nCREACION DE CARRERA\n");
    printf("--------------------\n");
    printf("Identificativo de la carrera: \n");
    fflush(stdout);
    scanf("%i", id);
    printf("Nombre de la carrera: \n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(name, str);
    printf("Fecha:\n");
    fflush(stdout);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(date, str);
    printf("Hora:\n");
    fflush(stdout);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(time, str);
    printf("Lugar:\n");
    fflush(stdout);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(location, str);
    printf("Duración en kilometros: \n");
    fflush(stdout);
    scanf("%i", &km);
    printf("Introduzca el nss del trabajador organizador de la carrera: \n");
    fflush(stdout);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(nss, str);

    if((f = fopen("employees.dat", "rb")) != NULL){
        num = fgetc(f);
        employees1 = (Employee*) malloc(num* sizeof(Employee));
        fread(employees1, sizeof(Employee), num, f);
        fclose(f);
    }else
    {
        num = 0;
    }

    for(int i = 0; i<num; i++)
    {
        if(strcmp(employees1[i].nss, nss) != 0)
        {
            organizer = employees1[i];
        }
    }

    printf("Introduzca el numero de trabajadores que se asignarán a esta carrera: \n");
    fflush(stdout);
    scanf("%i", nW);
    workers = (Employee*) malloc(sizeof(Employee)*nW);
    for(int i = 0; i < nW; i++)
    {
        printf("Introduzca el nss del trabajador organizador de la carrera: \n");
        fflush(stdout);
        fgets(str, 50, stdin);
        strtok(str, "\n");
        strcpy(nss, str);
        for(int i = 0; i<num; i++)
        {
            if(strcmp(employees1[i].nss, nss) != 0)
            {
                workers[i] = employees1[i];
            }
        }
    }
    free(employees1);

    if((f = fopen("runners.dat", "rb")) != NULL){
        num = fgetc(f);
        runners = (Runner*) malloc(num* sizeof(Runner));
        fread(runners, sizeof(Runner), num, f);
        fclose(f);
    }else
    {
        num = 0;
    }
    printf("Introduzca el numero máximo de participantes: \n");
    fflush(stdout);
    scanf("%i", nP);
    participants = (Runner*) malloc(sizeof(Runner)*nP);
    for(int i = 0; i < nP; i++)
    {
        printf("Introduzca el dni del participante: \n");
        fflush(stdout);
        fgets(str, 50, stdin);
        strtok(str, "\n");
        strcpy(dni, str);
        for(int i = 0; i<num; i++)
        {
            if(strcmp(runners[i].dni, dni) != 0)
            {
                participants[i] = runners[i];
            }
        }
        printf("Desea introducir otro participante? (S/N)\n");
        fflush(stdout);
        scanf("%c", back);
        if(back == 'S' || back == 's') break;
    }

    if((f = fopen("races.dat", "rb")) != NULL){
        num = fgetc(f);
        races1 = (Race*) malloc(num* sizeof(Race));
        fread(races1, sizeof(Race), num, f);
        fclose(f);
    }else{
        num = 0;
    }

    f = fopen("races.dat", "wb");
    fputc(num+1, f);
    races2 = (Race*) malloc((num+1)* sizeof(Race));
    for(int i = 0; i < num+1; i++)
    {
        if(i != num){
            races2[i].id = races1[i].id;
            strcpy(races2[i].name, races1[i].name);
            strcpy(races2[i].date, races1[i].date);
            strcpy(races2[i].time, races1[i].time);
            strcpy(races2[i].location, races1[i].location);
            races2[i].km = races1[i].km;
            races2[i].organizer = races1[i].organizer;
            races2[i].workers = races1[i].workers;
            races2[i].participants = races1[i].participants;
        }else{
            races2[i].id = id;
            strcpy(races2[i].name, name);
            strcpy(races2[i].date, date);
            strcpy(races2[i].time, time);
            strcpy(races2[i].location, location);
            races2[i].km = km;
            races2[i].organizer = organizer;
            races2[i].workers = workers;
            races2[i].participants = participants;
        }                
    }   
    fwrite(races2, sizeof(Race), num+1, f);
    fclose(f);
    free(races1);
    free(races2);
}

void modifyRace(int id)
{
    char option;
    char* str = "";
    char name[20];
    char date[11];
    char time[6];
    char location[20];
    int km;
    Employee organizer;
    Employee* employees;
    Employee* workers;
    Runner* participants;
    Runner* runners;

    char nss[12];
    char dni[10];
    int nW;
    int nP;
    int num = 0;
    int r = -1;
    char back;

    FILE* f;
    Race* races;
    if((f = fopen("races.dat", "rb"))!=NULL)
    {
        num = fgetc(f);
        races = (Race*) malloc(num* sizeof(Race));
        fread(races, sizeof(Race), num, f);
    }

    for(int i = 0; i < num; i++)
    {
        if(races[i].id == id)
        {
            r = i;
            break;
        }
    }
    if(r != -1)
    {
        do{
            printf("\nMODIFICACION DE DATOS DE CARRERA\n");
            printf("---------------------------------\n");
            printf("1.- Cambiar id.\n");
            printf("2.- Cambiar el nombre.\n");
            printf("3.- Cambiar la fecha.\n");
            printf("4.- Cambiar la hora.\n");
            printf("5.- Cambiar la localización.\n");
            printf("6.- Cambiar la duración en kilometros.\n");
            printf("7.- Cambiar el organizador.\n");
            printf("8.- Cambiar los trabajadores.\n");
            printf("9.- Cambiar los corredores.\n");
            printf("0.- Atrás.");

            fflush(stdout);
            scanf("%c", &option);

            switch(option){
                case '1':
                    printf("Introduzca el id nuevo: \n");
                    fflush(stdout);
                    scanf("%i", id);
                    races[r].id = id;
                    break;
                case '2':
                    printf("Introduzca el nombre nuevo: \n");
                    fflush(stdout);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(name, str);
                    strcpy(races[r].name, name);
                    break;
                case '3':
                    printf("Introduzca la nueva fecha: \n");
                    fflush(stdout);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(date, str);
                    strcpy(races[r].date, date);
                    break;
                case '4':
                    printf("Introduzca la nueva hora: \n");
                    fflush(stdout);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(time, str);
                    strcpy(races[r].time, time);
                    break;
                case '5':
                    printf("Introduzca la nueva localización: \n");
                    fflush(stdout);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(location, str);
                    strcpy(races[r].location, location);
                    break;
                case '6':
                    printf("Introduzca la nueva duración en kilometros: \n");
                    fflush(stdout);
                    scanf("%i", &km);
                    races[r].km = km;
                    break;
                case '7':
                    printf("Introduzca el nss del nuevo trabajador organizador de la carrera: \n");
                    fflush(stdout);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(nss, str);

                    if((f = fopen("employees.dat", "rb")) != NULL){
                        num = fgetc(f);
                        employees = (Employee*) malloc(num* sizeof(Employee));
                        fread(employees, sizeof(Employee), num, f);
                        fclose(f);
                    }

                    for(int i = 0; i<num; i++)
                    {
                        if(strcmp(employees[i].nss, nss) != 0)
                        {
                            organizer = employees[i];
                        }
                    }
                    free(employees);
                    races[r].organizer = organizer;
                    break;
                case '8':
                    printf("Introduzca el numero de trabajadores que se asignarán a esta carrera: \n");
                    fflush(stdout);
                    scanf("%i", nW);
                    workers = (Employee*) malloc(sizeof(Employee)*nW);
                    for(int i = 0; i < nW; i++)
                    {
                        printf("Introduzca el nss del trabajador organizador de la carrera: \n");
                        fflush(stdout);
                        fgets(str, 50, stdin);
                        strtok(str, "\n");
                        strcpy(nss, str);
                        for(int i = 0; i<num; i++)
                        {
                            if(strcmp(employees[i].nss, nss) != 0)
                            {
                                workers[i] = employees[i];
                            }
                        }
                    }
                    free(employees);
                    races[r].workers = workers;
                    free(workers);
                    break;
                case '9':
                    printf("Introduzca el numero máximo de participantes: \n");
                    fflush(stdout);
                    scanf("%i", nP);
                    participants = (Runner*) malloc(sizeof(Runner)*nP);
                    for(int i = 0; i < nP; i++)
                    {
                        printf("Introduzca el dni del participante: \n");
                        fflush(stdout);
                        fgets(str, 50, stdin);
                        strtok(str, "\n");
                        strcpy(dni, str);
                        for(int i = 0; i<num; i++)
                        {
                            if(strcmp(runners[i].dni, dni) != 0)
                            {
                                participants[i] = runners[i];
                            }
                        }
                        printf("Desea introducir otro participante? (S/N)\n");
                        fflush(stdout);
                        scanf("%c", back);
                        if(back == 'S' || back == 's') break;
                    }
                    races[r].participants = participants;
                    free(participants);
                    break;
                case '0':
                    break;
                default:
                    printf("ERROR. La opcion elegida no es correcta.\n");
            }
        }while(option != '0');
        
        fclose(f);
        f = fopen("races.dat", "wb");
        fputc(num, f);
        fwrite(races, sizeof(Race), num, f);
        fclose(f);
        free(races);
    }
}