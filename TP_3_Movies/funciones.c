#include "funciones.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//FUNCIONES PARA EL MANEJO DE LA ESTRUCTURA EMOVIE

int agregarPelicula(EMovie* movie)
{
    char auxcad[100], rta;
    EMovie movieAux;
    int aux, agregada=0;

    system("cls");
    printf("Titulo: ");
    fflush(stdin);
    gets(auxcad);
    val_cad(auxcad,19);
    strcpy(movieAux.titulo, auxcad);

    printf("\nGenero: ");
    fflush(stdin);
    gets(auxcad);
    val_cad(auxcad,19);
    strcpy(movieAux.genero, auxcad);

    printf("\nDuracion: ");
    scanf("%d", &aux);
    aux=val_int(aux,1);
    movieAux.duracion=aux;

    printf("\nDescripcion: ");
    fflush(stdin);
    gets(auxcad);
    val_cad(auxcad,49);
    strcpy(movieAux.descripcion, auxcad);

    printf("\nPuntaje: ");
    scanf("%d", &aux);
    aux=val_intervalo(aux,1, 10);
    movieAux.puntaje=aux;

    printf("\nLink Imagen: ");
    fflush(stdin);
    gets(auxcad);
    val_cad(auxcad,99);
    strcpy(movieAux.linkImagen, auxcad);

    system("cls");
    mostrarMovie(&movieAux);
    printf("Guardar? s/n: ");
    rta=tolower(getche());
    rta=val_char(rta,'s','n');
    if(rta=='s')
    {
        *movie=movieAux;
        agregada=1;
    }

    return agregada;
}

int borrarPelicula(EMovie* lista, int pos)
{
    int length=LeerCantidad();
    int i, j, eliminada=0;
    char rta;

    system("cls");
    printf("Pelicula a eliminar: \n");
    mostrarMovie(lista+pos);
    printf("Continuar? s/n: ");
    rta=tolower(getche());
    rta=val_char(rta,'s','n');

    if(rta=='s')
    {
        if(length==1)
        {
            length=length-1;
            free(lista);
            eliminada=1;
        }
        else
        {
            for(i=pos;i<length-1;i++)
            {
                j=i+1;
                *(lista+i)=*(lista+j);
            }
            if((lista=(EMovie*)realloc(lista, sizeof(EMovie)*(length-1)))==NULL)
            {
                printf("\nNo hay memoria\n");
                exit(1);
            }
            eliminada=1;
        }
    }
    return eliminada;
}

void mostrarMovie(EMovie* movie)
{
    printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\n", movie->titulo, movie->genero, movie->duracion);
    printf("Descripcion: %s\nPuntaje: %d\nLink Imagen: %s\n\n", movie->descripcion,movie->puntaje,movie->linkImagen);
}

int buscarPelicula(EMovie* lista, char titulo[])
{
    int i, posicion=-1, length=LeerCantidad();

    for(i=0;i<length;i++)
    {
        if(strcmp(titulo, (lista+i)->titulo)==0)
        {
            posicion=i;
            break;
        }
    }

    return posicion;
}

void modificarPelicula(EMovie* movie)
{
    int op, aux;
    char rta, auxcad[50];

    system("cls");
    mostrarMovie(movie);
    printf("Esta es la pelicula a modificar? s/n: ");
    rta=tolower(getche());
    rta=val_char(rta,'s','n');
    if(rta=='s')
    {

        do
        {
            system("cls");
            printf("Que desea modificar?:\n");
            printf("1. Titulo\n2. Genero\n3. Duracion\n4. Descripcion\n5. Puntaje\n6. Link Imagen\n7. Cancelar\n");
            printf("Ingrese opcion: ");
            scanf("%d", &op);
            op=val_intervalo(op,1,7);
            switch(op)
            {
                case 1:
                    system("cls");
                    printf("Titulo: ");
                    fflush(stdin);
                    gets(auxcad);
                    val_cad(auxcad,19);
                    strcpy(movie->titulo, auxcad);

                    break;

                case 2:
                    system("cls");
                    printf("Genero: ");
                    fflush(stdin);
                    gets(auxcad);
                    val_cad(auxcad,19);
                    strcpy(movie->genero, auxcad);

                    break;

                case 3:
                    system("cls");
                    printf("\nDuracion: ");
                    scanf("%d", &aux);
                    aux=val_int(aux,1);
                    movie->duracion=aux;

                    break;

                case 4:
                    system("cls");
                    printf("Descripcion: ");
                    fflush(stdin);
                    gets(auxcad);
                    val_cad(auxcad,19);
                    strcpy(movie->descripcion, auxcad);

                    break;

                case 5:
                    system("cls");
                    printf("\nPuntaje: ");
                    scanf("%d", &aux);
                    aux=val_intervalo(aux,1,10);
                    movie->puntaje=aux;

                    break;

                case 6:
                    system("cls");
                    printf("Link imagen: ");
                    fflush(stdin);
                    gets(auxcad);
                    val_cad(auxcad,49);
                    strcpy(movie->linkImagen, auxcad);
                    break;

                default:
                    rta='n';
                    break;
            }
            if(op!=7)
            {
                system("cls");
                printf("Continuar modificando? s/n:");
                rta=tolower(getche());
                rta=val_char(rta,'s','n');
            }

        }while(rta=='s');


    }
}


