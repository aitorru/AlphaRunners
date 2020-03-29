#include "Runner.h"
#include "../Employee/Employee.h"
#include "../Race/race.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void runnerRegister (void)
{
    FILE* f;
    int num;
    char str[50];
    char dni[10];
    char name[20];
    char tlfn[9];
    char email[30];
    char birthdate[11];
    char password[20];
    Runner *runners1;
    Runner *runners2;

    printf("\nREGISTRO DE CORREDOR\n");
    printf("--------------------\n");
    printf("DNI: \n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(dni, str);
    printf("Nombre y apellidos:\n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(name, str);
    printf("Número de telefono:\n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(tlfn, str);
    printf("Email:\n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(email, str);
    printf("Fecha de nacimiento (AAAA/MM/DD): \n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(birthdate, str);
    printf("Introduzca una contraseña: \n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(password, str);

    if((f = fopen("runners.dat", "rb")) != NULL){
        num = fgetc(f);
        runners1 = (Runner*) malloc(num* sizeof(Runner));
        fread(runners1, sizeof(Runner), num, f);
        fclose(f);
    }else{
        num = 0;
    }

    f = fopen("runners.dat", "wb");
    fputc(num+1, f);
    runners2 = (Runner*) malloc((num+1)* sizeof(Runner));
    for(int i = 0; i < num+1; i++)
    {
        if(i != num){
            strcpy(runners2[i].dni, runners1[i].dni);
            strcpy(runners2[i].name, runners1[i].name);
            strcpy(runners2[i].tlfn, runners1[i].tlfn);
            strcpy(runners2[i].email, runners1[i].email);
            strcpy(runners2[i].birthdate, runners1[i].birthdate);
            strcpy(runners2[i].password, runners1[i].password);
        }else{
            strcpy(runners2[i].dni, dni);
            strcpy(runners2[i].name, name);
            strcpy(runners2[i].tlfn, tlfn);
            strcpy(runners2[i].email, email);
            strcpy(runners2[i].birthdate, birthdate);
            strcpy(runners2[i].password, password);
        }                
    }   
    fwrite(runners2, sizeof(Runner), num+1, f);
    fclose(f);
    free(runners1);
    free(runners2);
}

void apuntarteACarrera(char dni[10])
{
    char option;
    char str[50];
    char newDni[10];
    char name[20];
    char tlfn[9];
    char email[30];
    char birthdate[11];
    char password[10];
    char registro;

    //Variable para guardar temporales
    int idtmp;
    

    int r = -1;

    FILE* f;
    int num = 0;
    Runner* runners;
    if((f = fopen("runners.dat", "rb"))!=NULL)
    {
        num = fgetc(f);
        runners = (Runner*) malloc(num* sizeof(Runner));
        fread(runners, sizeof(Runner), num, f);
    }

    for(int i = 0; i < num; i++)
    {
        if(strcmp(runners[i].dni, dni) == 0)
        {
            r = i;
            break;
        }
    }
    FILE* ff;
    Race* races;

    if (r != -1)
    {
        printf("\nMENU REGISTRO\n");
        printf("------------------\n");
        printf("1.- Listado de carreras.\n");
        printf("2.- Apuntarse a carrera.\n");
        printf("3.- Atrás.\n");
        fflush(stdout);
        fflush(stdin);
        scanf("%c", &registro);
        switch(registro)
        {
            case 1:
                
                if((ff = fopen("races.dat", "rb"))!=NULL)
                {
                    num = fgetc(f);
                    races = (Race*) malloc(num* sizeof(Race));
                    fread(races, sizeof(Race), num, f);
                }

                for(int i = 0; i < num; i++)
                {
                    printf("Carrera N%i: %s con ID: %i\n", i, races[i].name, races[i].id);
                    break;   
                }
                break;
            case 2:
                printf("Cual es el id de la carrera a la que te quieres apuntar:");
                fflush(stdout);
                fflush(stdin);
                scanf("%i", &idtmp);
                if((ff = fopen("races.dat", "rb"))!=NULL)
                {
                    num = fgetc(f);
                    races = (Race*) malloc(num* sizeof(Race));
                    fread(races, sizeof(Race), num, f);

                    for(int i = 0; i < num; i++)
                    {
                        if(races[i].id == idtmp);
                        {
                            races[i].participants;
                            Runner participantes[races[i].nP+1];
                            memcpy(&participantes, &races[i].participants, sizeof(Runner));
                            participantes[races[i].nP+1] = runners[r]; //Guardar el nuevo participante en la nueva posición
                            memcpy(races[i].participants, participantes, sizeof(Runner));
                            races[i].nP = races[i].nP+1;
                            printf("\nSe ha añadido correctamente.\n");
                            fflush(stdout);
                        }   
                    }
                } else
                {
                    printf("Error al leer el archivo.");
                }
                break;
            case 3:
                break;
        }
    }
    else
    {
        printf("DNI no encontrado.\n");
    }
}

void modifyRunner(char dni[10])
{
    char option;
    char str[50];
    char newDni[10];
    char name[20];
    char tlfn[9];
    char email[30];
    char birthdate[11];
    char password[10];

    int r = -1;

    FILE* f;
    int num = 0;
    Runner* runners;
    if((f = fopen("runners.dat", "rb"))!=NULL)
    {
        num = fgetc(f);
        runners = (Runner*) malloc(num* sizeof(Runner));
        fread(runners, sizeof(Runner), num, f);
    }

    for(int i = 0; i < num; i++)
    {
        if(strcmp(runners[i].dni, dni) == 0)
        {
            r = i;
            break;
        }
    }
    if(r != -1)
    {
        do{
            printf("\nMODIFICACION DE DATOS DE CORREDOR\n");
            printf("---------------------------------\n");
            printf("1.- Cambiar DNI.\n");
            printf("2.- Cambiar el nombre.\n");
            printf("3.- Cambiar el telefono.\n");
            printf("4.- Cambiar la fecha de nacimiento.\n");
            printf("5.- Cambiar el email.\n");
            printf("6.- Cambiar la contraseña.\n");
            printf("7.- Atrás.");

            fflush(stdout);
            fflush(stdin);
            scanf("%c", &option);

            switch(option){
                case '1':
                    printf("Introduzca el dni nuevo: \n");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(newDni, str);
                    strcpy(runners[r].dni, newDni);
                    break;
                case '2':
                    printf("Introduzca el nombre nuevo: \n");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(name, str);
                    strcpy(runners[r].name, name);
                    break;
                case '3':
                    printf("Introduzca el nuevo número de telefono: \n");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(tlfn, str);
                    strcpy(runners[r].tlfn, tlfn);
                    break;
                case '4':
                    printf("Introduzca la nueva fecha de nacimiento: \n");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(birthdate, str);
                    strcpy(runners[r].birthdate, birthdate);
                    break;
                case '5':
                    printf("Introduzca el email nuevo: \n");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(email, str);
                    strcpy(runners[r].email, email);
                    break;
                case '6':
                    printf("Introduzca la nueva contraseña: \n");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    strcpy(password, str);
                    strcpy(runners[r].password, password);
                    break;
                case '7':
                    break;
                default:
                    printf("ERROR. La opcion elegida no es correcta.\n");
            }
        }while(option != '7');
        
        fclose(f);
        f = fopen("runners.dat", "wb");
        fputc(num, f);
        fwrite(runners, sizeof(Runner), num, f);
        fclose(f);
        free(runners);
    }else{
        printf("No se ha encontrado el corredor.\n");
    }
}