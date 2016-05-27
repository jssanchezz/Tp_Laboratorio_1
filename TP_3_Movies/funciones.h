#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[100];
}EMovie;

//FUNCIONES PARA MANEJO DE LA ESTRUCTURA EMovie

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie, int pos);

/**
 *  Muestra los datos de una pelicula cargada en una estructura EMovie
 *  @param movie Pelicula a ser mostrada
 */
void mostrarMovie(EMovie* movie);

/**
 *  Busca una pelicula dentro del array de estructuras por el titulo
 *  @param lista Array de estructura EMovie
 *  @param titulo Titulo a ser buscado
 *  @return el valor de la posicion donde se encuentra la pelicula, o -1 si no existe
 */
int buscarPelicula(EMovie* lista, char titulo[]);

/**
 *  Permite al usuario modificar los datos de una estructura
 *  @param movie Pelicula a ser modificada
 */
void modificarPelicula(EMovie* movie);

//FUNCIONES PARA EL MANEJO DE ARCHIVOS

/**
 *  Lee del archivo binario la cantidad de elementos del Array
 *  @return el entero con el valor de la cantidad de elementos del array
 */
int LeerCantidad();

/**
 *  Lee del archivo binario los datos guardados y los carga
 *  @param lista Puntero con la direccion donde se cargan los datos
 *  @param length Cantidad de datos a ser leidos del archivo
 */
void LeerBinario(EMovie* lista, int length);

/**
 *  Guarda en un archivo binario los datos cargados en el array de estructura
 *  @param lista Puntero con la direccion donde se leen los datos
 *  @param length Cantidad de datos a ser guardados
 */
void GuardarBinario(EMovie* lista, int length);

/**
 *  Guarda en un archivo binario el entero con la cantidad de elementos cargados en el array
 *  @param length Cantidad de elementos
 */
void GuardarCantidad(int length);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

//FUNCIONES VALIDADORAS DE DATOS

/**  Valida una cadena de caracteres dentro de un limite
 * \param cad cadena a validar
 * \param limit cantidad maxima de caracteres que debe contener la cadena
 * \return
 */
void val_cad(char cad[], int limit);

/**  Valida un entero a partir de un limite menor
 * \param dato entero a validar
 * \param lowlomit limite menor que debe tener el entero
 * \return retorna el valir validado
 */
int val_int(int dato, int lowLimit);

/** Valida un char entre otros dos caracteres
 *
 * \param dato char a validar
 * \param datoA primer char a comparar con dato
 * \param datoB segundo char a comprar con dato
 * \return retorna el char validado
 */
 char val_char(char dato, char datoA, char datoB);

/**
 *  Valida un entero dentro de un intervalo
 *  @param dato Dato a validar
 *  @param lowLimit Limite inferior del intervalo
 *  @param hiLimit Limite superior del intervalo
 *  @return el dato validado
 */
 int val_intervalo(int dato, int lowLimit, int hiLimit);

#endif // FUNCIONES_H_INCLUDED

