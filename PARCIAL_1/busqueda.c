#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define CANTPERS 20
#include "validaciones.h"
#include "cargaYEdicion.h"
#include "edicionArrays.h"
#include "busqueda.h"

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndicePorId(E_Usuario listaPersonas[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdUsuario(listaPersonas,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}

/**
 * \brief Obtiene el indice del ID
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param mensaje, texto para solicitar el ID
 * \param mensajeError, texto si el dato es invalido
 * \param mensajeNoEncontrado, texto si no se encontro el ID
 * \return indice del ID encontrado
 *
 */

int obtenerIndiceLlamadaPorId(E_Productos listaProductos[],int cantidad,char mensaje[], char mensajeError[],char mensajeNoEncontrado[])
{
    int indiceId=-1;
    char id[5];
    char continuar;
    do
    {
        if(cargarNumero(id,mensaje,mensajeError,0,999))
        {
            indiceId = buscarPorIdProductos(listaProductos,cantidad,atoi(id));
            if(indiceId==-1)
            {
                printf("%s",mensajeNoEncontrado);
                continuar=getChar("\nDesea continuar? s/n");
            }
        }
    }
    while(indiceId==-1 && continuar=='s');
    return indiceId;
}

/**
 * \brief busca el DNI
 * \param recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param dni, dato a buscar
 * \return -1 si no se encontro el dato o indice del dato encontrado
 *
 */

int buscarPorDni(E_Usuario lista[], int cantidad,char dni[])
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if(strcmp(lista[i].dni,dni)==0)
            retorno=i;
    }
    return retorno;
}


/**
 * \brief busca el primer espacio libre
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param si se encuentra ocupado o no
 * \return -1 si no hay espacio libre o indice libre
 *
 */

int obtenerEspacioLibreLlamadas(E_Productos lista[], int cantidad_elementos, int precio)
{
    int i;
    int retorno=-1;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].isEmpty==precio)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param si se encuentra ocupado o no
 * \return -1 si no hay espacio libre o indice libre
 *
 */

