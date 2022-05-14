/*
 * menu.c
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */


#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"

/// @fn int mostrarMenu()
/// @brief Muestra un menu y le pide al usuario que ingrese una opcion.
///
/// @return Un entero que es la opcion elegida.
int mostrarMenuPrincipal()
{
	int opcion;
	printf("\n*****MENU PRINCIPAL*****");
	printf("\n1) ALTAS");
	printf("\n2) MODIFICACIONES");
	printf("\n3) BAJAS");
	printf("\n4) INFORMAR");
	printf("\n5) SALIR");
	printf("\nIngrese una opcion: ");

	opcion = getInt();

	return opcion;
}

/// @fn int mostrarMenu()
/// @brief Muestra un menu y le pide al usuario que ingrese una opcion.
///
/// @return Un entero que es la opcion elegida.
int mostrarMenuModificacion()
{
	int opcion;
	printf("\n*****MENU DE MODIFICACION*****");
	printf("\n1) NOMBRE.");
	printf("\n2) APELLIDO.");
	printf("\n3) PRECIO.");
	printf("\n4) TIPO DE PASAJERO.");
	printf("\n5) CODIGO DE VUELO.");
	printf("\n6) VOLVER AL MENU PRINCIPAL.");
	printf("\nIngrese una opcion: ");
	opcion = getInt();

	return opcion;
}

/// @fn int mostrarMenu()
/// @brief Muestra un menu y le pide al usuario que ingrese una opcion.
///
/// @return Un entero que es la opcion elegida.
int mostrarMenuListar()
{
	int opcion;
	printf("\n*****MENU DE LISTADOS*****");
	printf("\n1) ALFABETICAMENTE, APELLIDO Y TIPO.");
	printf("\n2) TOTAL, PROMEDIO Y CUANTOS SUPERAN EL PROMEDIO.");
	printf("\n3) CODIGO DE VUELOS Y ACTIVOS.");
	printf("\n4) VOLVER AL MENU PRINCIPAL.");
	printf("\nIngrese una opcion: ");
	opcion = getInt();

	return opcion;
}

/// @fn int mostrarMenu()
/// @brief Muestra un menu y le pide al usuario que ingrese una opcion.
///
/// @return Un entero que es la opcion elegida.
int mostrarMenuSN(char mensaje[])
{
	int opcion;

	printf("\n%s", mensaje);
	printf("\n1) SI.");
	printf("\n2) NO.");
	printf("\nIngrese una opcion: ");
	opcion = getInt();

	return opcion;
}


