/*******************************************************************
*Programa:PARCIAL
*
*Nombre: Boullon Demian.
*
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "lib.h"
#include "busqueda.h"

#define CANT 100
#define CANTIDADPRODUCTOS 1000


int main()
{
    char seguir='s';
    int opcion=0;
    E_Usuario listaPersonas[CANT];
    E_Productos listaProductos[CANTIDADPRODUCTOS];

    int generadorID=4;
    int generadorIdLlamadas=0;
    int afiliadosConMasLlamadas[CANT];
    int i,j;
    int indiceId;
    float acumuladorCalificaciones=0;
    float promedio;
    int contador;

    inicializarListaDePersonas(listaPersonas,CANT,1);
    inicializarListaDeProductos(listaProductos,CANTIDADPRODUCTOS,1);
    inicializarArrayDeIndices(afiliadosConMasLlamadas,CANT,-1);



    //-----------------------------------------------------------------------------------------------------------------
    strcpy(listaPersonas[0].nombre,"ZZ");
    strcpy(listaPersonas[0].pasword,"BBB");
    listaPersonas[0].isEmpty=0;
    listaPersonas[0].id=0;

    strcpy(listaPersonas[1].nombre,"ZZ");
    strcpy(listaPersonas[1].pasword,"AAA");
    listaPersonas[1].isEmpty=0;
    listaPersonas[1].id=1;
    listaPersonas[1].calificacion[0]=8;
    listaPersonas[1].calificacion[1]=2;
    listaPersonas[1].calificacion[2]=-1;

    strcpy(listaPersonas[2].nombre,"AA");
    strcpy(listaPersonas[2].pasword,"ZZZ");
    listaPersonas[2].isEmpty=0;
    listaPersonas[2].id=2;
    listaPersonas[2].calificacion[0]=-1;


    strcpy(listaPersonas[3].nombre,"AA");
    strcpy(listaPersonas[3].pasword,"SSS");
    listaPersonas[3].isEmpty=0;
    listaPersonas[3].id=2;
    listaPersonas[3].calificacion[0]=5;
    listaPersonas[3].calificacion[1]=-1;

    listaProductos[0].duracion=50;
    listaProductos[0].id=0;
    listaProductos[0].idUsuario=0;
    listaProductos[0].stock=50;
    strcpy(listaProductos[0].nombreProducto,"Bicicleta");
    listaProductos[0].precio=40;
    listaProductos[0].isEmpty=0;

    listaProductos[1].id=1;
    listaProductos[1].idUsuario=0;
    strcpy(listaProductos[1].nombreProducto,"Xbox");
    listaProductos[1].precio=45;
    listaProductos[1].isEmpty=0;
    listaProductos[1].stock=20;

    listaProductos[2].duracion=40;
    listaProductos[2].id=0;
    listaProductos[2].stock=0;
    listaProductos[2].idUsuario=1;
    strcpy(listaProductos[2].nombreProducto,"GameBoy");
    listaProductos[2].precio=58;
    listaProductos[2].isEmpty=0;


    listaProductos[3].duracion=45;
    listaProductos[3].id=0;
    listaProductos[3].stock=0;
    listaProductos[3].idUsuario=2;
    strcpy(listaProductos[3].nombreProducto,"Play");
    listaProductos[3].precio=77;
    listaProductos[3].isEmpty=0;

//--------------------------------------------------------------------------------*/

    do
    {

        printf("SERVICIO DE ASISTENCIA MEDICA.\n\n");
        printf("1- ALTA DEL USUARIO.\n");
        printf("2- MODIFICAR DATOS DEL USUARIO.\n");
        printf("3- BAJA DEL USUARIO:.\n");
        printf("4- NUEVA PUBLICACION.\n");
        printf("5- MODIFICAR DATOS DE PUBLICACION.\n");
        printf("6- CANCELAR PUBLICACION.\n");
        printf("7- COMPRAR PRODUCTO.\n");
        printf("8- LISTAR PUBLICACIONES DE USUARIO.\n");
        printf("9- GRAFICO EDAD.\n");
        printf("10- LISTAR USUARIOS.\n");
        fflush(stdin);
        opcion=getInt("\nElija una opcion: ");

        switch(opcion)
        {
        case 1:
            if(alta(listaPersonas,CANT,generadorID))
            {
                generadorID++;
            }
            break;
        case 2:
            modificar (listaPersonas,CANT,"Ingrese ID del afiliado a modificar","\nId erroneo.\n","ID no encontrado");

            break;
        case 3:
            baja(listaPersonas,CANT,listaProductos,1000,"Ingrese ID para la baja","Error","ID no encontrado");

            break;
        case 4:
            nuevaPublicacion(listaPersonas,CANT,listaProductos,CANTIDADPRODUCTOS,generadorIdLlamadas);
            break;
        case 5:
            modificarPublicacion(listaPersonas,CANT,listaProductos,1000,"Ingrese ID de usuario","Error","ID no encontrado");
            break;
        case 6:
            cancelarPublicacion(listaPersonas,CANT,listaProductos,1000,"Ingrese ID de usuario","Error","ID no encontrado");
            break;
        case 7:
            nuevaCompra(listaPersonas,CANT,listaProductos, CANTIDADPRODUCTOS);
            break;

        case 8:
            listarPublicacionesDeUsuarios(listaPersonas,CANT,listaProductos,CANTIDADPRODUCTOS,"\nIngrece ID de usuario: ","\nERROR\n","ID NO ENCONTRADO");
            break;
        case 9:
            system("cls");

            printf("NombreProducto\tID\tPrecio\tCantidad vendida\tStock\tUsuario\n\n");
            for(i=0; i<CANT; i++)
            {

                if(listaProductos[i].isEmpty==0)
                {
                    printf("%s\t",listaProductos[i].nombreProducto);
                    printf("%d\t",listaProductos[i].id);
                    printf("%f\t",listaProductos[i].precio);
                    printf("%d\t",listaProductos[i].vendidos);
                    printf("%d\t",listaProductos[i].stock);
                    indiceId=buscarPorIdUsuario(listaPersonas,CANT,listaProductos[i].idUsuario);
                    printf("%s\n\n",listaPersonas[indiceId].nombre);
                }
            }
            printf("\n\n");

            break;

        case 10:
            printf("Nombre \t CalificacionPromedio\n\n");
            for(i=0; i<CANT; i++)
            {

                if(listaPersonas[i].isEmpty==0)
                {
                    printf("%s \t",listaPersonas[i].nombre);

                    for(j=0; j<10; j++)
                    {
                        if(listaPersonas[i].calificacion[j]!=-1)
                        {
                            contador=0;
                            acumuladorCalificaciones=listaPersonas[i].calificacion[j]+acumuladorCalificaciones;
                            contador++;
                        }
                        else
                        {
                            break;
                        }

                    }
                    promedio=acumuladorCalificaciones/contador;
                    printf(" %.2f\n",promedio);
                }
            }
            break;
        default :
            printf("Opcion incorrecta.\n");
            system("cls");
            break;
        }

    }
    while(seguir=='s');

    return 0;
}
