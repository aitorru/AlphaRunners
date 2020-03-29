#include "Employee.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registerEmployee(void)
{
    FILE* f;
    int num = 0;  
    char str[50];
    Employee *employees1;
    Employee *employees2;
    char nss[12];
    char name[20];
    int salary;
    
    printf("\nALTA DE TRABAJADOR\n");
    printf("------------------\n");
    printf("NSS: \n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(nss, str);
    printf("Nombre y apellidos:\n");
    fflush(stdout);
    fflush(stdin);
    fgets(str, 50, stdin);
    strtok(str, "\n");
    strcpy(name, str);
    printf("Salario: \n");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &salary);

    if((f = fopen("employees.dat", "rb"))!=NULL){
        num = fgetc(f);
        employees1 = (Employee*) malloc(num* sizeof(Employee));
        fread(employees1, sizeof(Employee), num, f);
    }                                             
    fclose(f);
                                                
    f = fopen("employees.dat", "wb");
    fputc(num+1, f);
    employees2 = (Employee*) malloc((num+1)* sizeof(Employee));
    for(int i = 0; i < num+1; i++)
    {
        if(i != num){
            strcpy(employees2[i].nss, employees1[i].nss);
            strcpy(employees2[i].name, employees1[i].name);
            employees2[i].salary = employees1[i].salary;                    

        }else{
            strcpy(employees2[i].nss, nss);
            strcpy(employees2[i].name, name);
            employees2[i].salary = salary;
        }
            strcpy(employees2[i].state, "ALTA");
    }
    fwrite(employees2, sizeof(Employee), num+1, f);
    fclose(f);
    free(employees1);
    free(employees2);
}

void modifyEmployee(char nss[12])
{
    char option;
    FILE* f;
    int num = 0;  
    char str[50];
    Employee *employees1;
    char nssNuevo[12];
    char name[20];
    int salary;

    if((f = fopen("employees.dat", "rb"))!=NULL){
        num = fgetc(f);
        employees1 = (Employee*) malloc(num* sizeof(Employee));
        fread(employees1, sizeof(Employee), num, f);
    }                                             
    fclose(f);

    int r = -1;
    for(int i = 0; i < num; i++)
    {
        if(strcmp(employees1[i].nss, nss) == 0)
        {
            r = i;
            break;
        }
    }
    if(r != -1)
    {
        printf("\nMODIFICACION DATOS DE TRABAJADOR\n");
        printf("------------------\n");
        printf("1.- Cambiar NSS. \n");
        printf("2.- Cambiar nombre y apellidos. \n");
        printf("3.- Atrás.\n");
        fflush(stdout);
        fflush(stdin);
        scanf("%c", &option);

        switch(option)
        {
            case '1':
                printf("NSS nuevo: \n");
                fflush(stdout);
                fflush(stdin);
                fgets(str, 50, stdin);
                strtok(str, "\n");
                strcpy(nssNuevo, str);
                strcpy(employees1[r].nss, nssNuevo);
                break;
            case '2':
                printf("Nombre y apellidos nuevos:\n");
                fflush(stdout);
                fflush(stdin);
                fgets(str, 50, stdin);
                strtok(str, "\n");
                strcpy(name, str);
                strcpy(employees1[r].name, name);
                break;
            case '3':
                break;
            default:
                printf("ERROR. La opción elegida no es correcta.\n");
        }
                                                    
        f = fopen("employees.dat", "wb");
        fputc(num, f);
        fwrite(employees1, sizeof(Employee), num, f);
        fclose(f);
        free(employees1);
    }else{
        printf("No se ha encontrado el trabajador.\n");
    }
}

void modifyEmployeeA(char nss[12])
{
    char option;
    FILE* f;
    int num = 0;  
    char str[50];
    Employee *employees1;
    char nssNuevo[12];
    char name[20];
    int salary;

    if((f = fopen("employees.dat", "rb"))!=NULL){
        num = fgetc(f);
        employees1 = (Employee*) malloc(num* sizeof(Employee));
        fread(employees1, sizeof(Employee), num, f);
    }                                             
    fclose(f);

    int r = -1;
    for(int i = 0; i < num; i++)
    {
        if(strcmp(employees1[i].nss, nss) == 0)
        {
            r = i;
            break;
        }
    }
    
    if(r != -1)
    {
        printf("\nMODIFICACION DATOS DE TRABAJADOR\n");
        printf("------------------\n");
        printf("1.- Cambiar NSS. \n");
        printf("2.- Cambiar nombre y apellidos. \n");
        printf("3.- Cambiar salario.\n");
        printf("4.- Atrás.\n");
        fflush(stdout);
        fflush(stdin);
        scanf("%c", &option);

        switch(option)
        {
            case '1':
                printf("NSS nuevo: \n");
                fflush(stdout);
                fflush(stdin);
                fgets(str, 50, stdin);
                strtok(str, "\n");
                strcpy(nssNuevo, str);
                strcpy(employees1[r].nss, nssNuevo);
                break;
            case '2':
                printf("Nombre y apellidos nuevos:\n");
                fflush(stdout);
                fflush(stdin);
                fgets(str, 50, stdin);
                strtok(str, "\n");
                strcpy(name, str);
                strcpy(employees1[r].name, name);
                break;
            case '3':
                printf("Salario nuevo: \n");
                fflush(stdout);
                fflush(stdin);
                scanf("%d", &salary);
                employees1[r].salary = salary;
                break;
            case '4':
                break;
            default:
                printf("ERROR. La opción elegida no es correcta.\n");
        }
                                                    
        f = fopen("employees.dat", "wb");
        fputc(num, f);
        fwrite(employees1, sizeof(Employee), num, f);
        fclose(f);
        free(employees1);
    }else{
        printf("No se ha encontrado el trabajador.\n");
    }
    
}