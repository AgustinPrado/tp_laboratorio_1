#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
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
                break;

            case 2:

                b = getValue();
                break;

            case 3:

                printf("La suma entre %.2f y %.2f es: %.2f\n\n", a, b, sumar(a,b));
                break;

            case 4:

                printf("La resta entre %.2f y %.2f es: %.2f\n\n", a, b, restar(a,b));
                break;

            case 5:

                /**< Para el caso que el divisor sea 0 */
                if (b == 0)
                    printf("No se puede dividir por 0. Por favor, cambie el valor de B.\n\n");
                else
                    printf("La division entre %.2f y %.2f es: %.2f\n\n", a, b, dividir(a,b));
                break;

            case 6:

                printf("La multiplicacion entre %.2f y %.2f es: %.2f\n\n", a, b, multiplicar(a,b));
                break;

            case 7:

                /**< Primero lo paso a int para sacarle la parte decimal */
                aux = (double)(int)a;

                printf("Para calcular el factorial, se tomara solo la parte entera del numero.\n");
                printf("El factorial de %.0f es: %.0f\n\n", aux, getFactorial(aux));

                break;

            case 8:

                printf("La suma entre %.2f y %.2f es: %.2f\n\n", a, b, sumar(a,b));
                printf("La resta entre %.2f y %.2f es: %.2f\n\n", a, b, restar(a,b));

                if (b == 0)
                    printf("No se puede dividir por 0. Por favor, cambie el valor de B.\n\n");
                else
                    printf("La division entre %.2f y %.2f es: %.2f\n\n", a, b, dividir(a,b));

                printf("La multiplicacion entre %.2f y %.2f es: %.2f\n\n", a, b, multiplicar(a,b));

                /**< Primero lo paso a int para sacarle la parte decimal */
                aux = (double)(int)a;

                printf("Para calcular el factorial, se tomara solo la parte entera del numero.\n");
                printf("El factorial de %.0f es: %.0f\n\n", aux, getFactorial(aux));

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
