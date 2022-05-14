/*
 * statusFlight.c
 *
 *  Created on: 13 may. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <string.h>
#include "statusFlight.h"
#include "entradas.h"

/// @fn void hardcodestatusFlight(StatusFlight[], int)
/// @brief
///
/// @param list
/// @param len
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
/// @brief
///
/// @param list
/// @param len
void showstatusFlight(StatusFlight list[], int len)
{
	int i;
	printf("\n%5s\t\t%s", "ID", "ESTADO\n");
	for(i = 0; i < len; i++)
	{
		printf("%5d\t\t%s\n", list[i].idStatus, list[i].nameStatus);
	}
}

/// @fn int loadstatusFlight(StatusFlight[], int)
/// @brief
///
/// @param list
/// @param len
/// @return
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

