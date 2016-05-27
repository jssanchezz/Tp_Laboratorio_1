#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    char seguir='s', aux[50], i;
    int opcion=0, tamArray=0, flag=0, ok;
    EMovie* peliculas;

    tamArray=LeerCantidad();


    if(tamArray==0)
    {
        printf("\nNo hay datos guardados.\n");
    }
    else
    {
        peliculas=(EMovie*)malloc(tamArray*sizeof(EMovie));
        LeerBinario(peliculas, tamArray);
        flag=1;
        printf("\nDatos cargados con exito.\n");

    }
    getch();

    while(seguir=='s')
    {
        system("cls");

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        opcion=val_intervalo(opcion,1,5);

        switch(opcion)
        {
            case 1:
                if(tamArray==0)
                {
                    if((peliculas=(EMovie*)malloc(sizeof(EMovie)))==NULL)
                    {
                        printf("\nNo hay memoria\n");
                        exit(1);
                    }
                }
                else
                {
                    if((peliculas=(EMovie*)realloc(peliculas, sizeof(EMovie)*(tamArray+1)))==NULL)
                    {
                        printf("\nNo hay memoria\n");
                        exit(1);
                    }
                }
                ok=agregarPelicula(peliculas+tamArray);
                if(ok)
                {
                    tamArray++;
                    GuardarBinario(peliculas, tamArray);
                    printf("\nPelicula agregada.\n");

                    flag=1;
                }
                else
                {
                    system("cls");
                    printf("\nPelicula no agregada.\n");
                }
                getch();

                break;

            case 2:

                if(flag)
                {
                    system("cls");
                    printf("Ingrese titulo de la pelicula a eliminar: ");
                    fflush(stdin);
                    gets(aux);
                    val_cad(aux, 19);
                    i=buscarPelicula(peliculas,aux);
                    if(i!=-1)
                    {
                        ok=borrarPelicula(peliculas, i);
                        if(ok)
                        {
                            tamArray--;
                            if(tamArray==0)
                                flag=0;
                            GuardarBinario(peliculas, tamArray);
                            printf("\nEliminada.\n");
                            getch();
                        }
                        else
                        {
                            printf("\nEliminacion cancelada.\n");
                            getch();
                        }
                    }
                    else
                    {
                        printf("No existe pelicula.\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("Primero cargue peliculas.");
                    getch();
                }

                break;

            case 3:

                if(flag)
                {
                    system("cls");
                    printf("Ingrese titulo de la pelicula a modificar: ");
                    fflush(stdin);
                    gets(aux);
                    val_cad(aux, 19);
                    i=buscarPelicula(peliculas,aux);
                    if(i!=-1)
                    {
                        modificarPelicula(peliculas+i);
                    }
                    else
                    {
                        printf("\nNo existe la pelicula\n");
                        getch();
                    }
                }
                else
                {
                    printf("Primero cargue peliculas.");
                    getch();
                }
                break;

            case 4:
                if(flag)
                {
                    system("cls");
                    printf("*Generar archivo html*\n\n");
                    printf("Ingrese nombre del archivo: ");
                    fflush(stdin);
                    gets(aux);
                    val_cad(aux, 20);
                    generarPagina(peliculas, aux);
                }
                else
                {
                    printf("Primero cargue peliculas.");
                    getch();
                }

               break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    if(tamArray!=0)
       free(peliculas);

    return 0;
}
