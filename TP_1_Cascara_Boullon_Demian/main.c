/*******************************************************************
* Programa: Calculadora.
*
* Objetivo:
   Ingresar dos números y calcular:
                                    -Suma.
                                    -Resta.
                                    -Multiplicación.
                                    -División.
                                    -Factorial

* Version: 0.1 del 06 abril de 2017
* Autor: Demian Alejandro Boullon
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"
#include "validacion.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int flagA=0;
    int flagB=0;
    float num1=0;
    float num2=0;
    float resultado;
    long long resultadoFactorial;

    do
    {
        printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            num1=ingreso("Ingrese numero A: ");
            flagA=1;
            system("cls");
            break;
        case 2:
            num2=ingreso("Ingrese numero B: ");
            flagB=1;
            system("cls");
            break;
        case 3:
            if(flagA==0)
            {
                printf("Introduzca el valor de A: ");
                scanf(" %f",&num1);
                flagA=1;
            }
            if(flagB==0)
            {
                printf("Introduzca el valor de B: ");
                scanf(" %f",&num2);
                flagB=1;
            }
            resultado=sumarDosNumFlot(num1,num2);
            printf(" -La suma entre %.2f y %.2f es: %.2f\n\n",num1,num2,resultado);
            CualquierTeclaContinnuar();
            system("cls");
            break;
        case 4:
            if(flagA==0)
            {
                printf(" -Introduzca el valor de A: ");
                scanf(" %f",&num1);
                flagA=1;
            }
            if(flagB==0)
            {
                printf(" -Introduzca el valor de B: ");
                scanf(" %f",&num2);
                flagB=1;
            }
            resultado=restarDosNumFlot(num1,num2);
            printf(" -El resultado de %.2f menos %.2f da: %.2f\n\n",num1,num2,resultado);
            CualquierTeclaContinnuar();
            system("cls");
            break;
        case 5:
            if(flagA==0)
            {
                printf("Introduzca el valor de A: ");
                scanf(" %f",&num1);
                flagA=1;
            }
            if(flagB==0)
            {
                printf("Introduzca el valor de B: ");
                scanf(" %f",&num2);
                flagB=1;
            }
            if(num2!=0)
            {
                resultado=dividirDosNumFlot(num1,num2);
                printf(" -El resultado de %.2f dividido %.2f es: %.2f\n\n",num1,num2,resultado);
            }
            else
            {
                printf(" -Error, imposible dividir por cero.\n\n");
            }
            CualquierTeclaContinnuar();
            system("cls");
            break;
        case 6:
            if(flagA==0)
            {
                printf("Introduzca el valor de A: ");
                scanf(" %f",&num1);
                flagA=1;
            }
            if(flagB==0)
            {
                printf("Introduzca el valor de B: ");
                scanf(" %f",&num2);
                flagB=1;
            }
            resultado=multiDosNumFlot(num1,num2);
            printf(" -La multiplicacion entre %.2f y %.2f es: %.2f\n\n",num1,num2,resultado);
            CualquierTeclaContinnuar();
            system("cls");
            break;

        case 7:
            if(flagA==0)
            {
                printf(" -Introduzca el valor de A: ");
                scanf(" %f",&num1);
                flagA=1;
            }
            if(validarEntero(num1))
            {
                resultadoFactorial= factorialA(num1);
                printf(" -El factorial de %.0f es %lld\n\n",num1,resultadoFactorial);//en windows la firma long long es "%I64d"
            }
            else
            {
                printf(" -Error, elija la opcion 1 e ingrese un valor entero igual o mayor que cero.\n\n");
            }
            CualquierTeclaContinnuar();
            system("cls");
            break;
        case 8:
            if(flagA==0)
            {
                printf("Introduzca el valor de A: ");
                scanf(" %f",&num1);
                flagA=1;
            }
            if(flagB==0)
            {
                printf("Introduzca el valor de B: ");
                scanf(" %f",&num2);
                flagB=1;
            }
            integralDeOperaciones(num1,num2);
            CualquierTeclaContinnuar();
            system("cls");
            break;
        case 9:
            seguir = 'n';
            break;
        default:
            printf("Debe seleccionar una opcion del menu, entre 1 y 9.\n");
            CualquierTeclaContinnuar();
            system("cls");
            break;
        }
    }
    while(seguir=='s');
    return 0;
}
