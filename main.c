#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Runner/Runner.h"
#include "Employee/Employee.h"

void runnerRegister (void)
{
    FILE* f;
    int num;
    char* str = "";
    char dni[9];
    char* name = "";
    int tlfn;
    char* email = "";
    char* birthdate = "";
    char* password = "";
    Runner *runners1;
    Runner *runners2;

    printf("\nREGISTRO DE CORREDOR\n");
    printf("--------------------\n");
    printf("DNI: \n");
    fgets(str, 9, stdin);
    sscanf(str, "%s", dni);
    printf("Nombre y apellidos:\n");
    fflush(stdout);
    scanf("%s", name);
    printf("Número de telefono:\n");
    fflush(stdout);
    scanf("%d", &tlfn);
    printf("Email:\n");
    fflush(stdout);
    scanf("%s", email);
    printf("Fecha de nacimiento (AAAA/MM/DD): \n");
    fflush(stdout);
    scanf("%s", birthdate);
    printf("Introduzca una contraseña: \n");
    fflush(stdout);
    scanf("%s", password);

	f = fopen("runners.dat", "rb");
    num = fgetc(f);
    runners1 = (Runner*) malloc(num* sizeof(Runner));
    fread(runners1, sizeof(Runner), num, f);
    fclose(f);

    f = fopen("runners.dat", "wb");
    fputc(num+1, f);
    runners2 = (Runner*) malloc((num+1)* sizeof(Runner));
    for(int i = 0; i < num+1; i++)
    {
        if(i != num){
            strcpy(runners2[i].dni, runners1[i].dni);
            runners2[i].name = runners1[i].name;
            runners2[i].tlfn = runners1[i].tlfn;
            runners2[i].email = runners1[i].email;
            runners2[i].birthdate = runners1[i].birthdate;
            runners2[i].password = runners1[i].password;
        }else{
            strcpy(runners2[i].dni, dni);
            runners2[i].name = name;
            runners2[i].tlfn = tlfn;
            runners2[i].email = email;
            runners2[i].birthdate = birthdate;
            runners2[i].password = password;
        }                
    }   
    fwrite(runners2, sizeof(Runner), num+1, f);
    fclose(f);
    free(runners1);
    free(runners2);
}

