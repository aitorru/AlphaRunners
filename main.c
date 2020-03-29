#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Runner/Runner.h"
#include "Employee/Employee.h"
#include "Race/race.h"

int main(void){
    //Variables para los ficheros
    FILE* f;
    int num;
    bool find = false;
    int cont = 0;

    //Variables para navegar a traves de los menus
    char opcionIni;
    char opcionAdmin;
    char back;

    //Variable para iniciar sesion como Admin
    char passAdmin[13];

    //Variable para la contraseña de corredor
    char passRunner[8];
    int intentosRunner = 0;
    char opcionCorredor;
    char dniTemp[10];

    //Variable para contraseña de trabajador
    char passWorker[8];
    int intentosWorker = 0;
    char opcionWorker;

    //Variable para no leer caracteres de más
    char str[50];

    //Variable para modificación de datos del corredor
    char dni[10];

    //Variables para la creación/modificación/eliminación de carreras
    int uniqueIdR = 0;
    int id;
    char date[11];
    char time[6];
    char location[20];
    int km;
    Employee organizer;
    int nW;
    Employee* workers;
    int nP;
    Runner* runners;
    Runner* participants;
    Race* races1;
    Race* races2;

    //Variables para alta/baja de un trabajador
    int uniqueIdT = 0;
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
        fflush(stdin);
        scanf("%c", &opcionIni);
        switch(opcionIni){
            case '1':
                while (intentosRunner!=3 || opcionCorredor!='5')
                {
                    printf("\nIntroduzca la contraseña de corredor: \n");
                    fflush(stdout);
                    fflush(stdin);
                    memset(passRunner, 0, 8);
                    fgets(passRunner, 8, stdin);
                    strtok(passRunner, "\n");
                    if (strcmp(passRunner, "ALPHARUNNERS") != 0){
                            do{
                                printf("\nMENU CORREDORES\n");
                                printf("------------------\n");
                                printf("1.- Apuntarte a carrera.\n");
                                printf("2.- Desapuntarte a carrera.\n");
                                printf("3.- Editar tus datos.\n");
                                printf("4.- Ver tus estadisticas.\n");
                                printf("5.- Atrás.\n");
                                fflush(stdout);
                                fflush(stdin);
                                scanf("%c", &opcionCorredor);
                                switch(opcionCorredor)
                                {   
                                    case '1':
                                        printf("Introduce tu dni:");
                                        fflush(stdout);
                                        fflush(stdin);
                                        memset(passRunner, 0, 10);
                                        fgets(dniTemp, 10, stdin);
                                        strtok(passRunner, "\n");
                                        apuntarteACarrera(dniTemp);
                                        break;
                                    case '3':
                                        printf("Introduce tu dni");
                                        fflush(stdout);
                                        fflush(stdin);
                                        memset(passRunner, 0, 10);
                                        fgets(dniTemp, 10, stdin);
                                        strtok(passRunner, "\n");
                                        modifyRunner(dniTemp);
                                        break;
                                    case '5':
                                        intentosRunner = 3;
                                        break;
                                    default:
                                        printf("ERROR. La opcion elegida no es correcta.\n");
                                }
                            }while(opcionCorredor!='5');
                    }else
                    {
                        printf("Contraseña incorrecta.");
                    }
                    if(intentosRunner!=3) intentosRunner++;
                }
                break;
            case '2':
                while (intentosWorker!=3 || opcionCorredor!='6')
                {
                    printf("\nIntroduzca la contraseña de trabajador: \n");
                    fflush(stdout);
                    fflush(stdin);
                    memset(passWorker, 0, 8);
                    fgets(passWorker, 8, stdin);
                    strtok(passWorker, "\n");
                    if (strcmp(passWorker, "ALPHARUNNERS") != 0){
                            do{
                                printf("\nMENU TRABAJADOR\n");
                                printf("------------------\n");
                                printf("1.- Ver tu tarea.\n");
                                printf("2.- Notificar baja.\n");
                                printf("3.- Editar tus datos.\n");
                                printf("4.- Solicitar cambio de tarea.\n");
                                printf("5.- Introducir resultados de carreras.\n");
                                printf("6.- Atrás.\n");
                                fflush(stdout);
                                fflush(stdin);
                                scanf("%c", &opcionWorker);
                                switch(opcionWorker)
                                {
                                    case '1':
                                        printf("Introduzca su nss: \n");
                                        fflush(stdout);
                                        fflush(stdin);
                                        fgets(str, 50, stdin);
                                        strtok(str, "\n");
                                        strcpy(nss, str);

                                        if((f = fopen("races.dat", "rb"))!= NULL)
                                        {
                                            num = fgetc(f);
                                            races1 = (Race*) malloc(sizeof(Race)*num);
                                            fread(races1, sizeof(Race), num, f);
                                            find = true;
                                        }else{
                                            printf("No se te ha asignado ninguna tarea.\n");
                                            find = false;
                                        }

                                        cont = 0;

                                        if(find)
                                        {
                                            for(int i = 0;i < num; i++)
                                            {
                                                if(strcmp(races1[i].organizer.nss, nss) == 0)
                                                {
                                                    printf("%i.- Organizador de la carrera %s (%s).\n", cont, races1[i].name, races1[i].date);
                                                    cont++;
                                                }
                                                employees1 = (Employee*) malloc(sizeof(Employee)*races1[i].nW);
                                                employees1 = races1[i].workers;
                                                for(int j = 0; j < races1[i].nW; j++)
                                                {
                                                    if(strcmp(employees1[j].nss, nss) == 0)
                                                    {
                                                        printf("%i.- Empleado en la carrera %s (%s).\n", cont, races1[i].name, races1[i].date);
                                                        cont++;
                                                    }
                                                }
                                                free(employees1);
                                            }
                                        }
                                        free(races1);                                        
                                        break;
                                    case '2':
                                        break;
                                    case '3':
                                        printf("Introduzca el nss del trabajador:\n");
                                        fflush(stdout);
                                        fflush(stdin);
                                        fgets(str, 50, stdin);
                                        strtok(str, "\n");
                                        strcpy(nss, str);
                                        modifyEmployee(nss);
                                    case '4':
                                        break;
                                    case '5':
                                        printf("Introduzca el id de la carrera: \n");
                                        fflush(stdout);
                                        fflush(stdin);
                                        scanf("%i", &id);
                                        introduceResults(id);
                                        break;
                                    case '6':
                                        intentosWorker = 3;
                                        break;
                                    default:
                                        printf("ERROR. La opcion elegida no es correcta.\n");
                                }
                            }while(opcionWorker!='6');
                    }else
                    {
                        printf("Contraseña incorrecta.");
                    }
                    if(intentosWorker!=3) intentosWorker++;
                }
                break;
            case '3':
                do{
                    printf("Introduzca la contraseña de administrador: \n");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%12s", passAdmin);
                    char key[] = "alpharunners";
                    if(strcmp(key, passAdmin) == 0){
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
                                        printf("2.- Modificar carrera.\n");
                                        printf("3.- Eliminar una carrera.\n");
                                        printf("4.- Añadir resultados de una carrera.\n");
                                        printf("5.- Atrás.\n");
                                        fflush(stdout);
                                        fflush(stdin);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                createRace();
                                                break;
                                            case '2':
                                                printf("Introduzca el id de la carrera: \n");
                                                fflush(stdout);
                                                fflush(stdin);
                                                scanf("%i", &id);
                                                modifyRace(id);
                                                break;
                                            case '3':
                                                printf("Introduzca el id de la carrera: \n");
                                                fflush(stdout);
                                                fflush(stdin);
                                                scanf("%i", &id);
                                                deleteRace(id);
                                                break;
                                            case '4':
                                                printf("Introduzca el id de la carrera: \n");
                                                fflush(stdout);
                                                fflush(stdin);
                                                scanf("%i", &id);
                                                introduceResults(id);
                                                break;
                                            case '5':
                                                break;
                                            default:
                                                printf("ERROR. La opcion elegida no es correcta.\n");
                                        }
                                    }while(opcionAdmin != '5');
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
                                                fflush(stdout);
                                                fflush(stdin);
                                                fgets(str, 50, stdin);
                                                strtok(str, "\n");
                                                strcpy(dni, str);
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
                                        printf("2.- Modificar datos de trabajador.\n");
                                        printf("3.- Dar de baja a un trabajador.\n");
                                        printf("4.- Atrás.\n");

                                        fflush(stdout);
                                        fflush(stdin);
                                        scanf("%c", &opcionAdmin);
                                        switch(opcionAdmin){
                                            case '1':
                                                registerEmployee();
                                                break;
                                            case '2':
                                                printf("Introduzca el nss del trabajador:\n");
                                                fflush(stdout);
                                                fflush(stdin);
                                                fgets(str, 50, stdin);
                                                strtok(str, "\n");
                                                strcpy(nss, str);
                                                modifyEmployeeA(nss);
                                                break;
                                            case '3':
                                                printf("\nBAJA DE TRABAJADOR\n");
                                                printf("------------------\n");
                                                printf("Introduzca el nss del trabajador:\n");
                                                fflush(stdout);
                                                fflush(stdin);
                                                fgets(str, 50, stdin);
                                                strtok(str, "\n");
                                                strcpy(nss, str);

                                                num = 0;
                                                Employee *employees;    

                                                if((f = fopen("employees.dat", "rb"))!=NULL){
                                                    num = fgetc(f);
                                                    employees = (Employee*) malloc(num* sizeof(Employee));
                                                    fread(employees, sizeof(Employee), num, f);
                                                    find = true;
                                                }else{
                                                    printf("No se ha encontrado el fichero de empleados.\n");
                                                    find = false;
                                                }                                               
                                                fclose(f);
                                                
                                                if(find)
                                                {
                                                    for(int i = 0; i < num; i++)
                                                    {
                                                        if(strcmp(employees[i].nss, nss) == 0)
                                                        {
                                                            strcpy(employees[i].state, "BAJA");
                                                            printf("Se ha dado de baja correctamente al trabajador %s.\n", employees[i].name);
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
                                                }

                                                break;
                                            case '4':
                                                break;
                                            default:
                                                printf("ERROR. La opcion elegida no es correcta.\n");
                                        }
                                    }while(opcionAdmin != '4');
                                    opcionAdmin = '3';
                                    break;
                                case '4':
                                    break;
                                default:
                                    printf("ERROR. La opcion elegida no es correcta.\n");
                            }
                        }while(opcionAdmin != '4');
                    }else{
                        printf("Contraseña erronea.\n");
                    }
                    printf("¿Desea volver al menú inicial? S/N");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%c", &back);                    
                }while(back != 'S' && back != 's');
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

