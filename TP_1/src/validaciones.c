/*
 * validaciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>


/// @fn int validarEsMayor(int, int)
/// @brief Recive un flotante y un entero y los compara con un entero,
/// si el flotante es mas chico que entero retorna 0,
/// si el flotante es mas grande retorna 1.
///
/// @param numero El flotante a comparar.
/// @param comparante El enero con el que se va a comparar el flotante.
/// @return	0 si el flotante es mas chico y 1 si el flotante es mas grande.
int validarEsMayor(float numero, int comparante)
{
	int retorno;

	retorno = 0;

	if(numero > comparante)
	{
		retorno = 1;
	}

	return retorno;
}

/// @fn char validarLetra(char, char, char)
/// @brief Recive tres letras, y compara la primer letra que recive con las otras dos.
/// si la primer letra es distinta de las dos letras con las que se compara retorna 0.
/// si la primer es igyal a alguna de las otras dos letras retorna 1.
///
/// @param letra Letra comparar.
/// @param comparanteA Primer ketra con la que se compara la letra a comparar.
/// @param comparanteB Segunda letra con la que se compara la letra a comparar.
/// @return 0 si la letra a comparar es distinta de las otras dos letras, 1 si la letra a comparar es igual.
char validarLetra(char letra, char comparanteA, char comparanteB)
{
	char retorno;

	retorno = 0;

	if(letra == comparanteA || letra == comparanteB)
	{
		retorno = 1;
	}

	return retorno;
}


