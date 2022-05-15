/*
 * TypePassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: wilo waiko
 */

#include "TypePassenger.h"

/// @fn void hardcodeTypePassenger(TypePassenger[], int)
/// @brief Hrdcodea 4 tipos de pasajeros.
///
/// @param list Lista que contiene los tipos de pasajeros.
/// @param len Tamaño del array que contiene los tipos de pasajeros.
void hardcodeTypePassenger(TypePassenger list[], int len)
{
	int i;
	int id[] = {1, 2, 3, 4};
	char name[][51] = {"Primera", "Ejecutiva", "Premium economy", "Turista"};

	for(i = 0;  i < len; i++)
	{
		list[i].idTypePassenger = id[i];
		strcpy(list[i].nameTypePassenger, name[i]);
	}
}

/// @fn void showTypePassenger(TypePassenger[], int)
/// @brief Muestra por pantalla la lista de tipos de pasajeros.
///
/// @param list Lista que contiene los tipos de pasajeros.
/// @param len Tamaño del array que contiene los tipos de pasajeros.
void showTypePassenger(TypePassenger list[], int len)
{
	int i;
	printf("\nTipo de pasajero\n");
	for(i = 0; i < len; i++)
	{
		printf("%d - %s\n", list[i].idTypePassenger, list[i].nameTypePassenger);
	}
}

/// @fn int loadstatusFlight(StatusFlight[], int)
/// @brief Muestra por pantalla  el ID y el nombre del tipo de pasajero para que el usuario
/// pueda selecionar uno y retornal el indice.
///
/// @param list Lista que contiene los tipos de pasajeros.
/// @param len Tamaño del array que contiene los tipos de pasajeros.
/// @return Retorna el indice.
int loadTypePassenger(TypePassenger list[], int len)
{
	int i;
	int auxiliar;
	int index;

	showTypePassenger(list, len);

	auxiliar = getValidInt("Igrese la clase", "Error, opcion no valida", 1, len);
	for(i = 0; i < len; i++)
	{
		if(list[i].idTypePassenger == auxiliar)
		{
			index = i;
		}
	}

	return index;
}
