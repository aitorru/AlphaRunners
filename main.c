#include <stdio.h>
#include <string.h>
#include "Runner/Runner.h"

int main(void)
{
    //Variables para navegar a traves de los menus
    char opcionIni;
    char opcionAdmin;
    char back;

    //Variable para iniciar sesion como Admin
    char passAdmin[8];

    //Variable para no leer caracteres de más
    char* str = "";

    //Variables para que los corredores se registres
    char dni[9];
    char* name = "";
    char* email = "";
    char* birthdate = "";
    char* password = "";

    do{
        printf("INICIO DE SESION\n");
        printf("----------------\n");
        printf("Iniciar sesion como:\n");
        printf("1.- Corredor.\n");
        printf("2.- Trabajador.\n");
        printf("3.- Administrador.\n");
        printf("4.- Registarse como corredor.\n");
        printf("Pulsar 'q' para salir.\n");
        fflush(stdout);

        opcionIni = getchar();
        switch(opcionIni){
            case '1':
                break;
            case '2':
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
                            opcionAdmin = getchar();
                            switch(opcionAdmin){
                                case '1':
                                    break;
                                case '2':
                                    break;
                                case '3':
                                    do{
                                        printf("\nADMINISTRACION DE TRABAJADORES\n");
                                        printf("------------------------------\n");
                                        printf("1.- Dar de alta a un trabajador.\n");
                                        printf("2.- Dar de baja a un trabajador.\n");
                                        printf("3.- Atrás.");

                                        fflush(stdout);
                                        opcionAdmin = getchar();
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
                                case '4':
                                    break;
                                default:
                                    printf("ERROR. La opcion elegida no es correcta.\n");
                            }
                        }while(opcionAdmin != '4');
                    }else{
                        printf("¿Desea volver al menú inicial? S/N");
                        back = getchar();
                    }
                }while(back != 'S' || back != 's');
                break;
            case '4':
                printf("\nREGISTRO\n");
                printf("--------\n");
                printf("DNI: \n");
                fgets(str, 9, stdin);
                sscanf(str, "%s", dni);
                printf("Nombre y apellidos:\n");
                fflush(stdout);
                scanf("%s", name);
                printf("Email:\n");
                fflush(stdout);
                scanf("%s", email);
                printf("Fecha de nacimiento (AAAA/MM/DD): \n");
                fflush(stdout);
                scanf("%s", birthdate);
                printf("Introduzca una contraseña: \n");
                fflush(stdout);
                scanf("%s", password);

                Runner r;
                strcpy(r.dni, dni);
                r.name = name;
                r.email = email;
                r.birthdate = birthdate;
                r.password = password;
                Runner runners[1];
                runners[0] = r;
	            FILE* f = fopen("runners.dat", "ab");
                fwrite(runners, sizeof(Runner), 1, f);
                fclose(f);

                break;
            case 'q':
                break;
            default:
            printf("ERROR. La opcion elegida no es correcta.\n");
        }
        printf("\n");
    }while(opcionIni != 'q' );
    return 0;
}

