/*
 * operaciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>

float calcularDescuento(float numero, int porcentaje)
{
	float numeroDescontado;
	float numeroConDescuento;

	numeroDescontado = numero * porcentaje / 100;
	numeroConDescuento = numero - numeroDescontado;

	return numeroConDescuento;
}

float calcularAumento(float numero, int porcentaje)
{
	float numeroAumentado;
	float numeroConAumento;

	numeroAumentado = numero * porcentaje / 100;
	numeroConAumento = numero + numeroAumentado;

	return numeroConAumento;
}

float dividirFlotante(float numeroA, float numeroB)
{
	float resultado;

	resultado = numeroA / numeroB;

	return resultado;
}

float restarFlotante(float numeroA, float numeroB)
{
	float  resultado;

	resultado = numeroA - numeroB;

	return resultado;
}


double pasarAMoneda(float valor, float moneda)
{
	double retorno;

	retorno = (double)valor / moneda;

	return retorno;
}
