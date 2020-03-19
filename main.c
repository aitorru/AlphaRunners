#include <stdio.h>
#include "Runner/Runner.h"

int main(void)
{
    char opcionIni;
    char back;
    char passAdmin[8];
    char* str;
    char dni[9];
    char* name;
    char* email;
    char* birthdate;
    
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
                    if(passAdmin == "ALPHARUNNERS"){
                        printf("\nMENU ADMINISTRADOR\n");
                        printf("------------------\n");
                    }else{
                        printf("¿Desea volver atrás? S/N");
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

                FILE* f = fopen("corredores.txt", "a");
                fprintf(f, "%s; %s; %s; %s\n", dni, name, email, birthdate);
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