int obtenerEspacioLibre(E_Usuario lista[], int cantidad_elementos, int precio)
{
    int i;
    for(i=0; i < cantidad_elementos; i++)
    {
        if(lista[i].isEmpty==precio)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Obtiene el usuario con mayor cantidad de llamadas realizadas
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param indice de usuarios con mayor cantidad de llamadas
 * \return 0 si hubo error 1 si esta todo ok
 *
 */

int usuarioConMayorCantidadDeLlamadas (E_Productos listaProductos[],int cantComent,E_Usuario listaUsuar[],int cantUsuar,int usuarConMasMensajes[])
{
    int retorno=0;
    int maximo=0;
    int contador;
    int i;
    int j;
    int k=0;
    inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
    for(i=0; i<cantUsuar; i++)
    {
        if(listaUsuar[i].isEmpty==1)
        {
            continue;
        }
        contador=0;
        for(j=0; j<cantComent; j++)
        {
            if(listaProductos[j].isEmpty==0 && listaProductos[j].idUsuario==listaUsuar[i].id)
            {
                contador++;

            }
        }
        if(contador>maximo)
        {
            k=0;
            inicializarArrayDeIndices(usuarConMasMensajes,cantUsuar,-1);
            usuarConMasMensajes[k]=i;
            maximo=contador;
            retorno = 1;

        }
        else if(contador==maximo)
        {
            k++;
            usuarConMasMensajes[k]=i;
        }

    }
    return retorno;
}
/**
 * \brief Obtiene id
 * \param recibe array de llamadas
 * \param cantidad,cantidad de subindices
 * \param dato a comparar
 * \return indice o -1 si no se encontro el id
 *
 */

int buscarPorIdProductos(E_Productos lista[], int cantidad,int idComentario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idComentario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

/**
 * \brief Obtiene el nombreProducto más elegido
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param indice de nombreProductos más elegidos
 * \return
 *
 */

void nombreProductoMasRepetido (E_Productos lista[],int cantidad,EMotivo nombreProducto[],int nombreProductosMasRepetidos[])
{
    int contador[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0)
        {
            if(strcmp(lista[i].nombreProducto,nombreProducto[0].tipo)==0)
            {
                contador[0]++;
            }
            else if(strcmp(lista[i].nombreProducto,nombreProducto[1].tipo)==0)
            {
                contador[1]++;
            }
            else
            {
                contador[2]++;
            }
        }
    }

    for(i=0; i<3; i++)
    {
        if(contador[i]>maximo)
        {
            inicializarArrayDeIndices(nombreProductosMasRepetidos,3,0);
            nombreProductosMasRepetidos[i]=1;
            maximo=contador[i];
        }
        else if(contador[i]==maximo)
        {
            nombreProductosMasRepetidos[i]=1;
        }
    }
}

/**
 * \brief Obtiene el nombreProducto con más tiempo en linea
 * \param lista el array se pasa como parametro.
 * \param cantidad de subindices
 * \param lista el array se pasa como parametro.
 * \param indice de nombreProductos con más tiempo en linea
 * \return
 *
 */
/*void nombreProductoMasDemoraEnPromedio (E_Productos lista[],int cantidad,EMotivo nombreProducto[],int nombreProductosMasDemorados[])
{
    int contador[3]= {0,0,0};
    int acumulador[3]= {0,0,0};
    int promedio[3]= {0,0,0};
    int maximo=0;
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].isEmpty==0 && stricmp(lista[i].precio,"CUMPLIDO")==0))
        {
            if(strcmp(lista[i].nombreProducto,nombreProducto[0].tipo)==0)
            {
                contador[0]++;
                acumulador[0]=acumulador[0]+lista[i].duracion;

            }
            else if(strcmp(lista[i].nombreProducto,nombreProducto[1].tipo)==0)
            {
                contador[1]++;
                acumulador[1]=acumulador[1]+lista[i].duracion;
            }
            else
            {
                contador[2]++;
                acumulador[2]=acumulador[2]+lista[i].duracion;
            }
        }
    }
    for(i=0; i<3; i++)
    {
        if(contador[i]>0)
        {
            promedio[i]=(acumulador[i]/contador[i]);
        }

    }


    for(i=0; i<3; i++)
    {
        if(promedio[i]>maximo)
        {
            inicializarArrayDeIndices(nombreProductosMasDemorados,3,0);
        nombreProductosMasDemorados[i]=1;
            maximo=promedio[i];

        }
        else if(promedio[i]==maximo)
        {
            nombreProductosMasDemorados[i]=1;
        }
    }
}*/

/**
 * \brief Obtiene el indice del ID
 * \param listaPersonas recibe array de personas
 * \param cantidad,cantidad de subindices
 * \param id a comparar
 * \return indice del ID encontrado o -1 si no se encuentra
 *
 */

int buscarPorIdUsuario(E_Usuario lista[], int cantidad,int idUsuario)
{
    int retorno=-1;
    int i;
    for(i=0; i<cantidad; i++)
    {
        if((idUsuario==lista[i].id) && lista[i].isEmpty==0)
        {
            retorno=i;
            break;
        }

    }

    return retorno;
}


void buscarProductoPorIdUsuario(E_Productos lista[], int cantidadDeProductos,int idUsuario, int listaProductosUsuario[])
{
    //int retorno=0;
    int i,j=0;
    inicializarArrayDeIndices(listaProductosUsuario,cantidadDeProductos,-1);
    for(i=0; i<cantidadDeProductos; i++)
    {
        if((idUsuario==lista[i].idUsuario) && lista[i].isEmpty==0)
        {
            listaProductosUsuario[j]=i;
            j++;
            //retorno=1;
        }

    }

  //  return retorno;
}

/*int usuarioMayorEdad (E_Usuario lista[],int cantidad,int listaUsuariosMayorEdad[])
{
    int retorno =0;
    int i,j;
    int maximo=0;
    for(i=0; i<cantidad; i++)
    {

        if(lista[i].isEmpty==0 && lista[i].calificacion>maximo)
        {
            j=0;
            inicializarArrayDeIndices(listaUsuariosMayorEdad,cantidad,-1);
            listaUsuariosMayorEdad[j]=i;
            maximo=auxiliarEdad;
            retorno =1;
        }
        else if(lista[i].isEmpty==0 && auxiliarEdad==maximo)
        {
            j++;
            listaUsuariosMayorEdad[j]=i;
        }
    }
    return retorno;
}*/






