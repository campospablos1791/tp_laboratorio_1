#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{

    char nombre[50];
    char edad[3];
    int estado;
    char dni[9];

} EPersona;


int obtenerEspacioLibre(EPersona lista[]);
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */


int buscarPorDni(EPersona lista[], int cantidad,char dni[]);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

void inicializarListaDePersonas(EPersona lista[],int cantidad,int estado);
/**
 * Le da un valor numerico a la variable "estado" en la estructura persona. En este caso "0", para indicar que está libre la posición.
 * @param lista: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidad: es la cantidad de posiciones que tiene el array.
 * @param estado: es el valor con el que se carga estado. En este caso "0".
 */
void comprimirArrayPersonas (EPersona arrayPersonas[],int cantidad, int blankFile);
/**
 * Esta función lo que hace es comprimir un array de estructuras de tipo EPersona par adiversos usos.
 * @param arrayPersonas: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidad: es la cantidad de posiciones que tiene el array.
 * @param blankFile: es el valor que indica el lugar en el índice donde se encuentra el lugar vacío.
 */
void ordenarPorNombre (EPersona arrayPersona[], int cantidad);
/**
 * Ordena un array de estructura del tipo EPersona por el nombre.
 * @param arrayPersonas: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidad: es la cantidad de posiciones que tiene el array.
 */
void imprimirListaPorNombre(EPersona listaPersonas[],int cantidad);
/**
 * Esta funcion imprime en pantalla una lista ordenada por nombre. (Utiliza la función ordenarPorNombre).
 * @param arrayPersonas: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidad: es la cantidad de posiciones que tiene el array.
 */
void imprimirGraficoEdades(EPersona lista[],int cantidad);
/**
 * Esta función detecta el rango etario con mayor cantidad de repeticiones y en base a esto imprime asteriscos y lugares en blanco "espacios" para
 generar un gráfico de barras en la pantalla, donde "y" representa a la cantidad  de personas y "x" a los tres tipos de rango: ( <18 ), ( >=18&&<=35 ) y ( >35 ).
 * @param arrayPersonas: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidad: es la cantidad de posiciones que tiene el array.
 */
void cualquierTeclaContinnuar (void);
/**
 * Esta funcion permite pausar el programa en distintas instancias para poder ver claramente una instancia del programa hasta que el usuario quiera.
 * Una vez que el usuario decide seguir adelante sólo debe tocar una tecla cualquiera para seguir.
 */
void marco (void);
/**
 * Esta función imprime un precario marco en la parte superior de la pantalla, a modo estético.
 */

void cargarDatosPersonales(EPersona listaPersona[], int cantidadDePersonas, int index);
/**
 * Esta función utiliza varias de las funciones vistas arriba y en UTN.H para cargar y validar los distintos datos.
 * @param listaPersonas: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidadDePersonas: es la cantidad de posiciones que tiene el array.
 * @param index: es la posición en el índice del array de estructura donde se cargaran los datos.
 */
int buscarIndiceVacio(EPersona listaPersonas[], int cantidad);
/**
 * Esta funcion recibe un array de estructuras de tipo EPersona, y devuelve la posición en el índice de la primera que encuantra vacía.
 * De no haber devuelve un -1.
 * @param listaPersonas: el array se pasa como parametro, en este caso una la lista de personas (la posición del array de estructuras).
 * @param cantidadDePersonas: es la cantidad de posiciones que tiene el array.
 */

#endif // FUNCIONES_H_INCLUDED
