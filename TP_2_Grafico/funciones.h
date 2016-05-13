#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


//FUNCIONES VALIDADORAS

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


//FUNCIONES PARA ESTRUCTURA PERSONA

void inicializarPersona(EPersona lista[]);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Carga los datos de una persona al array
 * \param lista el array se pasa como parametro
 * \param el indice de la posición a cargar
 */
void agregarPersona(EPersona lista[], int indice);

/** Elimina una persona del array cambiando el campo 'estado'
 * \param lista el array se pasa como parametro
 * \param el indice de la posición a borrar
 */
void borrarPersona(EPersona lista[], int indice);

/** Lista los elementos cargados en una posición del array
 * \param lista el array se pasa como parametro
 * \param el indice de la posición a listar
 */
void listarPersona(EPersona lista[], int indice);

/** Imprime por pantalla la lista total del array
 * \param lista el array se pasa como parametro
 */
void imprimirLista(EPersona lista[]);

/** Ordena la lista por nombre alfabeticamente
 * \param Se pasa el array de la estructura como parametro
 */
void ordenarLista(EPersona lista[]);

/**  Realiza el grafico por edades
 * \param Se pasa el array de la estructura como parametro
 */
void graficarEdades(EPersona lista[]);

/**  Realiza el grafico por edades
 * \param Se pasa el array de la estructura como parametro
 * \return retorna 0 si no encuentra datos cargados, retorna 1 si encuentra datos cargados
 */
int buscarDatosCargados(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
