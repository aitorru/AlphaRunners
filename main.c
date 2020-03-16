#include <stdio.h>
#include "Runner/Runner.h"

int main(void)
{
    char opcionIni;
    
    do{
        printf("INICIO DE SESION\n");
        printf("----------------\n");
        printf("Iniciar sesion como:\n");
        printf("1.- Corredor.\n");
        printf("2.- Trabajador.\n");
        printf("3.- Administrador.\n");
        printf("4.- Registarse como corredor.\n")
        printf("Pulsar 'q' para salir.\n");
        fflush(stdout);

        opcionIni = getchar();
        switch(c){
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                char* name;
                char* email;
                char* birthdate;

                printf("REGISTRO\n");
                printf("--------\n");
                printf("Nombre y apellidos:\n");
                fflush(stdout);
                name = getchar();
                printf("Email:\n");
                fflush(stdout);
                name = getchar();
                printf("Fecha de nacimiento (AAAA/MM/DD): \n");
                fflush(stdout);
                birthdate = getchar();

                FILE* f;
                f = fopen("corredores.dat", "w");
                fprintf("%s, %s, %s", name, email, birthdate);
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
