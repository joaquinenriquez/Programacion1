#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


typedef struct
{
    char label[50];
    int valorAbs;
    int valorRel;
}graficoBarras;



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
 * Ordena una lista de EPersona alfabeticamente.
 * @param lista del tipo EPersona el array se pasa como parametro.
 * @return No devuelve nada. Ordena el array pasado como argumento
 */
void ordenarPersonas(EPersona listaPersonas[]);

/**
 * Muestra la lista de personas
 * @param lista del tipo EPersona el array se pasa como parametro.
 * @return Devuelve un int con el total de registros mostrados
 */
int mostrarListaPersonas(EPersona listaPersona[]);

/**
 * Hace el ingreso y validacion de los datos para dar de alta una persona
 * @param lista del tipo EPersona el array se pasa como parametro.
 * @return Devuelve un int = 1 si la operacion se realizo correctamente, -1 si el DNI que se esta dando de alta ya existe
 * -2 cuando se cancela la actualizacion de los datos
 */

int agregarPersona(EPersona listaPersona[]);

/**
 * Mustra un mensaje de texto con respuesta <S/N>
 * @param array tipo char con las cadena de texto que se va a mostrar en el mensaje
 * @return Devuelve un 1 si la respuesta es S (SI) y 0 si es N (NO)
 */
int msgBox(char *);


/**
 * Limpia la pantalla
 */
void clearScreen();

/**
 * Calcula los datos para poder hacer el grafico y luego llama a la funcion dibujarGrafico
 * @param array del tipo EPersona
 */
void calcularDatosEdades(EPersona listaPersonas[]);

/**
 * Muestra el grafico de barras
 * @param array tipo graficoBarras con las informacion necesaria para graficar
 */
void dibujarGrafico(graficoBarras barras[]);
#endif // FUNCIONES_H_INCLUDED
