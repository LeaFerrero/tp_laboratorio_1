/*
 * validaciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>

int validarEsMayor(int numero, int aComparar)
{
	int retorno;

	retorno = 0;

	if(numero > aComparar)
	{
		retorno = 1;
	}

	return retorno;
}

char validarLetraSN(char letra)
{
	char retorno;

	retorno = 1;

	if(letra != 's' && letra != 'n')
	{
		retorno = 0;
	}

	return retorno;
}


