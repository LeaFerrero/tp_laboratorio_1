/*
 * entradas.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "validaciones.h"

/// @fn float pedirFlotante(char[])
/// @brief Pide un flotante al usuario y lo retorna.
///
/// @param mensaje Es el mensaje a ser mostrado.
/// @return El numero flotante ingresado.
float pedirFlotante(char mensaje[])
{
	float numero;
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}

/// @fn char pedirLetra(char[])
/// @brief Pide una letra al usuario, la pasa a mayúscula la retorna.
///
/// @param mensaje El mensaje a ser mostrado.
/// @return La letra ingresada
char pedirLetra(char mensaje[])
{
	char letra;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &letra);
	letra = toupper(letra);
	return letra;
}

/// @fn float reingresarFlotante(float, int, char[], char[])
/// @brief Se ejecuta un while que como condicion va llamar a la funcion validarEsMayor,
/// si esta funcion retorna 0 se cumple la condicion y el bucle sigue, si retorna 1 el bucle se corta.
/// Meintras se cumpla la condicion va a mostrar un mensaje para informar al usuario,
/// y va a llamar a la funcion pedirEntero para que reingrese el numero flotante.
/// Cuando el bucle se corta se retorna el flotante.
///
///
/// @param numero Flotante a ser comparado que se va a pasar a la funcion validarEsMayor.
/// @param comparante Es el número que se le va a pasar a la funcion vlidarEsMayor y con la que se va a comparar el número ingresado.
/// @param primerMensaje Mensaje que se va a pasar a la funcion validarEsMayor y se mostrara en caso que retorne 0.
/// @param segundoMensaje Mensaje que se va a pasar a la funcion pedirFlotante y se mostrara en caso de que validarEsMayor retorne 0.
/// @return un nuumero flotante.
float reingresarFlotante(float numero, int comparante, char primerMensaje[], char segundoMensaje[])
{
	while(validarEsMayor(numero, comparante) == 0)
	{
		printf("%s", primerMensaje);
		numero = pedirFlotante(segundoMensaje);
	}
	return numero;
}


/// @fn char reingresarChar(char, char, char, char[], char[])
/// @brief Se ejecuta un while que como condicion va llamar a la funcion validarLetra,
/// si esta funcion retorna 0 se cumple la condicion y el bucle sigue, si retorna 1 el bucle se corta.
/// Meintras se cumpla la condicion va a mostrar un mensaje para informar al usuario,
/// va a llamar a la funcion pedirLetra para que reingrese  la letra, y la va a pasar a mayúscula.
/// Cuando búcle se corta retorna la letra mayúscula.
///
/// @param letra Letra a ser comparada que se le va a pasar la funcion validarLetra.
/// @param comparanteA Primera letra que se le va a pasar a la funcion validarLetra y con la que se va a comparar la letra ingresada.
/// @param comparanteB Segunda letra que se le va a pasar a la funcion validarLetra y con la que se va a comparar la letra ingresada.
/// @param primerMensaje Mensaje que se mostrara en caso que la funcion validarLetra retorne 0.
/// @param segundoMensaje Mensaje que se va a pasar a la funcion pedirLetra y se mostrara en caso de que validarEsMayor retorne 0.
/// @return letra mayuscula.
char reingresarChar(char letra, char comparanteA, char comparanteB, char primerMensaje[], char segundoMensaje[])
{
	while(validarLetra(letra, comparanteA, comparanteB) == 0)
	{
		printf("%s", primerMensaje);
		letra = pedirLetra(segundoMensaje);
		letra = toupper(letra);
	}
	return letra;
}
