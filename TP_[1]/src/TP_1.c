/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "entradas.h"
#include "validaciones.h"
#include "operaciones.h"
#include "salidas.h"

int main(void)
{
	//variables
	char salir;
	int aumento;
	int descuento;
	int flagAerolineas;
	int flagCalculos;
	int flagKm;
	int flagLatam;
	int minimo;
	int opcion;
	int opcionB;
	float aerolineasPorKm;
	float bitcoin;
	float creditoAerolineas;
	float creditoLatam;
	float debitoAerolineas;
	float debitoLatam;
	float diferenciaPrecio;
	float km;
	float latamPorKm;
	float precioAerolineas;
	float precioLatam;
	float bitCoinAerolineas;
	float bitCoinLatam;

	//se inicializan las variables que lo necesiten.
	salir = 'N';
	aumento = 25;
	bitcoin = 4665933.58;
	descuento = 10;
	minimo = 1;

	flagAerolineas = 0;
	flagCalculos =	0;
	flagKm = 0;
	flagLatam = 0;

	setbuf(stdout, NULL);

	//empieza el men�
	do
	{
		printf("\n*******MENU*******\n");
		printf("1. Ingresar kil�metros: ");

		// una vez que se ingresaron los kil�metros, se muestran en el men�.
		imprimirMensajeBandera(flagKm, 0, "Km = ", km);

		printf("\n2. Ingresar Precio de Vuelos: ");

		// una vez que se ingres� el precio de Aerol�neas, se muestra en el men�.
		imprimirMensajeBandera(flagAerolineas, 0, "Aerol�neas = $", precioAerolineas);

		// una vez que se ingres� el precio de Latam, se muestra en el men�.

		imprimirMensajeBandera(flagLatam, 0, "Latam = $", precioLatam);

		printf("\n3. Calcular Costos");
		printf("\n4. Informar Resultados");
		printf("\n5. Carga Forzada");
		printf("\n6. Salir\n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);


		switch(opcion)
		{
			case 1:
				//pide los kil�metros.
				km = pedirFlotante("\nIngrese los kil�metros: ");
				//verifica que los kil�metros no sean inferiores a uno y en caso de que lo sean los vuelve a pedir.
				km = reingresarFlotante(km, minimo, "\nError, los kil�metros no pueden ser inferiores a 1.\n", "\nReingrese los kil�metros: ");
				//Verifica que el usuario haya ingresado los kil�metros, pone la vandera  de km en 1 e informa si la carga fue exitosa.
				if(validarEsMayor(km, minimo) == 1)
				{
					flagKm = 1;
					printf("\n�Kil�metros ingresados con �xito!.\n");
				}

			break;

			case 2:
				//submenu para los precios.
				do
				{
					printf("\nIngresar precio de vuelos\n");
					printf("\n1. Ingresar precio Aerol�neas: ");

					// una vez que se ingres� el precio de Aerol�neas, se muestran en el submen� de ingreso de precios.
					imprimirMensajeBandera(flagAerolineas, 0, "Aerol�neas = $", precioAerolineas);

					printf("\n2. Ingresar Precio de Latam: ");

					// una vez que se ingres� el precio de Latam, se muestran en el submen� de ingreso de precios.
					imprimirMensajeBandera(flagLatam, 0, "Latam = $", precioLatam);

					printf("\n3. Volver al men� principal\n");
					printf("\nIngrese una opci�n: ");
					scanf("%d", &opcionB);
					switch(opcionB)
					{
						case 1:
							//pide el precio para Aerol�neas.
							precioAerolineas = pedirFlotante("\nIngrese el precio para Aerol�neas: ");
							//verifica que el precio no sea inferior a uno y en caso de que lo sean los vuelve a pedir.
							precioAerolineas = reingresarFlotante(precioAerolineas, minimo, "\n�ERROR! El precio no puede ser inferior a 1.\n", "\nReingrese el precio para Aerol�neas: ");
							//Verifica que el usuario haya ingresado el, pone la vandera  de precioAerolineas en 1 e informa si la carga fue exitosa.
							if(validarEsMayor(precioAerolineas, minimo) == 1)
							{
								flagAerolineas = 1;
								printf("\n�El precio para Aerol�neas se ha ingresado con �xito!\n");
							}

						break;

						case 2:
							//pide el precio para Latam.
							precioLatam = pedirFlotante("\nIngrese el precio para Latam: ");
							//verifica que el precio no sea inferior a uno y en caso de que lo sean los vuelve a pedir.
							precioLatam = reingresarFlotante(precioLatam, minimo, "\n�ERROR! El precio no puede ser inferior a 1.\n", "\nReingrese el precio para Latam: ");
							//Verifica que el usuario haya ingresado el, pone la vandera  de precioLatam en 1 e informa si la carga fue exitosa.
							if(validarEsMayor(precioLatam, minimo) == 1)
							{
								flagLatam = 1;
								printf("\n�El precio para Latam se ha ingresado con �xito!\n");
							}
						break;

						case 3:
							//vuelve al men� principal
							printf("\nVolviendo al men� principal.\n\n");
						break;

						default:
							//si se ingresa una opci�n no valida muestra un mensaje de error.
							printf("\n�ERROR! Opci�n no valida, volviendo al men�.\n");
						break;
					}
				}
				while(opcionB != 3);

			break;

			case 3:
				//verifica si el usuario ingreso todos los datos y hace las cuentas necesarias.
				if(flagKm == 1 && flagAerolineas == 1 && flagLatam == 1 )
				{
					debitoAerolineas = calcularDescuento(precioAerolineas, descuento);
					creditoAerolineas = calcularAumento(precioAerolineas, aumento);
					bitCoinAerolineas = dividir(precioAerolineas, bitcoin);
					aerolineasPorKm = dividir(precioAerolineas, km);

					debitoLatam = calcularDescuento(precioLatam, descuento);
					creditoLatam = calcularAumento(precioLatam, aumento);
					bitCoinLatam = dividir(precioLatam, bitcoin);
					latamPorKm = dividir(precioLatam, km);

					//verifica cual es el precio mas alto para que la resta no de negativa.
					if(precioAerolineas > precioLatam)
					{
						diferenciaPrecio = precioAerolineas - precioLatam;
					}
					else
					{
						diferenciaPrecio = precioLatam - precioAerolineas;
					}
					//s
					flagCalculos =	1;
					printf("\nSe han calculando los costos.\n");
				}
				else
				{
					//se muestra un error si hay algun dato que no se haya ingresado
					if(flagKm == 0)
					{
						printf("\n�ERROR! No se han ingresado Kil�metros.\n");
					}

					if(flagAerolineas == 0)
					{
						printf("\n�ERROR! No se han ingresado precios para Aerolineas.\n");
					}

					if(flagLatam == 0)
					{
						printf("\n�ERROR! No se han ingresado precios para Latam.\n");
					}

				}
 			break;

			case 4:
				//se verifica que se hayan hecho los calculos y de ser asi se los imprime en pantalla con un mensaje.
				if(flagCalculos == 1)
				{
					imprimirResultados(km, precioAerolineas, precioLatam, debitoAerolineas,
									   debitoLatam, creditoAerolineas, creditoLatam, bitCoinAerolineas,
									   bitCoinLatam, aerolineasPorKm, latamPorKm, diferenciaPrecio);
				}
				//muestra un error si no se pudierion mostrar los resultados.
				else
				{
						printf("\n�ERROR! Faltan datos para realizar las operaciones.\n");
				}

				//una vez calculado los costos se vuelen a poner las banderas en 0,
				//el usuario necesita reingresar los datos si quiere volver a calcular.
				flagAerolineas = 0;
				flagCalculos =	0;
				flagKm = 0;
				flagLatam = 0;

			break;

			case 5:
				// aca se hardcoodean los datos, se calculan y se imprimen.
				//DATO DE VITAL IMPORTANCIA, no hay banderas en el modo hardcodeo,
				//por lo tanto no se va a mostrar los datos ingresados en el men�,
				//ni se van a poder hacer los calculos usando estos valores para las opciones 3 y 4.
				km = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;

				debitoAerolineas = calcularDescuento(precioAerolineas, descuento);
				creditoAerolineas = calcularAumento(precioAerolineas, aumento);
				bitCoinAerolineas = dividir(precioAerolineas, bitcoin);
				aerolineasPorKm = dividir(precioAerolineas, km);

				debitoLatam = calcularDescuento(precioLatam, descuento);
				creditoLatam = calcularAumento(precioLatam, aumento);
				bitCoinLatam = dividir(precioLatam, bitcoin);
				latamPorKm = dividir(precioLatam, km);

				//como aca los datos esta hardcodeados no hace falta verificar, Aerolineas siempre va a ser mas grande, a menos que lo cambie e un futuro, claro.
				diferenciaPrecio = precioAerolineas - precioLatam;

				imprimirResultados(km, precioAerolineas, precioLatam, debitoAerolineas,
									debitoLatam, creditoAerolineas, creditoLatam, bitCoinAerolineas,
									bitCoinLatam, aerolineasPorKm, latamPorKm, diferenciaPrecio);


			break;

			case 6:
				//pide una letra para finalizar el programa.
				salir = pedirLetra("\n�Desea salir? 'S' o 'N' ");
				//verifica que la letra sea ingresada sea S o N, si no la vuelve a pedir.
				salir = reingresarChar(salir, 'S', 'N', "\n�ERROR! Opci�n no valida.", " �Desea salir? ('S' para si, o 'N' para No.): ");
				//si la letra es S cierra el programa, y muestra una bonita frase de despedida.
				if((salir == 'S') == 1)
				{
					printf("\n�Gracias, vuelva pronto!");
				}
			break;

			default:
				//mensaje de error para una opci�n del menu no valida.
				printf("\n�ERROR! Opcion no valida, volviendo al men�.\n");
			break;
		}

	}while(salir == 'N');

	return EXIT_SUCCESS;
}
