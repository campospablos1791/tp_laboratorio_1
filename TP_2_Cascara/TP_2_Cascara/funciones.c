#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "funciones.h"
int buscarPorDni(EPersona lista[], int cantidad,char dni[])
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(lista[i].dni,dni)==0)
            return i;
    }
    return -1;
}
void inicializarListaDePersonas(EPersona lista[],int cantidad,int estado)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        lista[i].estado=estado;
    }
}
void ordenarPorNombre (EPersona arrayPersona[], int cantidad)
{
    comprimirArrayPersonas(arrayPersona,cantidad,0);
    int i,j;
    EPersona auxiliarPersona;
    for(i=0; i<cantidad; i++)
    {
        if(arrayPersona[i].estado==0)
        {
            continue;
        }
        auxiliarPersona = arrayPersona[i];
        j=i;
        for( ; j>0 && stricmp(auxiliarPersona.nombre,arrayPersona[j-1].nombre)<0 ; j--)
        {
            if(arrayPersona[j].estado==0)
            {
                continue;
            }
            arrayPersona[j]=arrayPersona[j-1];
        }
        arrayPersona[j]=auxiliarPersona;
    }
}
void comprimirArrayPersonas (EPersona arrayPersonas[],int cantidad, int blankFile)
{
    int i;
    for (i=0 ; i<cantidad; i++)
    {
        if(arrayPersonas[i].estado==blankFile)
        {
            for(; i<cantidad-1; i++)
            {
                arrayPersonas[i]=arrayPersonas[i+1];
            }
            arrayPersonas[cantidad-1].estado=blankFile;
        }
    }
}
void imprimirListaPorNombre(EPersona listaPersonas[],int cantidad)
{
    int i;
    ordenarPorNombre(listaPersonas,cantidad);
    printf("Nombre.\t\tEdad.\t\tDNI\n\n");
    for(i=0; i<cantidad && listaPersonas[i].estado==1; i++)
    {
        printf("%s\t\t%s\t\t%s\n",listaPersonas[i].nombre,listaPersonas[i].edad,listaPersonas[i].dni);
    }
}
void imprimirGraficoEdades(EPersona lista[],int cantidad)
{
    int contadorMenor_18=0;
    int contadorEntre_18_Y_35=0;
    int contadorMayor_35=0;
    int i;
    int edad;
    for(i=0; i<cantidad && lista[i].estado==1; i++)
    {
        edad=atoi(lista[i].edad);
        if(edad<18)
            contadorMenor_18++;
        else if(edad>18&&edad<35)
            contadorEntre_18_Y_35++;
        else
            contadorMayor_35++;
    }
    if(contadorMenor_18>contadorEntre_18_Y_35&&contadorMenor_18>contadorMayor_35)
    {
        for(i=contadorMenor_18; i>0; i--)
        {
            printf("\n  *\t");
            if(i==contadorEntre_18_Y_35)
            {
                printf("  *\t");
                contadorEntre_18_Y_35--;
            }
            else
            {
                printf(" \t");
            }
            if(i==contadorMayor_35)
            {
                printf(" *\n");
                contadorMayor_35--;
            }
            else
                printf("\n");
        }
        printf(" <18\t18a35\t>35\n");
    }
    else if(contadorEntre_18_Y_35>contadorMenor_18&&contadorEntre_18_Y_35>contadorMayor_35)
    {
        for(i=contadorEntre_18_Y_35; i>0; i--)
        {
            if(i==contadorMenor_18)
            {
                printf("\n  *\t");
                contadorMenor_18--;
            }
            else
            {
                printf("\n   \t");
            }
            printf("  *\t");
            if(i==contadorMayor_35)
            {
                printf(" *\n");
                contadorMayor_35--;
            }
            else
                printf("\n");
        }
        printf(" <18\t18a35\t>35\n");
    }
    else
    {
        for(i=contadorMayor_35; i>0; i--)
        {
            if(i==contadorMenor_18)
            {
                printf("\n  *\t");
                contadorMenor_18--;
            }
            else
            {
                printf("\n   \t");
            }
            if(i==contadorEntre_18_Y_35)
            {
                printf("  *\t");
                contadorEntre_18_Y_35--;
            }
            else
            {
                printf("   \t");
            }
            printf(" *\n");
        }
        printf(" <18\t18a35\t>35\n");
    }
}
void cualquierTeclaContinnuar(void)
{
    printf("Presione cualquier tecla para continuar.");
    getch();
}
void marco (void)
{
    system("cls");
    printf("=========================================================\n\n");
}
void cargarDatosPersonales (EPersona listaPersona[], int cantidadDePersonas, int index)
{
    char auxNombre[50];
    char auxDni[9];
    char auxEdad[4];
    int carga;
    char seguir;

    do
    {
        getString("Ingrse el nombre: ",auxNombre);
        carga=esSoloLetras(auxNombre);
        if(!(carga))
        {
            printf("Ha ingresado caracteres invalidos para un nombre.\n");
            seguir=getChar("Desea reintentar?");
        }
    }
    while(carga!=1 && seguir == 's');

    if(carga==1)
    {
        do
        {
            getString("Ingrse el DNI: ",auxDni);
            carga=esNumeroChar(auxDni);
            if(!(carga)|| (strlen(auxDni)!=8))
            {
                printf("Debe ingresar un DNI valdo.");
                seguir=getChar("Desea reintentar?");
            }
            else if(buscarPorDni(listaPersona,cantidadDePersonas,auxDni)!=-1)
            {
             printf("Este DNI ya se encuentra cargado en el sistema.\n");
             carga=0;
             seguir=getChar("Desea reintentar?");
            }
        }
        while((carga!=1 ||(strlen(auxDni)!=8))&& seguir == 's');
    }

    if(carga==1)
    {
        do
        {
            getString("Ingrese la edad: ",auxEdad);
            carga=esNumeroChar(auxEdad);
            if(!(carga)|| atoi(auxEdad) > 150)
            {
                printf("Debe ingresar una edad valda.");
                seguir=getChar("Desea reintentar?");
            }
        }
        while((carga!=1 && seguir == 's') || atoi(auxEdad) > 150);
    }

    if(carga==1)
    {
        strcpy(listaPersona[index].dni,auxDni);
        strcpy(listaPersona[index].edad,auxEdad);
        strcpy(listaPersona[index].nombre,auxNombre);
        listaPersona[index].estado=1;
    }
}
int buscarIndiceVacio(EPersona listaPersonas[], int cantidad)
{
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(listaPersonas[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}
