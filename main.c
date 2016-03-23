#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0, flagA = 0, flagB = 0;
    float a = 0, b = 0;
    double aux;

    while(seguir == 's')
    {
        printf("1- Ingresar 1er operando (A = %.2f)\n", a);
        printf("2- Ingresar 2do operando (B = %.2f)\n", b);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\nOpcion: ");

        scanf("%d",&opcion);

        system("cls");

        switch(opcion)
        {
            case 1:

                a = getValue();
                flagA = 1;

                break;

            case 2:

                b = getValue();
                flagB = 1;

                break;

            case 3:

                if ((flagA == 1) && (flagB == 1))
                    printf("La suma entre %.2f y %.2f es: %.2f\n\n", a, b, sumar(a,b));
                else
                    printf("Ingrese valores de A y B para realizar la operacion\n\n");

                break;

            case 4:

                if ((flagA == 1) && (flagB == 1))
                    printf("La resta entre %.2f y %.2f es: %.2f\n\n", a, b, restar(a,b));
                else
                    printf("Ingrese valores de A y B para realizar la operacion\n\n");

                break;

            case 5:

                if ((flagA == 1) && (flagB == 1))
                {
                    /**< Para el caso que el divisor sea 0 */
                    if (b == 0)
                        printf("No se puede dividir por 0. Por favor, cambie el valor de B.\n\n");
                    else
                        printf("La division entre %.2f y %.2f es: %.2f\n\n", a, b, dividir(a,b));
                }
                else
                    printf("Ingrese valores de A y B para realizar la operacion\n\n");

                break;

            case 6:

                if ((flagA == 1) && (flagB == 1))
                    printf("La multiplicacion entre %.2f y %.2f es: %.2f\n\n", a, b, multiplicar(a,b));
                else
                    printf("Ingrese valores de A y B para realizar la operacion\n\n");

                break;

            case 7:

                if (flagA == 1)
                {
                    /**< Primero lo paso a int para sacarle la parte decimal */
                    aux = (double)(int)a;

                    printf("Para calcular el factorial, se tomara solo la parte entera del numero.\n");
                    printf("El factorial de %.0f es: %.0f\n\n", aux, getFactorial(aux));
                }
                else
                    printf("Ingrese valor de A para realizar la operacion\n\n");

                break;

            case 8:

                /**< Al separar el if, puedo realizar el factorial en caso de que haya cargado A */
                if (flagA == 1)
                {
                    /**< Primero lo paso a int para sacarle la parte decimal */
                    aux = (double)(int)a;

                    printf("Para calcular el factorial, se tomara solo la parte entera del numero.\n");
                    printf("El factorial de %.0f es: %.0f\n\n", aux, getFactorial(aux));

                    /**< Si tambien cargó B, realiza el resto de las operaciones */
                    if (flagB == 1)
                    {
                        printf("La suma entre %.2f y %.2f es: %.2f\n\n", a, b, sumar(a,b));
                        printf("La resta entre %.2f y %.2f es: %.2f\n\n", a, b, restar(a,b));

                        /**< Para el caso que el divisor sea 0 */
                        if (b == 0)
                            printf("No se puede dividir por 0. Por favor, cambie el valor de B.\n\n");
                        else
                            printf("La division entre %.2f y %.2f es: %.2f\n\n", a, b, dividir(a,b));

                        printf("La multiplicacion entre %.2f y %.2f es: %.2f\n\n", a, b, multiplicar(a,b));
                    }
                    else
                        printf("Ingrese valor de B para realizar el resto de las operaciones\n\n");
                }
                else
                    printf("Ingrese valores de A y B para realizar las operaciones\n\n");

                break;

            case 9:

                seguir = 'n';
                printf("FIN DEL PROGRAMA\n");
                printf("Hecho por Agustin Prado - 2016\n");

                break;
        }

    }
    return 0;
}
