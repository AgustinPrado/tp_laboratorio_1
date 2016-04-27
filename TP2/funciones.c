#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Valida si el usuario desea continuar en un bucle
 *
 * \return Devuelve 1 si el usuario sigue y 0 si no desea seguir
 *
 */
int validaS_N (void)
{
    char charValid;
    int intValid;

    printf("Desea seguir S/N?: ");
    fflush(stdin);
    scanf("%c", &charValid);
    charValid = toupper(charValid);

    while((charValid != 'S' ) && (charValid != 'N'))
    {
        printf("Por favor, ingrese solamente 'S' o 'N'.\n");
        printf("Desea seguir S/N?: ");
        fflush(stdin);
        scanf("%c", &charValid);
        charValid = toupper(charValid);
    }

    if (charValid == 'S')
    {
        intValid = 1;
    }
    else
    {
        intValid = 0;
    }

    return intValid;
}

/** \brief Realiza una busqueda ordenada y devuelve la posicion en la que lo encuentra
 *
 * \param valor valor a buscar
 * \param vec Vector donde se busca
 * \param lengthVector Longitud del vector
 * \return Devuelve la posicion o -1 si no lo encuentra
 *
 */
int buscOrd (int valor, int vec[], int lengthVector)
{
    int i;

    for(i = 0; i < lengthVector; i++)
    {
        if(valor == vec[i])    /**< Cuando encuentro el valor */
        {
            return i;
        }
    }

    return -1;
}

/**
 * \brief Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[])
{
    int i;
    for(i = 0; i < CANT_ELEMENTOS; i++)
    {
        if(lista[i].estado == 0)
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista el array se pasa como parametro.
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
long int buscarPorDni(EPersona lista[], long int dni)
{
    int i;
    for(i = 0; i < CANT_ELEMENTOS; i++)
    {
        if((lista[i].dni == dni) && (lista[i].estado != 0))
        {
            return i;
        }
    }
    return -1;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int aux;
    printf("%s", mensaje);
    scanf("%d", &aux);
    return aux;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido sea float
 * \param str Array con la cadena a ser analizada
 * \return 1 si es float y 0 si no lo es
 *
 */
