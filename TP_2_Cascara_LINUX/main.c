#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"

#define MAX_REGISTROS 20                             //Dimension del vector listaPersnas


int main()
{
    char seguir = 's';                              //flag del bucle del menu
    char status[100] = {};                         //Texto de estado en pantalla principal
    char auxOpcion[10] = {};                       //Para validar el menu
    int opcion = 0;                               //Opciones del menu
    int dni = 0;
    int index;
    int resultadoOperacion = 0;                  //Auxiliar para gurdar el resultado de las operaciones
    int cantPersonasCargadas;                   //Cantidad de Personas cargadas

    //EPersona listaPersonas[MAX_REGISTROS] = {{"Juan",10,1,12345678},{"Maria",20,1,22345678},{"Raul",40,1,3234567}, {"Isabel",40,1,4235678},{"Patricia",40,1,5678914}};
    EPersona listaPersonas[MAX_REGISTROS] = {{"Nahuel",15,1,12345678},{"Eluney",16,1,12345679},{"Millaray",17,1,12345680},{"Sayen",18,1,12345681},{"Ayelen",21,1,12345682},{"Aimara",25,1,12345683},{"Efrain",65,0,12345689},{"Efren",15,0,12345690},{"Elena",17,0,12345691},{"Eleonor",50,0,12345692},{"Elias",22,0,12345693},{"Elias",78,0,12345694},{"Elisabeth",55,0,12345695},{"Eloisa",5,0,12345696},{"Elsa",19,0,12345697},{"Nehuen",24,1,12345684},{"Edgardo",30,1,12345685},{"Edith",34,1,12345686},{"Edmundo",40,1,12345687},{"Eduardo",41,1,12345688}};

    MENU: while(seguir=='s')
    {
        clearScreen();
        printf("BIENVENIDO\n\n");
        printf("1 - Agregar persona..\n");
        printf("2 - Borrar persona..\n");
        printf("3 - Imprimir lista ordenada por nombre..\n");
        printf("4 - Imprimir grafico de edades..\n\n");
        printf("5 - Salir\n\n\n");

        printf("%s", status); //estado de la operacion
        printf("---------------------------------------------------------------------\n");


        if (getStringNumeros("ELIGA UNA OPCION: ",auxOpcion) == 1){
            opcion = atoi(auxOpcion);
        } else{
            strcpy(status, "Opcion no valida\n");
            goto MENU;
        }

        getchar();   //Hacemos una pausa

        status[100] = '\0'; //limpiamos el status

        switch(opcion)
        {
            case 1:
                resultadoOperacion = (agregarPersona(listaPersonas));
                if (resultadoOperacion == 1)         //En funcion de lo que devuelva agregarPersona mostramos distintos mensajes.
                {
                    strcpy(status, "Persona dada de alta correctamente!\n");
                }
                else if (resultadoOperacion == -1)
                {
                    strcpy(status,"La memoria llego al maximo. Elimine algun registro e intente de nuevo.\n");
                }
                else if (resultadoOperacion == -2)
                {
                    strcpy(status,"Se cancelo el alta de la persona.\n");
                }
                else if (resultadoOperacion == -3)
                {
                    strcpy(status, "La persona ya se encuentra cargada.\n");
                }
                break;

            case 2:
                clearScreen();
                printf("Eliminar por DNI \n\nDNI:");
                scanf("%d", &dni);

                if (borrarPersona(listaPersonas, dni) == 1)
                {
                    strcpy(status, "Se elimino la persona\n");
                }
                else
                {
                    strcpy(status, "No existen personas con ese DNI\n");
                }
                break;

            case 3:
                clearScreen();
                ordenarListaPersonas(listaPersonas);
                cantPersonasCargadas = mostrarListaPersonas(listaPersonas); //Mostrar lista nos devuelve tambien la cant de personas
                if (cantPersonasCargadas == 0)
                {
                    strcpy(status, "No hay personas cargadas\n");
                }
                else
                {
                    sprintf(status, "Personas Cargadas: %d | Registros disponibles: %d\n", cantPersonasCargadas, MAX_REGISTROS-cantPersonasCargadas);
                    printf("\n\n\n\nPresione cualquier tecla para continuar..");
                    getchar();
                }
                break;

            case 4:
                clearScreen();
                calcularDatosEdades(listaPersonas);
                break;

            case 5:
                seguir = 'n';
                break;

            default:
                strcpy(status, "Opcion no valida\n");
                break;
        }
    }
    return 0;
}
