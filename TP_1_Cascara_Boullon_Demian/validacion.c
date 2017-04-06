#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validacion.h"

/*
* \brief   valida si un valor es entero, guardando el valor como entero en un auxiliar y restando el original (flotante).
* \param   numero valor que será validado.
* \return  Un "1" si el valor es entero o un "0" si no.
*/
int validarEntero(float numero)
{
    if(numero<0)
    {
        return 0;
    }
    else
    {
        int ent=(int)numero;

        if(numero-ent==0)
          {
            return 1;
          }
          else
          {
            return 0;
          }
    }
}
