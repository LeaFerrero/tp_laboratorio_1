/*
 * salidas.c
 *
 *  Created on: 15 abr. 2022
 *      Author: wilo waiko
 */

#include <stdio.h>
#include <stdlib.h>

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

	printf("Precio Aerol�neas: $ %.2f\n", precioAerolineas);
	printf("a) Precio con tarjeta de d�bito: $ %.2f\n", debitoAerolineas);
	printf("b) Precio con tarjeta de cr�dito: $ %.2f\n", creditoAerolineas);
	printf("d) Precio pagando con BitCoin: %lf BTC\n", bitCoinAerolineas);
	printf("e) Mostrar precio unitario: $ %.2f\n\n", aerolineasPorKm);

	printf("Precio Latam: $ %.2f\n", precioLatam);
	printf("a) Precio con tarjeta de d�bito: $ %.2f\n", debitoLatam);
	printf("b) Precio con tarjeta de cr�dito: $ %.2f\n", creditoLatam);
	printf("d) Precio pagando con BitCoin: $ %lf\n", bitCoinLatam);
	printf("e) Mostrar precio unitario: $ %.2f\n\n", latamPorKm);

	printf("La diferencia de precio es: $ %.2f\n\n", diferenciaPrecio);
}