int esFloat(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9') && str[i] != '.')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo float
 */
int getStringFloat(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esFloat(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Inicializa un array de enteros con el valor recibido
 * \param lista Es el array a ser inicializado
 * \return
 *
 */
void inicializarArrayPersona(EPersona lista[])
{
    int i;
    for(i = 0;i < CANT_ELEMENTOS; i++)
    {
        lista[i].estado = 0;
    }
    return;
}

/** \brief Realiza todos los pasos para agregar una persona al vector
 *
 * \param persona Vector de estructura que uso en todo el programa
 * \return
 *
 */
void agregarPersona(EPersona persona[])
{
    char auxNombreStr[50], auxDNIStr[15], auxEdadStr[3];
    int indiceEspacioLibre, auxEdad, indiceBusquedaDNI;
    long int auxDNI;

    /**< ESPACIO LIBRE */
    indiceEspacioLibre = obtenerEspacioLibre(persona);/**< Calculo si hay lugares libres. */
    if(indiceEspacioLibre == -1)
    {
        recuadroStr("No hay lugares libre. Borre alguna persona para poder ingresar otra.");
        return;
    }

    /**< NOMBRE */
    if(!getStringLetras("Ingrese el nombre y apellido: ", auxNombreStr))/**< Verifica que sean solo letras lo que se ingresa. */
    {
        recuadroStr("El nombre y apellido no puede contener caracteres que no sean letras.");
        return;
    }
    if(strlen(auxNombreStr) > (LARGO_NOMBRE - 1))
    {
        recuadroStr("El nombre y apellido no pueden ser mas largos que 20 caracteres.");
        return;
    }

    /**< EDAD */
    if(!getStringNumeros("Ingrese la edad: ",auxEdadStr))/**< Verifica que sean solo numeros lo que se ingresa. */
    {
        recuadroStr("La edad no puede contener caracteres que no sean numeros.");
        return;
    }
    auxEdad = atoi(auxEdadStr);

    if((auxEdad < 0) || (auxEdad > 120))/**< Valido que la edad sea mayor a 0 y menor a 120 */
    {
        recuadroStr("La edad no puede ser menor a 0 ni mayor a 120.");
        return;
    }

    /**< DNI */
    if(!getStringNumeros("Ingrese el DNI: ",auxDNIStr))/**< Verifica que sean solo numeros lo que se ingresa. */
    {
        recuadroStr("El DNI no puede contener caracteres que no sean numeros.");
        return;
    }
    auxDNI = atoi(auxDNIStr);

    if((auxDNI < 1000000) || (auxDNI > 100000000))/**< Valido que el DNI sea mayor a 1.000.000 y menor que 100.000.000 */
    {
        recuadroStr("El DNI no puede ser menor a 1.000.000 ni mayor que 100.000.000");
        return;
    }

    indiceBusquedaDNI = buscarPorDni(persona,auxDNI);/**< Busco ese DNI y me devuelve el indice */

    if(indiceBusquedaDNI != -1)/**< Si es distinto a -1 significa que ya hay una persona con ese DNI */
    {
        recuadroStr("Ya hay una persona con ese DNI.");
        return;
    }

    /**< CARGO DATOS */
    /**< Si llego hasta esta parte, significa que no hubo ningun error.*/
    /**< Paso de las variables auxiliares a mi vector de estructura. */
    strcpy(persona[indiceEspacioLibre].nombre, auxNombreStr);
    persona[indiceEspacioLibre].edad = auxEdad;
    persona[indiceEspacioLibre].dni = auxDNI;
    persona[indiceEspacioLibre].estado = 1;/**< Cambio el estado a 1 para representar que esta ocupado */
    recuadroStr("Persona agregada exitosamente.");
    return;
}

/** \brief Realiza todos los pasos para borrar logicamente a una persona del vector
 *
 * \param persona Vector de estructura que uso en todo el programa
 * \return
 *
 */
void borrarPersona(EPersona persona[])
{
    char auxDNIStr[15];
    int indiceBusquedaDNI;

    if(obtenerEspacioLibre(persona) == 0)/**< Calculo si hay algun elemento en el vector. */
    {
        recuadroStr("No hay ninguna persona cargada.");
        return;
    }

    printf("\nBorrar persona\n");
    if(!getStringNumeros("Ingrese el DNI de la persona a borrar: ",auxDNIStr))/**< Verifica que sean solo numeros lo que se ingresa. */
    {
        recuadroStr("El DNI no puede contener caracteres que no sean numeros.");
        return;
    }
    indiceBusquedaDNI = buscarPorDni(persona,atoi(auxDNIStr));/**< Busco ese DNI y me devuelve el indice */

    if(indiceBusquedaDNI == -1)/**< Si es -1 significa que no lo encontro */
    {
        recuadroStr("No se encuentra una persona con ese DNI");
        return;
    }

    /**< Si llego hasta aca, significa que no hubo errores y que encontro el DNI */
    persona[indiceBusquedaDNI].estado = 0;/**< Le cambio el estado a 0, representando que lo borra logicamente */
    recuadroStr("Persona borrada exitosamente.");
    return;
}

/** \brief Realiza todos los pasos para ordenar el vector por nombre
 *
 * \param persona Vector de estructura que uso en todo el programa
 * \return
 *
 */
void listaOrdenada(EPersona persona[])
{
    int i, j;
    EPersona auxPersona;

    if(obtenerEspacioLibre(persona) == 0)/**< Calculo si hay algun elemento en el vector. */
    {
        recuadroStr("No hay ninguna persona cargada.");
        return;
    }

    recuadroStr("Lista ordenada por nombre");

    for(i = 0; i < CANT_ELEMENTOS - 1; i++)
    {
        if(persona[i].estado == 0)/**< Cuando el estado es 0, significa que esta borrado logicamente y no lo quiero ordenar */
        {
            continue;/**< De esta manera, continuo con el siguiente paso del for */
        }
        for(j = i + 1; j < CANT_ELEMENTOS; j++)
        {
            if(persona[j].estado == 0)/**< Cuando el estado es 0, significa que esta borrado logicamente y no lo quiero ordenar */
            {
                continue;/**< De esta manera, continuo con el siguiente paso del for */
            }
            if(strcmp(persona[i].nombre,persona[j].nombre) > 0)
            {
                auxPersona = persona[i];
                persona[i] = persona[j];
                persona[j] = auxPersona;
            }
        }
    }

    printf("Nombre\t\t\tEdad\tDNI\n");
    printf("=========================================\n");
    for(i = 0; i < CANT_ELEMENTOS; i++)
    {
        if(persona[i].estado != 0)/**< Para que no me lo muestre si esta borrado logicamente */
        {
            printf("%-20s\t %d\t%ld\n",persona[i].nombre,persona[i].edad,persona[i].dni);
        }
    }
}

/** \brief Realiza todos los pasos para generar un grafico por edades
 *
 * \param persona Vector de estructura que uso en todo el programa
 * \return
 *
 */
void graficoEdad(EPersona persona[])
{
    char grafico[CANT_ELEMENTOS][3];
    int i, j, contMen18 = 0, cont19a35 = 0, contMay35 = 0;

    if(obtenerEspacioLibre(persona) == 0)/**< Calculo si hay algun elemento en el vector. */
    {
        recuadroStr("No hay ninguna persona cargada.");
        return;
    }

    for(i = 0; i < CANT_ELEMENTOS; i++)/**< Aprovecho el mismo for para inicializar el grafico y contar las edades */
    {
        for(j = 0; j < 3; j++)
        {
            grafico[i][j] = ' ';/**< Cargo el grafico con espacios ' ' */
        }

        if(persona[i].estado == 0)/**< Cuando el estado es 0, significa que esta borrado logicamente y no lo quiero contar */
        {
            continue;/**< De esta manera, continuo con el siguiente paso del for */
        }

        /**< Cuento cada rango de edad */
        if(persona[i].edad < 18)
        {
            contMen18++;
        }
        else
        {
            if(persona[i].edad > 35)
            {
                contMay35++;
            }
            else
            {
                cont19a35++;
            }
        }
    }

    /**< Cargo mi grafico */
    for(i = CANT_ELEMENTOS - 1; i >= 0; i--)
    {
        if(contMen18 > 0)
        {
            grafico[i][0] = '*';
            contMen18--;
        }
        if(cont19a35 > 0)
        {
            grafico[i][1] = '*';
            cont19a35--;
        }
        if(contMay35 > 0)
        {
            grafico[i][2] = '*';
            contMay35--;
        }
    }

    recuadroStr("GRAFICO");
    printf("\n");
    for(i = 0; i < CANT_ELEMENTOS; i++)
    {
        if((grafico[i][0] == ' ') && (grafico[i][1] == ' ') && (grafico[i][2] == ' '))/**< Si no hay un *, que siga de largo con el sig elemento */
        {
            continue;
        }
        printf("%c\t%c\t%c\n", grafico[i][0], grafico[i][1], grafico[i][2]);
    }
    printf("<18\t19-35\t>35\n\n");
}

/** \brief Muestra una cadena de caracteres con un recuadro
 *
 * \param cadena La cadena a mostrar
 * \return
 *
 */
void recuadroStr(char cadena[])
{
    int length = strlen(cadena), i;

    printf("\n\n");
    for(i = 0; i < (length + 4); i++)
    {
        printf("-");
    }
    printf("\n| %s |", cadena);
    printf("\n");
    for(i = 0; i < (length + 4); i++)
    {
        printf("-");
    }
    printf("\n");
    return;
}
