#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "validacion.h"

/*
* \brief  Solicita un número al usuario y devuelve el mismo.
* \param  mensaje "Mensaje que debe introducir el usuario, el cual refiere al numero que se solicitará".
* \return El número ingresado por el usuario.
*/
float ingreso(char mensaje [])
{
    float numero;
    printf("%s", mensaje);
    scanf("%f", &numero);
    return numero;
}

/*
* \brief   Suma dos números y devuelve el resultado.
* \param   a y b Dos números que serán sumados.
* \return  El resultado de la suma.
*/
float sumarDosNumFlot(float num1, float num2)
{
    float resultado;
    resultado=num1+num2;
    return resultado;
}

/*
* \brief   Resta dos números y devuelve el resultado.
* \param   a y b "valores usados para realizar la división("a" sobre "b").
* \return  El resultado de la resta.
*/
float restarDosNumFlot(float num1, float num2)
{
    float resultado;
    resultado=num1-num2;
    return resultado;
}

/*
* \brief   Divide dos números y devuelve el resultado.
* \param   a y b   valores para realiar la división.
* \return  El resultado de la división.
*/
float dividirDosNumFlot(float num1, float num2)
{
    float resultado;
    resultado=num1/num2;
    return resultado;
}

/*
* \brief   Multiplica dos números y devuelve el resultado.
* \param   a y b valores que serán multiplicados.
* \return  El resultado de la multiplicación.
*/
float multiDosNumFlot(float num1, float num2)
{
    float resultado;
    resultado=num1*num2;
    return resultado;
}

/*
* \brief   Se factoriza un número y devuelve el resultado.
* \param   num1  valor para realizar la factorización.
* \return  El resultado de la factorización.
*/
long long factorialA(float num1)
{
    long long respuesta=1;
    int i;
    for(i=num1; i>1; i--)
    {
        respuesta=respuesta*i;
    }
    return respuesta;
}

/*
* \brief  Piede al usuario una tecla cualquiera para continuar.
* \param  -
* \return -
*/
void CualquierTeclaContinnuar (void)
{
    printf("Presione cualquier tecla para continuar.");
    getch();
}

/*
* \brief  Llama a las funciones de suma, resta, multiplicacion, división y factorial, e imprime el resultado en pantalla.
* \param  num1 y num2  valores que utilizará para realizar todas las operaciones.
* \return -
*/
void integralDeOperaciones (float num1, float num2)
{
    float resultado;
    long long resultadoFactorial;

    resultado=sumarDosNumFlot(num1,num2);
    printf("\n -El resultado de la suma entre %.2f y %.2f es: %.2f\n",num1,num2,resultado);

    resultado=restarDosNumFlot(num1,num2);
    printf(" -El resultado de %.2f menos %.2f da: %.2f\n",num1,num2,resultado);

    if(num2!=0)
    {
        resultado=dividirDosNumFlot(num1,num2);
        printf(" -La division entre %.2f y %.2f es: %.2f\n",num1,num2,resultado);
    }
    else
    {
        printf(" -Error, imposible dividir por cero.\n");
    }
    resultado=multiDosNumFlot(num1,num2);
    printf(" -El producto entre %.2f y %.2f es: %.2f\n",num1,num2,resultado);

    if(validarEntero(num1))
    {
        resultadoFactorial= factorialA(num1);
        printf(" -El factorial de %.0f es %lld\n\n",num1,resultadoFactorial);//en windows la firma long long es "%I64d"
    }
    else
    {
        printf(" -%.2f no se puede factorizar.\n\n",num1);
    }
}
