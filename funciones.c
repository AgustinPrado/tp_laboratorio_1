#include <stdio.h>
#include <stdlib.h>

/** \brief Recibe dos valores y los suma
 *
 * \param Primer sumando
 * \param Segundo sumando
 * \return Suma de la operaci�n
 *
 */
float sumar(float a, float b)
{
    return a + b;
}

/** \brief Recibe dos valores y los resta
 *
 * \param Minuendo
 * \param Sustraendo
 * \return Diferencia de la operaci�n
 *
 */
float restar(float a, float b)
{
    return a - b;
}

/** \brief Recibe dos valores y los divide
 *
 * \param Dividendo
 * \param Divisor
 * \return Cociente de la operaci�n
 *
 */
float dividir(float a, float b)
{
    return a / b;
}

/** \brief Recibe dos elementos y los multiplica
 *
 * \param Primer m�ltiplo
 * \param Segundo m�ltiplo
 * \return Producto de la operaci�n
 *
 */
float multiplicar(float a, float b)
{
    return a * b;
}

/** \brief Calcula el factorial del n�mero ingresado, tomando solo su parte entera
 *
 * \param N�mero a calcularle el factorial
 * \return Factorial del n�mero ingresado
 *
 */

double getFactorial (double a)
{
    double factorial;

    /**< Por convenci�n, el factorial de 0 y 1 es 1 */
    if ((a == 0) || (a == 1))
        factorial = 1;
    else
        factorial = a * getFactorial(a - 1);

    return factorial;
}

/** \brief Pide al usuario que ingrese un valor
 *
 * \return Devuelve el valor ingresado por el usuario
 *
 */
float getValue ()
{
    float aux;

    printf("Ingrese un valor: ");
    scanf("%f",&aux);

    return aux;
}
