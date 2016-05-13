#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0, i, aux, flag=0;

    EPersona persona[20];

    inicializarPersona(persona);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                i=obtenerEspacioLibre(persona);
                if(i==-1)
                {
                    system("cls");
                    printf("No hay espacio para otra persona.");
                    getch();
                }
                else
                {
                    agregarPersona(persona, i);
                    flag=1;
                }

                break;

            case 2:
                if(flag)
                {
                    system("cls");
                    printf("DNI: ");
                    scanf("%d", &aux);
                    aux=val_int(aux, 1);
                    i=buscarPorDni(persona, aux);
                    borrarPersona(persona, i);
                    flag=buscarDatosCargados(persona);
                }
                else
                {
                    system("cls");
                    printf("Primero cargue datos.");
                    getch();
                }

                break;

            case 3:
                if(flag)
                {
                    system("cls");
                    imprimirLista(persona);
                    getch();
                }
                else
                {
                    system("cls");
                    printf("Primero cargue datos.");
                    getch();
                }

                break;

            case 4:
                if(flag)
                {
                    system("cls");
                    graficarEdades(persona);
                    getch();
                }
                else
                {
                    system("cls");
                    printf("Primero cargue datos.");
                    getch();
                }

                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
