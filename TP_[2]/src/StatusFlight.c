/*
 * statusFlight.c
 *
 *  Created on: 13 may. 2022
 *      Author: wilo waiko
 */


#include "StatusFlight.h"


/// @fn void hardcodestatusFlight(StatusFlight[], int)
/// @brief
///
/// @param list Array que contiene los estados.
/// @param len Tammaño del array que contiene los estados.
void hardcodestatusFlight(StatusFlight list[], int len)
{
	int i;
	int id[] = {1, 2, 3, 4};
	char name[][51] = {"Activo", "Demorado", "Reprogramado", "Cancelado"};

	for(i = 0;  i < len; i++)
	{
		list[i].idStatus = id[i];
		strcpy(list[i].nameStatus, name[i]);
	}
}

/// @fn void showstatusFlight(StatusFlight[], int)
/// @brief Muestra por pantala la lista de estados.
///
/// @param list Array que contiene los estados.
/// @param len Tammaño del array que contiene los estados.
void showstatusFlight(StatusFlight list[], int len)
{
	int i;
	printf("\nEstado de vuelo\n");
	for(i = 0; i < len; i++)
	{
		printf("%d - %s\n", list[i].idStatus, list[i].nameStatus);
	}
}

/// @fn int loadstatusFlight(StatusFlight[], int)
/// @brief Muestra por pantalla  el ID y el nombre del Estado para que el usuario
/// pueda selecionar uno y retornal el indice.
///
/// @param list Array que contiene los estados.
/// @param len Tammaño del array que contiene los estados.
/// @return Retorna el indice.
int loadstatusFlight(StatusFlight list[], int len)
{
	int i;
	int auxiliar;
	int index;

	showstatusFlight(list, len);

	auxiliar = getValidInt("Ingrese el estado del vuelo", "Error, opcion no valida", 1, len);
	for(i = 0; i < len; i++)
	{
		if(list[i].idStatus == auxiliar)
		{
			index = i;
		}
	}

	return index;
}

