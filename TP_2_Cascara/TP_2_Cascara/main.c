#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "utn.h"
#include "funciones.h"
int main()
{
    EPersona listaPersonas[CANTPERS];
    char auxiliarChar[50];
    int index,blankIndex;
    char seguir='s';
    int opcion=0;
    inicializarListaDePersonas(listaPersonas,CANTPERS,0);
    do
    {
        marco();
        printf("ALTA Y BAJA DE DATOS PERSONALES.\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            marco();
            blankIndex = buscarIndiceVacio(listaPersonas,CANTPERS);
            cargarDatosPersonales(listaPersonas,CANTPERS,blankIndex);
            break;
        case 2:
            marco();
            getNumerosChar(auxiliarChar,"\nIngrese el DNI que desea eliminar.\n");
            index = buscarPorDni(listaPersonas,CANTPERS,auxiliarChar);
            if(index!=-1)
            {
                listaPersonas[index].estado=0;
                printf("Usuario borrado!");
            }
            else
                printf("Error DNI invalido!");
            break;
        case 3:
            marco();
            imprimirListaPorNombre(listaPersonas,CANTPERS);
            break;
        case 4:
            marco();
            printf("ESTADISTICA DE RANGOS ETARIOS:\n\n\n");
            imprimirGraficoEdades(listaPersonas,CANTPERS);
            break;
        case 5:
            seguir='n';
            break;
        }
        cualquierTeclaContinnuar();
        system("cls");
    }while(seguir=='s');
    return 0;
}
