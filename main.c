#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Runner/Runner.h"
#include "Employee/Employee.h"

int main(void){
    //Variables para los ficheros
    FILE* f;
    int num;

    //Variables para navegar a traves de los menus
    char opcionIni;
    char opcionAdmin;
    char back;

    //Variable para iniciar sesion como Admin
    char passAdmin[13];

    //Variable para la contraseña de corredor
    char passRunner[8];

    //Variable para no leer caracteres de más
    char* str = "";

    //Variable para modificación de datos del corredor
    char dni[10];

    //Variables para alta/baja de un trabajador
    int uniqueId = 0;
    int id;
    char nss[12];
    char name[20];
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
                    fflush(stdin);
                    fgets(str, 50, stdin);
                    strtok(str, "\n");
                    printf(" STR %s.", str);
                    strcpy(passAdmin, str);
                    printf(" passAdmin %s.", str);
                    fflush(stdout);
                    if(strcmp(passAdmin, "ALPHARUNNERS") != 0){
                        do{
                            printf("\nMENU ADMINISTRADOR\n");
                            printf("------------------\n");
                            printf("1.- Administrar carreras.\n");
                            printf("2.- Administrar corredores.\n");
                            printf("3.- Administrar trabajadores.\n");
                            printf("4.- Atrás.\n");
                            fflush(stdout);
                            fflush(stdin);
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
                                        printf("5.- Atrás.\n");

                                        fflush(stdout);
                                        fflush(stdin);
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
                                        printf("2.- Modificar un corredor.\n");
                                        printf("3.- Atrás.\n");

                                        fflush(stdout);
                                        fflush(stdin);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                runnerRegister();
                                                break;
                                            case '2':
                                                printf("Introduzca el DNI del corredor del que quieres modificar sus datos: \n");
                                                fgets(dni, 100, stdin);
                                                strtok(dni, "\n");
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
                                        printf("3.- Atrás.\n");

                                        fflush(stdout);
                                        fflush(stdin);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                printf("\nALTA DE TRABAJADOR\n");
                                                printf("------------------\n");
                                                printf("NSS: \n");
                                                fgets(nss, 100, stdin);
                                                strtok(nss, "\n");
                                                printf("Nombre y apellidos:\n");
                                                fgets(name, 100, stdin);
                                                strtok(name, "\n");
                                                printf("Salario: \n");
                                                scanf("%d", &salary);

                                                num = 0;
                                                Employee *employees1;    

                                                if((f = fopen("employees.dat", "rb"))!=NULL){
                                                    num = fgetc(f);
                                                    employees1 = (Employee*) malloc(num* sizeof(Employee));
                                                    fread(employees1, sizeof(Employee), num, f);
                                                }else{
                                                    printf("No se ha encontrado el fichero de empleados.\n");
                                                }                                               
                                                fclose(f);
                                                
                                                f = fopen("employees.dat", "wb");
                                                fputc(num+1, f);
                                                employees2 = (Employee*) malloc((num+1)* sizeof(Employee));
                                                for(int i = 0; i < num+1; i++)
                                                {
                                                    if(i != num){
                                                        employees2[i].id = employees1[i].id;
                                                        strcpy(employees2[i].nss, employees1[i].nss);
                                                        strcpy(employees2[i].name, employees1[i].name);
                                                        employees2[i].salary = employees1[i].salary;                    
                                                    }else{
                                                        employees2[i].id = uniqueId++;
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
                                                break;
                                            case '2':
                                                printf("\nBAJA DE TRABAJADOR\n");
                                                printf("------------------\n");
                                                printf("Introduzca el número identificativo del trabajador:\n");
                                                fflush(stdout);
                                                scanf("%i", &id);

                                                num = 0;
                                                Employee *employees;    

                                                if((f = fopen("employees.dat", "rb"))!=NULL){
                                                    num = fgetc(f);
                                                    employees = (Employee*) malloc(num* sizeof(Employee));
                                                    fread(employees, sizeof(Employee), num, f);
                                                }else{
                                                    printf("No se ha encontrado el fichero de empleados.\n");
                                                }                                               
                                                fclose(f);

                                                for(int i = 0; i < num; i++)
                                                {
                                                    if(employees[i].id == id)
                                                    {
                                                        strcpy(employees[i].state, "BAJA");
                                                        printf("Se ha dado de baja correctamemte al trabajador %s.\n", employees[i].name);
                                                        break;
                                                    }else{
                                                        printf("No se ha podido encontrar al trabajador.\n");
                                                    }
                                                }

                                                f = fopen("employees.dat", "wb");
                                                fputc(num, f);
                                                fwrite(employees, sizeof(Employee), num, f);
                                                fclose(f);
                                                free(employees);

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
                        fflush(stdout);
                        fflush(stdin);
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

