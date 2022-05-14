/*
 * validaciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */



/// @fn int validarEsMayor(int, int)
/// @brief Recibe un flotante y un entero y los un entero,
/// si el flotante es mas chico que entero retorna 0, si no retorna 1
///
/// @param numero El flotante a comparar.
/// @param comparante El enero con el que se va a comparar el flotante.
/// @return	0 si el flotante es mas chico y 1 si el flotante es mas grande.
int validarEsMayor(float numero, int comparante)
{
	int retorno;

	retorno = 1;

	if(numero < comparante)
	{
		retorno = 0;
	}

	return retorno;
}

///// @fn int validarEsMayor(int, int)
/// @brief Recibe dos enteros y los compara.
/// si el primer entero es menor retorna 0, si no retorna 1.
///
/// @param numero El entero a comparar.
/// @param comparante El enero con el que se va a comparar el primer entero.
/// @return	0 si el primer entero es mas chico que el segundo, 1 si es mas grande.
int validarEsMayorEntero(int numero, int comparante)
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
/// @brief Recibe tres letras, y compara la primer letra que recibe con las otras dos.
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