//FUNCIONES PARA EL MANEJO DE ARCHIVOS

int LeerCantidad()
{
    FILE* archivo;
    int cant=0;

    archivo=fopen("datos.bin","rb");
    fread(&cant, sizeof(int), 1, archivo);
    fclose(archivo);

    return cant;
}

void LeerBinario(EMovie* lista, int length)
{
    FILE* archivo;

    archivo=fopen("lista.bin", "rb");
    if(archivo==NULL)
    {
        printf("\nNo se pudo leer archivo.\n");
        exit(1);
    }
    fread(lista, sizeof(EMovie), length, archivo);

    fclose(archivo);
}

void GuardarBinario(EMovie* lista, int length)
{
    FILE* archivo;

    archivo=fopen("lista.bin", "wb");
    if(archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
        exit(1);
    }
    fwrite(lista, sizeof(EMovie), length, archivo);
    GuardarCantidad(length);

    fclose(archivo);
}

void GuardarCantidad(int length)
{
    FILE* archivo;

    archivo=fopen("datos.bin", "wb");
    if(archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo.(datos)\n");
        exit(1);
    }
    fwrite(&length, sizeof(int), 1, archivo);


    fclose(archivo);
}

void generarPagina(EMovie lista[], char nombre[])
{
    FILE* html;
    int length, i;

    length=LeerCantidad();
    strcat(nombre, ".html");
    html=fopen(nombre,"w");

    if(html==NULL)
    {
        printf("\nNo se pudo crear html.\n");
        exit(1);
    }

    fprintf(html,"<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
    fprintf(html,"<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
    fprintf(html,"<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
    fprintf(html,"<title>Lista peliculas</title>\n<!-- Bootstrap Core CSS -->\n<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
    fprintf(html,"<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
    fprintf(html,"<link href='css/custom.css' rel='stylesheet'>\n<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
    fprintf(html,"<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n<!--[if lt IE 9]>\n");
    fprintf(html,"<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'>\n</script>\n");
    fprintf(html,"<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'>\n</script>\n<![endif]-->\n</head>\n");
    fprintf(html,"<body>\n");

    for(i=0;i<length;i++)
    {
        fprintf(html,"<div class='container'>\n<div class='row'>\n");
        fprintf(html,"\n<!-- Repetir esto para cada pelicula -->\n");
        fprintf(html,"<article class='col-md-4 article-intro'><a href='#'>");
        fprintf(html,"<img class='img-responsive img-rounded' src='%s' alt=''>", (lista+i)->linkImagen);
        fprintf(html,"</a>\n<h3>\n<a href='#'>%s\n</a>\n</h3>\n<ul>\n", (lista+i)->titulo);
        fprintf(html,"<li>Genero: %s</li>\n<li>Puntaje: %d</li>\n<li>Duracion: %d</li>\n", (lista+i)->genero, (lista+i)->puntaje,(lista+i)->duracion);
        fprintf(html,"</ul>\n<p>%s.</p>\n</article>\n", (lista+i)->descripcion);
        fprintf(html,"<!-- Repetir esto para cada pelicula -->\n");
        fprintf(html,"</div>\n<!-- /.row -->\n</div>\n<!-- /.container -->\n");

    }

    fprintf(html,"<!-- jQuery -->\n<script src='js/jquery-1.11.3.min.js'></script>\n");
    fprintf(html,"<!-- Bootstrap Core JavaScript -->\n<script src='js/bootstrap.min.js'>\n</script>\n");
    fprintf(html,"<!-- IE10 viewport bug workaround -->\n<script src='js/ie10-viewport-bug-workaround.js'>\n</script>\n");
    fprintf(html,"<!-- Placeholder Images -->\n<script src='js/holder.min.js'>\n</script>\n</body>\n</html>\n");

    printf("\nHTML creado con exito.\n");
    getch();

    fclose(html);
}


//FUNCIONES VALIDADORAS DE DATOS

void val_cad(char cad[], int limit)
{
    while(strlen(cad)>limit)
    {
        printf("Error. Max. %d caracteres: ", limit);
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

int val_intervalo(int dato, int lowLimit, int hiLimit)
{
    while(dato<lowLimit || dato>hiLimit)
    {
        printf("Error. Reingrese opcion: ");
        scanf("%d", &dato);
    }

    return dato;
}


