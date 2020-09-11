#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


#endif // FUNCTIONS_H_INCLUDED
/** \brief Muestra el menu de opciones para el usuario
 *
 * \param a int es el primer numero que ingresa el usuario en el menu de opciones
 * \param b int es el segundo numero que ingresa el usuario en el menu de opciones
 * \return void no devuelve nada ya que ,muestra unicamente el menu de usuario
 *
 */
void menu(int a, int b);
/** \brief realiza la suma entre el numero A y el numero B
 *
 * \param a int es el primer numero que ingresa el usuario en el menu de opciones
 * \param b int es el segundo numero que ingresa el usuario en el menu de opciones
 * \return int devuelve el valor de la operacion realizada con los valores a y b
 *
 */
int sumar(int a, int b);
/** \brief realiza la resta entre el numero A y el numero B
 *
 * \param a int es el primer numero que ingresa el usuario en el menu de opciones
 * \param b int es el segundo numero que ingresa el usuario en el menu de opciones
 * \return int devuelve el valor de la operacion realizada con los valores a y b
 *
 */
int restar(int a, int b);
/** \brief realiza la multiplicacion entre el numero A y el numero B
 *
 * \param a int int es el primer numero que ingresa el usuario en el menu de opciones
 * \param b int es el segundo numero que ingresa el usuario en el menu de opciones
 * \return int devuelve el valor de la operacion realizada con los valores a y b
 *
 */
int multiplicar(int a, int b);
/** \brief realiza la division entre el numero A y el numero B
 *
 * \param a int int es el primer numero que ingresa el usuario en el menu de opciones
 * \param b int es el segundo numero que ingresa el usuario en el menu de opciones
 * \return float devuelve el valor de la operacion realizada con los valores a y b
 *
 */
float dividir(int a, int b);
/** \brief realiza el factorial del numero ingresado
 *
 * \param numero que ingresa el usuario en el menu de opciones
 * \param se guardan el resultado del factorial del numero
 * \return devuelve el valor de la operacion realizada con el numero asignado pero si es un numero invalido, no devuelve nada
 *
 */
long int factorial (int numero);
/** \brief realiza la eleccion del menu de usuario
 *
 * \param a int es el primer numero que ingresa el usuario en el menu de opciones
 * \param b int es el segundo numero que ingresa el usuario en el menu de opciones
 * \return void no devuelve nada ya que es la logica del menu de usuario
 *
 */
void eleccion(int a, int b);
/** \brief Se encarga de obtener un numero
 *
 * \param num int se almacene el numero que solicita la funcion
 * \return int devuelve el numero obtenido
 *
 */
int get_int(int num);

