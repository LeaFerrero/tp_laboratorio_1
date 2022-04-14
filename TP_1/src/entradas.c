/*
 * entradas.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

float pedirFlotante(char mensaje[])
{
	float numero;
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}

char pedirLetra(char mensaje[])
{
	char letra;
	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &letra);
	return letra;
}

float reingresar(float numero, int aComparar, char mensajeUno[], char mensajeDos[])
{
	while(validarEsMayor(numero, aComparar) == 0)
	{
		printf("%s", mensajeUno);
		numero = pedirFlotante(mensajeDos);
	}
	return numero;
}