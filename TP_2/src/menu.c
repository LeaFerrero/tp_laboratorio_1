/*
 * menu.c
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */


#include "menu.h"

/// @fn int mostrarMenu()
/// @brief Muestra un menu y le pide al usuario que ingrese una opcion.
///
/// @return Un entero que es la opcion elegida.
int mostrarMenuPrincipal()
{
	int opcion;
	printf("\n*****MENU PRINCIPAL*****");
	printf("\n1) Altas");
	printf("\n2) Hardcodear Altas");
	printf("\n3) Modificaciones");
	printf("\n4) Bajas");
	printf("\n5) Informar");
	printf("\n6) Salir");
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
	printf("\n1) Nombre.");
	printf("\n2) Apellido.");
	printf("\n3) Precio.");
	printf("\n4) Tipo de pasajero.");
	printf("\n5) Codigo de vuelo.");
	printf("\n6) Volver al menu principal.");
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
	printf("\n1) Alfabeticamente, appelido y tipo.");
	printf("\n2) total, promedio y cuantos superan el promedio.");
	printf("\n3) Codigo de vuelo y activos.");
	printf("\n4) volver al menu principal.");
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


