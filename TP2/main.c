#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    EPersona persona[CANT_ELEMENTOS];

    inicializarArrayPersona(persona);

    while(seguir == 's')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarPersona(persona);
                break;
            case 2:
                borrarPersona(persona);
                break;
            case 3:
                listaOrdenada(persona);
                break;
            case 4:
                graficoEdad(persona);
                break;
            case 5:
                seguir = 'n';
                recuadroStr("FIN DEL PROGRAMA");
                recuadroStr("Hecho por Agustin Prado - 2016");
                break;
        }
    }

    return 0;
}
