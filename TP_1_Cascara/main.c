#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int refreshMenu();
float operator1 = 0, operator2 = 0, result = 0;
int flagOperator1 = 0, flagOperator2 = 0;
int noDefine = 0;

int main()
{
    char seguir='s';
    int opcion=0;

    while(seguir=='s')
    {
        refreshMenu();
        printf("\n-\nINGRESE UNA OPCION: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                result = 0;
                refreshMenu();
                printf("\n-\nINGRESE PRIMER OPERANDO: ");
                scanf("%f", &operator1);
                flagOperator1 = 1;
                break;
            case 2:
                result = 0;
                refreshMenu();
                printf("\n-\nINGRESE SEGUNDO OPERANDO: ");
                scanf("%f", &operator2);
                flagOperator2 = 1;
                break;
            case 3:
                result = addition(operator1, operator2);
                break;
            case 4:
                result = subtraction(operator1, operator2);
                break;
            case 5:
                if (operator2){
                    result = division(operator1, operator2);
                } else {
                    noDefine = 1;
                }
                break;
            case 6:
                result = multiplication(operator1, operator2);
                break;
            case 7:
                result = factorial(operator1);
                break;
            case 8:
                noDefine = 3;
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
}

int refreshMenu(){
    system("cls");

    if (flagOperator1){
        printf("1- Ingresar 1er operando (A=%.2f)\n", operator1);
    } else printf("1- Ingresar 1er operando (A=x)\n");

    if (flagOperator2){
        printf("2- Ingresar 2do operando (B=%.2f)\n", operator2);
    } else printf("2- Ingresar 2do operando (B=y)\n");

    printf("3- Calcular la suma (A+B)\n");
    printf("4- Calcular la resta (A-B)\n");
    printf("5- Calcular la division (A/B)\n");
    printf("6- Calcular la multiplicacion (A*B)\n");
    printf("7- Calcular el factorial (A!)\n");
    printf("8- Calcular todas las operacione\n");
    printf("9- Salir\n");

    if (noDefine == 0){
        printf("\n-\nRESULTADO = %.2f", result);
    } else if (noDefine == 1){
        printf("\n-\nRESULTADO = LA DIVISION POR CERO NO ESTA DEFINIDA!");
        noDefine = 0;
    } else if (noDefine == 3){
        printf("\n-\nSUMA = %.2f", addition(operator1, operator2));
        printf("\nRESTA = %.2f", subtraction(operator1, operator2));
        printf("\nDIVISION = %.2f", division(operator1, operator2));
        printf("\nMULTIPLICACION = %.2f", multiplication(operator1, operator2));
        printf("\nFACTORIAL = %d", factorial(operator1));
        noDefine = 0;
    }
}

