/*
 * TypePassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <string.h>
#include "typePassenger.h"
#include "entradas.h"

void hardcodeTypePassenger(TypePassenger list[], int len)
{
	int i;
	int id[] = {1, 2, 3, 4};
	char name[][51] = {"Primera clase", "Clase ejecutiva", "Clase premium economu", "Clase turista"};

	for(i = 0;  i < len; i++)
	{
		list[i].idTypePassenger = id[i];
		strcpy(list[i].nameTypePassenger, name[i]);
	}
}

void showTypePassenger(TypePassenger list[], int len)
{
	int i;
	printf("\n%5s\t\t%s", "ID", "TIPO\n");
	for(i = 0; i < len; i++)
	{
		printf("%5d\t\t%s\n", list[i].idTypePassenger, list[i].nameTypePassenger);
	}
}

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

	printf("\n este es el tipo %d:", index);
	return index;
}