void modifyRunner(char dni[9])
{
    char option;
    char* str = "";
    char newDni[9];
    char* name = "";
    int tlfn;
    char* email = "";
    char* birthdate = "";
    char* password = "";

    int r = -1;

    FILE* f = fopen("runners.dat", "rb");
    int num = fgetc(f);
    Runner* runners = (Runner*) malloc(num* sizeof(Runner));
    fread(runners, sizeof(Runner), num, f);

    for(int i = 0; i < num; i++)
    {
        if(strcmp(runners[i].dni, dni) != 0)
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
            scanf("%c", &option);

            switch(option){
                case '1':
                    printf("Introduzca el dni nuevo: \n");
                    fgets(str, 9, stdin);
                    sscanf(str, "%s", newDni);
                    strcpy(runners[r].dni, newDni);
                    break;
                case '2':
                    printf("Introduzca el nombre nuevo: \n");
                    scanf("%s", name);
                    runners[r].name = name;
                    break;
                case '3':
                    printf("Introduzca el nuevo número de telefono: \n");
                    scanf("%i", &tlfn);
                    runners[r].tlfn = tlfn;
                    break;
                case '4':
                    printf("Introduzca la nueva fecha de nacimiento: \n");
                    scanf("%s", birthdate);
                    runners[r].birthdate = birthdate;
                    break;
                case '5':
                    printf("Introduzca el email nuevo: \n");
                    scanf("%s", email);
                    runners[r].email = email;
                    break;
                case '6':
                    printf("Introduzca la nueva contraseña: \n");
                    scanf("%s", password);
                    runners[r].password = password;
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
    }
}


int main(void){
    //Variables para los ficheros
    FILE* f;
    int num;

    //Variables para navegar a traves de los menus
    char opcionIni;
    char opcionAdmin;
    char back;

    //Variable para iniciar sesion como Admin
    char passAdmin[8];

    //Variable para la contraseña de corredor
    char passRunner[8];

    //Variable para no leer caracteres de más
    char* str = "";

    //Variable para modificación de datos del corredor
    char dni[9];

    //Variables para alta/baja de un trabajador
    int uniqueId = 0;
    int id;
    int nss;
    char *name;
    int salary;
    Employee *employees1;
    Employee *employees2;

    do{
        printf("\nINICIO DE SESION\n");
        printf("----------------\n");
        printf("Iniciar sesion como:\n");
        printf("1.- Corredor.\n");
        printf("2.- Trabajador.\n");
        printf("3.- Administrador.\n");
        printf("4.- Registarse como corredor.\n");
        printf("Pulsar 'q' para salir.\n");
        fflush(stdout);

        scanf("%c", &opcionIni);
        switch(opcionIni){
            case '1':
                printf("Introduzca la contraseña de corredor: \n");
                fflush(stdout);
                fgets(str, 8, stdin);
                sscanf(str, "%s", passRunner);
                //WIP (Se podria leer una base de datos con contraseñas(alias)) 
                if(strcmp(passAdmin, "ALPHARUNNERS") != 0){
                        do{
                            printf("\nMENU CORREDORES\n");
                            printf("------------------\n");
                            printf("1.- Apuntarte a carrera.\n");
                            printf("2.- Desapuntarte a carrera.\n");
                            printf("3.- Editar tus datos.\n");
                            printf("4.- Ver tus estadisticas.\n");
                            printf("5.- Atrás.");
                            scanf("%c", &opcionAdmin);
                            switch(opcionAdmin)
                            {
                                case '5':
                                    break;
                                default:
                                    printf("ERROR. La opcion elegida no es correcta.\n");
                            }
                        }while(0);
                }
                break;
            case '2':
                printf("Introduzca la contraseña de corredor: \n");
                fflush(stdout);
                fgets(str, 8, stdin);
                sscanf(str, "%s", passRunner);
                //WIP (Se podria leer una base de datos con contraseñas(alias)) 
                if(strcmp(passAdmin, "ALPHARUNNERS") != 0){
                        do{
                            printf("\nMENU TRABAJADOR\n");
                            printf("------------------\n");
                            printf("1.- Ver tu tarea.\n");
                            printf("2.- DNotificar baja.\n");
                            printf("3.- Editar tus datos.\n");
                            printf("4.- Solicitar cambio de tarea.\n");
                            printf("5.- Introducir resultados de carreras.\n");
                            printf("6.- Atrás.");
                            scanf("%c", &opcionAdmin);
                            switch(opcionAdmin)
                            {
                                case '6':
                                    break;
                                default:
                                    printf("ERROR. La opcion elegida no es correcta.\n");
                            }
                        }while(0);
                }
                break;
            case '3':
                do{
                    printf("Introduzca la contraseña de administrador: \n");
                    fflush(stdout);
                    fgets(str, 8, stdin);
                    sscanf(str, "%s", passAdmin);
                    if(strcmp(passAdmin, "ALPHARUNNERS") != 0){
                        do{
                            printf("\nMENU ADMINISTRADOR\n");
                            printf("------------------\n");
                            printf("1.- Administrar carreras.\n");
                            printf("2.- Administrar corredores.\n");
                            printf("3.- Administrar trabajadores.\n");
                            printf("4.- Atrás.");
                            scanf("%c", &opcionAdmin);
                            switch(opcionAdmin){
                                case '1':
                                    do{
                                        printf("\nADMINISTRACION DE CARRERAS\n");
                                        printf("--------------------------\n");
                                        printf("1.- Crear una carrera.\n");
                                        printf("2.- Modificar carrera.");
                                        printf("3.- Eliminar una carrera.\n");
                                        printf("4.- Añadir resultados de una carrera.\n");
                                        printf("5.- Atrás.");

                                        fflush(stdout);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                
                                                break;
                                            case '2':
                                                
                                                break;
                                            case '3':
                                                break;
                                            default:
                                                printf("ERROR. La opcion elegida no es correcta.\n");
                                        }
                                    }while(opcionAdmin != '3');
                                    break;
                                case '2':
                                    do{
                                        printf("\nADMINISTRACION DE CORREDORES\n");
                                        printf("--------------------------\n");
                                        printf("1.- Registrar un corredor.\n");
                                        printf("2.- Modificar un corredor.");
                                        printf("3.- Atrás.");

                                        fflush(stdout);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                runnerRegister();
                                                break;
                                            case '2':
                                                printf("Introduzca el DNI del corredor del que quieres modificar sus datos: \n");
                                                fgets(str, 9, stdin);
                                                sscanf(str, "%s", dni);
                                                modifyRunner(dni);
                                                break;
                                            case '3':
                                                break;
                                            default:
                                                printf("ERROR. La opcion elegida no es correcta.\n");
                                        }
                                    }while(opcionAdmin != '3'); 
                                    break;
                                case '3':
                                    do{
                                        printf("\nADMINISTRACION DE TRABAJADORES\n");
                                        printf("------------------------------\n");
                                        printf("1.- Dar de alta a un trabajador.\n");
                                        printf("2.- Dar de baja a un trabajador.\n");
                                        printf("3.- Atrás.");

                                        fflush(stdout);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                printf("\nALTA DE TRABAJADOR\n");
                                                printf("------------------\n");
                                                printf("NSS: \n");
                                                fgets(str, 11, stdin);
                                                sscanf(str, "%d", &nss);
                                                printf("Nombre y apellidos:\n");
                                                fflush(stdout);
                                                scanf("%s", name);
                                                printf("Salario: \n");
                                                scanf("%d", &salary);
                                                
                                                f = fopen("employees.dat", "rb");
                                                num = fgetc(f);
                                                employees1 = (Employee*) malloc(num* sizeof(Employee));
                                                fread(employees1, sizeof(Employee), num, f);
                                                fclose(f);

                                                f = fopen("employees.dat", "wb");
                                                fputc(num+1, f);
                                                employees2 = (Employee*) malloc((num+1)* sizeof(Employee));
                                                for(int i = 0; i < num+1; i++)
                                                {
                                                    if(i != num){
                                                        employees2[i].id = employees1[i].id;
                                                        employees2[i].nss = employees1[i].nss;
                                                        employees2[i].name = employees1[i].name;
                                                        employees2[i].salary = employees1[i].salary;                    
                                                    }else{
                                                        employees2[i].id = uniqueId++;
                                                        employees2[i].nss = nss;
                                                        employees2[i].name = name;
                                                        employees2[i].salary = salary;
                                                    }
                                                    employees2[i].state = "ALTA";
                                                }
                                                fwrite(employees2, sizeof(Employee), num+1, f);
                                                fclose(f);
                                                free(employees1);
                                                free(employees2);
                                                break;
                                            case '2':
                                                printf("\nBAJA DE TRABAJADOR\n");
                                                printf("------------------\n");
                                                printf("Introduzca el número identificativo del trabajador:\n");
                                                fflush(stdout);
                                                scanf("%i", &id);

                                                f = fopen("employees.dat", "rb");
                                                int num = fgetc(f);
                                                Employee *employees = (Employee*) malloc(num* sizeof(Employee));
                                                fread(employees, sizeof(Employee), num, f);
                                                fclose(f);

                                                for(int i = 0; i < num; i++)
                                                {
                                                    if(employees[i].id = id)
                                                    {
                                                        employees[i].state = "BAJA";
                                                        printf("Se ha dado de baja correctamemte al trabajador %s.\n", employees[i].name);
                                                        break;
                                                    }
                                                }
                                                break;
                                            case '3':
                                                break;
                                            default:
                                                printf("ERROR. La opcion elegida no es correcta.\n");
                                        }
                                    }while(opcionAdmin != '3');
                                    break;
                                case '4':
                                    break;
                                default:
                                    printf("ERROR. La opcion elegida no es correcta.\n");
                            }
                        }while(opcionAdmin != '4');
                    }else{
                        printf("¿Desea volver al menú inicial? S/N");
                        scanf("%c", &back);
                    }
                }while(back != 'S' || back != 's');
                break;
            case '4':
                runnerRegister();
                break;
            case 'q':
                break;
            default:
                printf("ERROR. La opcion elegida no es correcta.\n");
        }
    }while(opcionIni != 'q' );
    return 0;
}

