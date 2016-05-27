#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;

    while(seguir == 's')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                agregar();
                break;
            case 2:
                borrar();
                break;
            case 3:
                modificar();
                break;
            case 4:
                generar();
                break;
            case 5:
                seguir = 'n';
                recuadroStr("FIN DEL PROGRAMA");
                recuadroStr("Hecho por Agustin Prado - 2016");
                break;
            default:
                printf("\nPor favor, ingrese una opcion correcta.\n");
        }
    }

    return 0;
}
