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

#include "ArrayPassenger.h"
#include "entradas.h"
#include "menu.h"
#include "TypePassenger.h"

#define CANT 2000
#define CANT_STATUS 4
#define CANT_TYPE 4
#define CANT_HARDCODE 5
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
				if(hardcodePassenger(passenger, CANT_HARDCODE))
				{
					cantidadDatos = 5;
					printf("\nDatos harcodeados.\n");
				}

			break;

			case 3:
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
								if(modifyPassanger(passenger, CANT, type, CANT_TYPE, status, CANT_STATUS, opcionMenuModificacion))
								{
									printf("\nSe han realizado los cambios con exito.\n");
								}
							break;

							case 6:
								printf("\nVolviendo al menu anterior.\n");
							break;
							default:
								printf("\nError, opcion no valida.\n");
						}
					}
					while(opcionMenuModificacion != 6);
				}
				else
				{
					printf("\nNo se han ingresado datos.\n");
				}
			break;

			case 4:
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
					printf("\nNo se han ingresado datos.\n");
				}

			break;

			case 5:
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
					printf("\nNo se han ingresado datos.\n");
				}
			break;

			case 6:
				printf("\n¡Gracias, vualva pronto!");
			break;

			default:
				printf("\nError, opcion no valida.\n");
		}
	}
	while(opcionMenuPrincipal != 6);

	return EXIT_SUCCESS;
}
