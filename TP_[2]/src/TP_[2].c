/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"
#include "menu.h"
#include "passenger.h"
#include "typePassenger.h"

#define CANT 10
#define CANT_STATUS 4
#define CANT_TYPE 4
#define UP 1
#define DOWN 0

int main(void)
{
	int opcionMenuPrincipal;
	int opcionMenuModificacion;
	int opcionMenuListar;
	int cantidadDatos;
	Passenger passenger[CANT];
	StatusFlight status[CANT_STATUS];
	TypePassenger type[CANT_TYPE];



	cantidadDatos = 0;

	setbuf(stdout, NULL);

	initPassengers(passenger, CANT);
	hardcodestatusFlight(status, CANT_STATUS);
	hardcodeTypePassenger(type, CANT_STATUS);


	do
	{
		opcionMenuPrincipal = mostrarMenuPrincipal();

		switch(opcionMenuPrincipal)
		{
			case 1:
				if(loadPassenger(passenger, CANT, type, CANT_TYPE, status, CANT_STATUS))
				{
					printf("\nPasajero cargado con exito.\n");
					cantidadDatos++;
				}
			break;

			case 2:
				if(cantidadDatos > 0)
				{
					do
					{
						opcionMenuModificacion = mostrarMenuModificacion();
						switch(opcionMenuModificacion)
						{
							case 1:
							case 2:
							case 3:
							case 4:
							case 5:
								modifyPassanger(passenger, CANT, type, CANT_TYPE, status, CANT_STATUS, opcionMenuModificacion);
							break;

							case 6:
								printf("\nVolviendo al menu anterior");
							break;
							default:
								printf("Opcion no valida");
						}
					}
					while(opcionMenuModificacion != 6);
				}
				else
				{
					printf("\nNo se han ingresado datos");
				}
			break;

			case 3:
				if(cantidadDatos > 0)
				{
					if(downPassenger(passenger, CANT, type, CANT_TYPE, status, CANT_STATUS))
					{
						printf("\nSe ha dado de baja con exito.\n");
						cantidadDatos --;
					}
				}
				else
				{
					printf("\nNo se han ingresado datos");
				}

			break;

			case 4:
				if(cantidadDatos > 0)
				{
					do
					{
						opcionMenuListar = mostrarMenuListar();
						switch(opcionMenuListar)
						{
							case 1:
								if(sortPassengers(passenger, CANT, UP))
								{
									printPassenger(passenger, CANT, type, CANT_TYPE, status, CANT_STATUS);
								}
							break;

							case 2:
								informarPrecio(passenger, CANT);
							break;

							case 3:
								if(ordenarPasajerosCodigo(passenger, CANT, UP))
								{
									printPassenger(passenger, CANT, type, CANT_TYPE, status, CANT_STATUS);
								}
							break;
						}

					}
					while(opcionMenuListar != 6);
				}
				else
				{
					printf("\nNo se han ingresado datos");
				}
			break;
			default:
				printf("Error, opcion no valida.");
		}
	}
	while(opcionMenuPrincipal != 5);

	return EXIT_SUCCESS;
}
