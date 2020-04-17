#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


#endif // FUNCIONES_H_INCLUDED

/** \brief Primer menu de opciones
*
* \
* \
* \return Devuelve la opción elegida
*/
int menu();


/** \brief Segundo menu de opciones
*
* \ Incluye el primer numero ingresado (a)
* \
* \return Devuelve una opción elegida
*/
int menuA(int a);


/** \brief Tercer menu de opciones
*
* \ Incluye el primer numero ingresado (a)
* \ Incluye el segundo numero ingresado (b)
* \return Devuelve una opción elegida
*/
int menuB(int a, int b);


/** \brief Suma de dos enteros
*
* \ Primer numero sumando (a)
* \ Segundo numero sumando (b)
* \return Devuelve la suma entre a + b
*/
int sumar(int a, int b);


/** \brief Resta de dos enteros
*
* \ Numero minuendo (a)
* \ Numero sustraendo (b)
* \return Devuelve la resta entre a - b
*/
int restar(int a, int b);


/** \brief Division de dos numeros enteros
*
* \ Numero dividendo (a)
* \ Numero divisor (b)
* \return Devuelve la division entre a / b
*/
float dividir(int a, int b);


/** \brief Multiplicacion de dos enteros
*
* \ Primer factor ingresado (a)
* \ Segundo factor ingresado (b)
* \return Devuelve la multiplicacion de a * b
*/
int multiplicar(int a, int b);


/** \brief Factorial de un entero
*
* \ Numero inicial (a)
* \
* \return Devuelve la factorial de "a"
*/
int factorial(int a);

