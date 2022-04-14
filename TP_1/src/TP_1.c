/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "entradas.h"
#include "validaciones.h"
#include "operaciones.h"

int main(void)
{
	char salir;
	int flagKm;
	int flagAerolineas;
	int flagLatam;
	int opcion;
	int opcionB;
	float km;
	float aerolineasPorKm;
	float creditoAerolineas;
	float diferenciaPrecio;
	float latamPorKm;
	float creditoLatam;
	float debitoAerolineas;
	float debitoLatam;
	float precioAerolineas;
	float precioLatam;
	double bitCoinAerolineas;
	double bitCoinLatam;
	int flagCalculos;

	int minimo;
	int descuento;
	int aumento;
	float bitcoin;

	minimo = 0;
	descuento = 10;
	aumento = 25;
	bitcoin = 4665933.58;

	flagAerolineas = 0;
	flagKm = 0;
	flagCalculos =	0;
	flagLatam = 0;
	salir = 'n';

	setbuf(stdout, NULL);

	do
	{
		printf("\n*******MENU*******\n");
		printf("1. Ingresar kilómetros\n");
		printf("2. Ingresar Precio de Vuelos\n");
		printf("3. Calcular Costos\n");
		printf("4. Informar Resultados\n");
		printf("5. Carga Forzada\n");
		printf("6. Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);


		switch(opcion)
		{
			case 1:
				km = pedirFlotante("\nIngrese los kilómetros: ");
				km = reingresar(km, minimo, "\nError, los kilómetros no pueden ser inferiores a 1.\n", "\nReingrese los kilómetros: ");
				if(validarEsMayor(km, minimo) == 1)
				{
					flagKm = 1;
					printf("\n¡Kilómetros ingresados con éxito!.\n\n");
				}
				system("pause");
			break;

			case 2:
				do
				{
					printf("\nPrecio de vuelos\n");
					printf("1. Ingresar precio Aerolíneas\n");
					printf("2. Ingresar Precio de Latam\n");
					printf("3. Volver al menú principal\n\n");
					printf("Ingrese una opción: ");
					scanf("%d", &opcionB);
					switch(opcionB)
					{
						case 1:
							precioAerolineas = pedirFlotante("\nIngrese el precio para Aerolíneas: ");
							precioAerolineas = reingresar(precioAerolineas, minimo, "\nError, el precio no puede ser inferior a 1\n", "\nReingrese el precio para Aerolíneas: ");
							if(validarEsMayor(precioAerolineas, minimo) == 1)
							{
								flagAerolineas = 1;
								printf("\n¡El precio para Aerolíneas se ha ingresado con éxito!\n\n");
							}
							system("pause");
						break;

						case 2:
							precioLatam = pedirFlotante("\nIngrese el precio para Latam: ");
							precioLatam = reingresar(precioLatam, minimo, "\nError, el precio no puede ser inferior a 1\n", "\nReingrese el precio para Latam: ");
							if(validarEsMayor(precioLatam, minimo) == 1)
							{
								flagLatam = 1;
								printf("\n¡El precio para Latam se ha ingresado con éxito!\n");
							}
						break;

						case 3:
							printf("\nVolviendo al menú principal.\n\n");
							system("pause");

						default:
							printf("\nError, opcion no valida, volviendo al menú.\n\n");
							system("pause");
					}
				}
				while(opcionB != 3);

			break;

			case 3:
				if(flagKm == 1 && flagAerolineas == 1 && flagLatam == 1 )
				{
					debitoAerolineas = calcularDescuento(precioAerolineas, descuento);
					creditoAerolineas = calcularAumento(precioAerolineas, aumento);
					bitCoinAerolineas = pasarAMoneda(precioAerolineas, bitcoin);
					aerolineasPorKm = dividirFlotante(precioAerolineas, km);

					debitoLatam = calcularDescuento(precioLatam, descuento);
					creditoLatam = calcularAumento(precioLatam, aumento);
					bitCoinLatam = pasarAMoneda(precioLatam, bitcoin);
					latamPorKm = dividirFlotante(precioLatam, km);

					if(precioAerolineas > precioLatam)
					{
						diferenciaPrecio = precioAerolineas - precioLatam;
					}
					else
					{
						diferenciaPrecio = precioLatam - precioAerolineas;
					}

					flagCalculos =	1;
					printf("Se estan calculando los costos.");
				}
				else
				{
					if(flagKm == 0)
					{
						printf("No se han ingresado Kilómetros.");
					}

					if(flagAerolineas == 0)
					{
						printf("No se han ingresado precios para Aerolineas.");
					}

					if(flagAerolineas == 0)
					{
						printf("No se han ingresado precios para Latam.");
					}

				}
 			break;

			case 4:
				if(flagCalculos == 1)
				{
					printf("\nKMs ingresados: %.2f km.\n\n", km);

					printf("Precio Aerolíneas: $ %.2f\n", precioAerolineas);
					printf("a) Precio con tarjeta de debito: $ %.2f\n", debitoAerolineas);
					printf("b) Precio con tarjeta de credito: $ %.2f\n", creditoAerolineas);
					printf("d) Precio pagando con BitCoin: %lf BTC\n", bitCoinAerolineas);
					printf("e) Mostrar precio unitario: $ %.2f\n\n", aerolineasPorKm);

					printf("Precio Latam: $ %.2f\n", precioLatam);
					printf("a) Precio con tarjeta de debito: $ %.2f\n", debitoLatam);
					printf("b) Precio con tarjeta de credito: $ %.2f\n", creditoLatam);
					printf("d) Precio pagando con BitCoin: $ %lf\n", bitCoinLatam);
					printf("e) Mostrar precio unitario: $ %.2f\n\n", latamPorKm);

					printf("La diferencia de precio es: $ %.2f\n\n", diferenciaPrecio);
				}
				else
				{
						printf("\nError, faltan datos para hacer las operaciones.\n");
				}
			break;

			case 5:
				km = 7090;
				precioAerolineas = 162965;
				precioLatam = 159339;
				flagKm = 1;
				flagAerolineas = 1;
				flagLatam = 1;
			break;

			case 6:
				salir = pedirLetra("Desea salir? 's' o 'n' ");
				while(validarLetraSN(salir) == 0)
				{
					salir = pedirLetra("Opcion no valida ");
				}
				if(salir == 's')
				{
					printf("Gracias, vuelva pronto!");
				}
			break;

			default:
				printf("\nError, opcion no valida, volviendo al menú.\n");
				system("pause");

		}



	}while(salir == 'n');

	return EXIT_SUCCESS;
}
