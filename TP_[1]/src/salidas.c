/*
 * salidas.c
 *
 *  Created on: 15 abr. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

/// @fn void imprimirResultados(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Recibe los los flotantes y los imprime con un mensaje para informar al usuario.
///
/// @param km Los kilometros ingresados
/// @param precioAerolineas El precio de Aerolineas
/// @param precioLatam El precio de latam
/// @param debitoAerolineas El precio de Aerolineas a pagar con debito
/// @param debitoLatam El precio de Latam  a pagar con debiro
/// @param creditoAerolineas El precio de Aerolineas a pagar con tarjeta de credito
/// @param creditoLatam	El precio de Latam a pagar con tarjeta de credito
/// @param bitCoinAerolineas El precio de Aerolineas a pagar con BitCoin
/// @param bitCoinLatam El precio de Latam a pagar con BitCoin
/// @param aerolineasPorKm El costo por kilometro de Aerolineas
/// @param latamPorKm El costo por kilometro de Latam
/// @param diferenciaPrecio La diferencia de precio que hay entre el precio de ambas empresas
void imprimirResultados(float km, float precioAerolineas, float precioLatam, float debitoAerolineas,
						float debitoLatam, float creditoAerolineas, float creditoLatam, float bitCoinAerolineas,
						float bitCoinLatam, float aerolineasPorKm, float latamPorKm, float diferenciaPrecio)
{
	printf("\nKMs ingresados: %.2f km.\n\n", km);

	printf("Precio Aerolíneas: $ %.2f\n", precioAerolineas);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoAerolineas);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoAerolineas);
	printf("d) Precio pagando con BitCoin: %lf BTC\n", bitCoinAerolineas);
	printf("e) Mostrar precio unitario: $ %.2f\n\n", aerolineasPorKm);

	printf("Precio Latam: $ %.2f\n", precioLatam);
	printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoLatam);
	printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoLatam);
	printf("d) Precio pagando con BitCoin: $ %lf\n", bitCoinLatam);
	printf("e) Mostrar precio unitario: $ %.2f\n\n", latamPorKm);

	printf("La diferencia de precio es: $ %.2f\n\n", diferenciaPrecio);
}


/// @fn void imprimirMensajeBandera(int, int, char[], float)
/// @brief Se llama a la funcion validarEsMayor como condicion de un if para que imprima un mensaje en caso de cumplirse la condicion.
/// Si la funcion validarEsMayor retorna 1 se cumple la condicion e imprime el mensaje y muestra el numero flotante que recive.
///
/// @param numero El número entero a ser comparado.
/// @param minimo El número entero con el que se va a comparar el primer entero.
/// @param mensaje Mensaje que se va a mostrar.
/// @param numeroAMostrar El número flotante que se va a mostrar en el mnensaje.
void imprimirMensajeBandera(int numero, int minimo, char mensaje [], float numeroAMostrar)
{
	if(validarEsMayorEntero(numero, minimo) == 1)
	{
		printf("(%s %.2f) ", mensaje, numeroAMostrar);
	}
}
