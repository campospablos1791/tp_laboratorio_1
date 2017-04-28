#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <strings.h>"
#include "utn.h"

int getInt(char mensaje[])
{
    int entero;
    printf("%s",mensaje);
    scanf("%d",&entero);
    return entero;
}
float getFloat(char mensaje[])
{
    float flotante;
    printf("%s",mensaje);
    scanf("%f",&flotante);
    return flotante;
}
char getChar(char mensaje[])
{
    char caracter;
    printf("%s",mensaje);
    fflush(stdin); // Win
    // fpurge(stdin); //Linux y OSx
    scanf("%c",&caracter);
    return caracter;
}
int getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

void CualquierTeclaContinnuar (void)
{
    printf("Presione cualquier tecla para continuar.");
    getch();
}

void getString(char mensaje[],char arrayChar[])
{
    printf("%s",mensaje);
    scanf("%s",arrayChar);
}

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
 /*
void getOnlyLetters (char mensaje[], char nombre[])
{
    char auxiliar[50];
    getString(mensaje,auxiliar);
    if(esSoloLetras(auxiliar))
    {
        strcpy(nombre,auxiliar)
    }
}*/
int getNumerosChar (char array[],char mensaje[])
{
    int i=0;
    getString(mensaje,array);
    if(esNumeroChar(array))
        {
            return 1;
        }
        return 0;
}

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


