#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "utn.h"
#include "funciones.h"

#define MAX_REGISTROS 20

#define GR_EDADES 3//Grupos de edades para graficar




int obtenerEspacioLibre(EPersona lista[]){
    int i;

    for (i = 0; i < MAX_REGISTROS; i++){
        if (lista[i].estado == 0){
            return i;
            break;
        }
    }
    return -1;
}
int buscarPorDni(EPersona listaPersonas[], int dni)
{
    int i;

    for (i = 0; i < MAX_REGISTROS; i++)
    {
        if(listaPersonas[i].dni == dni && listaPersonas[i].estado == 1)
        {
            return i;
            break;
        }
    }
    return -1;
}
int borrarPersona(EPersona listaPersonas[], int dni)
{
    int index = buscarPorDni(listaPersonas, dni);

    if (index != -1)
    {
        listaPersonas[index].estado = 0;
        return 1;
    }
    return -1;
}
void ordenarListaPersonas (EPersona listaPersonas[])
{
    int i, j;
    EPersona auxPersona;

    for (i = 0; i < MAX_REGISTROS; i++)
    {
        for (j = i + 1; j < MAX_REGISTROS; j++)
        {
            if ((strcmp(listaPersonas[i].nombre, listaPersonas[j].nombre) > 0))
            {
                auxPersona = listaPersonas[i];
                listaPersonas[i] = listaPersonas[j];
                listaPersonas[j] = auxPersona;
            }
        }
    }
}
int mostrarListaPersonas(EPersona listaPersonas[])
{
    int i, cont = 0;

    printf("%-15s %8s %15s\n", "DNI", "NOMBRE", "EDAD");
    printf("-----------------------------------------\n");
    for (i = 0; i < MAX_REGISTROS; i++)
    {
        if (listaPersonas[i].estado == 1)
        {
            printf("%-15d %08s %15d\n", listaPersonas[i].dni, listaPersonas[i].nombre, listaPersonas[i].edad);
            printf("-----------------------------------------\n");
            cont ++;
        }
    }
    return cont;
}
int agregarPersona(EPersona listaPersonas[])
{
    char c;
    int index;
    char auxDNI[20] = {};
    char auxNombre[50];
    char auxEdad[20]={};


    index = obtenerEspacioLibre(listaPersonas);

    if (index == -1)
    {
        return index; //no hay espacio libre
    }
    else
    {
        clearScreen();

        printf("Alta personas\n\n");

        while (getStringNumeros("DNI: ", auxDNI) == 0)
        {
            printf("El DNI debe ser numerico!\n");
        }

        if (buscarPorDni(listaPersonas, atoi(auxDNI)) != -1)
        {
            return -3;
        }

        while (getStringLetras("NOMBRE: ", auxNombre) == 0)
        {
            printf("El nombre debe ser solo letras\n");
        }

        while((c= getchar()) != '\n' && c != EOF);

        while (getStringNumeros("EDAD: ", auxEdad) == 0)
        {
            printf("La edad debe ser numerica!\n");
        }

        if (msgBox("Confirma los datos? <S/N>: "))
        {
            listaPersonas[index].dni = atoi(auxDNI);
            strcpy(listaPersonas[index].nombre, auxNombre);
            listaPersonas[index].edad = atoi(auxEdad);
            listaPersonas[index].estado = 1;
            return 1; //Alta correcta
        }
        else
        {
            return -2; //Operacion cancelada
        }
    }
}
int msgBox(char msgtext[100]){

    char confirma, c;

    printf("\n%s", msgtext);

    while((c= getchar()) != '\n' && c != EOF);

    confirma = getchar();
    confirma = tolower(confirma);

    while (confirma !='s' && confirma !='n'){
        printf("Opcion no valida, intente de nuevo por favor");
        while((c= getchar()) != '\n' && c != EOF);
        confirma = getchar();
    }

    if (confirma == 's')
    {
        return 1;
    }
    else if (confirma == 'n')
    {
        return 0;
    }
}
void clearScreen (){
    system("clear");
}
void calcularDatosEdades (EPersona listaPersonas[])
{
    int cantPersonasGrupo1 = 0, cantPersonasGrupo2 = 0, cantPersonasGrupo3 = 0;
    int edadPersona;
    int i;

    graficoBarras barras[2];

    for (i = 0; i < MAX_REGISTROS; i++)
    {
        edadPersona = listaPersonas[i].edad;

        if (edadPersona > 1 && edadPersona <= 18)
        {
            cantPersonasGrupo1++;
        }
        else if (edadPersona >= 19 && edadPersona <= 35)
        {
            cantPersonasGrupo2++;
        }
        else if (edadPersona > 35)
        {
            cantPersonasGrupo3++;
        }
    }

    strcpy(barras[0].label, "Menor de 18");
    barras[0].valorAbs = cantPersonasGrupo1;

    strcpy(barras[1].label, "Entre 18 y 35");
    barras[1].valorAbs = cantPersonasGrupo2;

    strcpy(barras[2].label, "Mayor de 35");
    barras[2].valorAbs = cantPersonasGrupo3;

    dibujarGrafico(barras);

    getchar();
}
void dibujarGrafico(graficoBarras barras[])
{
    int i, j,posMax;
    int valorMax = INT_MIN;
    const TAM_BAR = 15;

    for ( i = 0; i < GR_EDADES; i++)      //Calculamos el mayor
    {
        if (barras[i].valorAbs > valorMax)
        {
            valorMax = barras[i].valorAbs;
            posMax = i;
        }
    }

    /*barras[posMax].valorRel = TAM_BAR;   //Definimos el alto maximo de barras al mayor

    for (i = 0; i < GR_EDADES; i++)      //Calculamos los tamños relativos
    {
        if (i != posMax){
            barras[i].valorRel = (barras[i].valorAbs * TAM_BAR) / valorMax;
        }
    }*/

    printf("Estadisticas de edades:\n\n");

    for (i = valorMax; i > 0; i--)
    {
        for (j = 0; j < GR_EDADES; j++)
        {
            if (barras[j].valorAbs >= i)
            {
                printf("             ****");
            }
            else
            {
                printf("                 ");
            }
        }
    putchar('\n');
    }

    for (i = 0; i < GR_EDADES; i++)     //Imprimimoos leyendas
    {
        printf("  %15s  ", barras[i].label);
    }
}
