#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>
#include "cargaYEdicion.h"

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
*/
int esSoloLetras(char array[])
{
    int  i=0;
    while(array[i]!='\0')
    {
        if(array[i]!=' ' && (array[i]<'a' || array[i]>'z') &&(array[i]<'A' || array[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief verifica si el dato ingresado es un numero
 * \param str es la cadena a ser analizada
 * \return devuelve 1 si es numerico 0 sino lo es
 *
 */
int esNumeroChar (char num[])
{
    int i=0;
    while(num[i]!='\0')
    {
        if(num[i] < '0' || num[i] > '9')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;

}



/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y valida si se encuentra dentro de un rango de edad lógico
 * \param input Array donde se cargará el texto ingresado
 * \return -
 */
void rangoEdad (char input[])
{
    int edad=atoi(input);
    if(edad<0 || edad>150)
    {
        printf("\nLA EDAD INGRESADA ES INVALIDA");
    }
}

void cualquierTeclaContinnuar(void)
{
    printf("Presione cualquier tecla para continuar.");
    getch();
}
