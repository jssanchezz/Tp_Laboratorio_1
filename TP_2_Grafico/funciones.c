#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

//FUNCIONES VALIDADORAS DE DATOS

void val_cad(char cad[], int limit)
{
    while(strlen(cad)>limit)
    {
        printf("Error. Max. 50 caracteres: ");
        fflush(stdin);
        gets(cad);
    }
}

int val_int(int dato, int lowLimit)
{
    while(dato<lowLimit)
    {
        printf("Error. Reingrese: ");
        scanf("%d", &dato);
    }

    return dato;
}

char val_char(char dato, char datoA, char datoB)
{
    while(dato!=datoA && dato!=datoB)
    {
        printf("\nError, reingrese: ");
        dato=tolower(getche());
    }

    return dato;
}

//FUNCIONES PARA ESTRUCTURA PERSONA

void inicializarPersona(EPersona lista[])
{
    int i;

    for(i=0;i<20;i++)
    {
        lista[i].estado=0;
    }
}

int obtenerEspacioLibre(EPersona lista[])
{
    int i, rta;

    for(i=0;i<20;i++)
    {
        if(lista[i].estado==0)
        {
            rta=i;
            break;
        }
    }
    if(i==20)
        rta=-1;

    return rta;
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i, rta;

    for(i=0;i<20;i++)
    {
        if(lista[i].dni==dni)
        {
            rta=i;
            break;
        }
    }
    if(i==20)
    {
        rta=-1;
    }

    return rta;
}

void agregarPersona(EPersona lista[], int indice)
{
    char auxcad[100];
    int aux;

    system("cls"); //nombre edad estado dni;

    printf("Nombre: ");
    fflush(stdin);
    gets(auxcad);
    val_cad(auxcad, 49);
    strcpy(lista[indice].nombre, auxcad);

    printf("\nEdad: ");
    scanf("%d", &aux);
    aux=val_int(aux, 1);
    lista[indice].edad=aux;

    printf("\nDNI: ");
    scanf("%d", &aux);
    aux=val_int(aux, 1);
    lista[indice].dni=aux;

    lista[indice].estado=1;
}

void borrarPersona(EPersona lista[], int indice)
{
    char rta;

    printf("Esta es la persona a eliminar? s/n:\n");
    listarPersona(lista, indice);
    rta=tolower(getche());
    rta=val_char(rta, 's', 'n');
    if(rta=='s')
    {
        lista[indice].estado=0;
        system("cls");
        printf("Eliminado.");
        getch();
    }
}

void listarPersona(EPersona lista[], int indice)
{
    printf("\nNombre: %s\nEdad: %d\nDNI: %d\n", lista[indice].nombre, lista[indice].edad, lista[indice].dni);
}

void imprimirLista(EPersona lista[])
{
    int i;

    ordenarLista(lista);
    for(i=0;i<20;i++)
    {
        if(lista[i].estado==1)
            listarPersona(lista, i);
    }
}

void ordenarLista(EPersona lista[])
{
    int i, j;
    EPersona aux;

    for(i=0;i<19;i++)
    {
        for(j=i+1;j<20;j++)
        {
            if(lista[i].estado==1 && lista[j].estado==1)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }
        }
    }
}

void graficarEdades(EPersona lista[])
{
    int i, hasta18=0, de19a35=0, mayorDe35=0, flag=0, mayor;

    //hasta 18
    for(i=0;i<20;i++)
    {
        if(lista[i].estado==1 && lista[i].edad>0 && lista[i].edad<=18)
            hasta18++;
    }

    //de19a35
    for(i=0;i<20;i++)
    {
        if(lista[i].estado==1 && lista[i].edad>18 && lista[i].edad<=35)
            de19a35++;
    }

    //mayorDe35
    for(i=0;i<20;i++)
    {
        if(lista[i].estado==1 && lista[i].edad>35)
            mayorDe35++;
    }

    if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }
    else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
            mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
        {
            if(i<10)
            {
                printf("%02d|",i);
            }
            else
                printf("%02d|",i);

            if(i<= hasta18)
            {
                printf("*");
            }
            if(i<= de19a35)
            {
                flag=1;
                printf("\t*");
            }
            if(i<= mayorDe35)
            {
                if(flag==0)
                    printf("\t\t*");
                if(flag==1)
                    printf("\t*");

            }
            printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);

}

int buscarDatosCargados(EPersona lista[])
{
    int i,rta=0;

    for(i=0;i<20;i++)
    {
        if(lista[i].estado!=0)
        {
            rta=1;
            break;
        }
    }

    return rta;
}
