#include <stdio.h>
#include <stdlib.h>

/** \brief Recibe dos valores y los suma
 *
 * \param Primer sumando
 * \param Segundo sumando
 * \return Suma de la operación
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
 * \return Diferencia de la operación
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
 * \return Cociente de la operación
 *
 */
float dividir(float a, float b)
{
    return a / b;
}

/** \brief Recibe dos elementos y los multiplica
 *
 * \param Primer múltiplo
 * \param Segundo múltiplo
 * \return Producto de la operación
 *
 */
float multiplicar(float a, float b)
{
    return a * b;
}

/** \brief Calcula el factorial del número ingresado, tomando solo su parte entera
 *
 * \param Número a calcularle el factorial
 * \return Factorial del número ingresado
 *
 */

double getFactorial (double a)
{
    double factorial;

    /**< Por convención, el factorial de 0 y 1 es 1 */
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
