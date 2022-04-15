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


	salir = 'N';

	aumento = 25;
	bitcoin = 4665933.58;
	descuento = 10;
	minimo = 0;

	flagAerolineas = 0;
	flagCalculos =	0;
	flagKm = 0;
	flagLatam = 0;

	setbuf(stdout, NULL);

	do
	{
		printf("\n*******MENU*******\n");
		printf("1. Ingresar kil�metros: ");
		if(flagKm == 1)
		{
			printf("(km = %.2f)", km);
		}
		printf("\n2. Ingresar Precio de Vuelos:");
		printf("\n3. Calcular Costos");
		printf("\n4. Informar Resultados");
		printf("\n5. Carga Forzada");
		printf("\n6. Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);


		switch(opcion)
		{
			case 1:
				km = pedirFlotante("\nIngrese los kil�metros: ");
				km = reingresarFlotante(km, minimo, "\nError, los kil�metros no pueden ser inferiores a 1.\n", "\nReingrese los kil�metros: ");
				if(validarEsMayor(km, minimo) == 1)
				{
					flagKm = 1;
					printf("\n�Kil�metros ingresados con �xito!.\n\n");
				}

			break;

			case 2:
				do
				{
					printf("\nIngresar precio de vuelos\n");
					printf("1. Ingresar precio Aerol�neas: \n");
					printf("2. Ingresar Precio de Latam: \n");
					printf("3. Volver al men� principal\n\n");
					printf("Ingrese una opci�n: ");
					scanf("%d", &opcionB);
					switch(opcionB)
					{
						case 1:
							precioAerolineas = pedirFlotante("\nIngrese el precio para Aerol�neas: ");
							precioAerolineas = reingresarFlotante(precioAerolineas, minimo, "\nError, el precio no puede ser inferior a 1\n", "\nReingrese el precio para Aerol�neas: ");
							if(validarEsMayor(precioAerolineas, minimo) == 1)
							{
								flagAerolineas = 1;
								printf("\n�El precio para Aerol�neas se ha ingresado con �xito!\n\n");
							}

						break;

						case 2:
							precioLatam = pedirFlotante("\nIngrese el precio para Latam: ");
							precioLatam = reingresarFlotante(precioLatam, minimo, "\nError, el precio no puede ser inferior a 1\n", "\nReingrese el precio para Latam: ");
							if(validarEsMayor(precioLatam, minimo) == 1)
							{
								flagLatam = 1;
								printf("\n�El precio para Latam se ha ingresado con �xito!\n");
							}
						break;

						case 3:
							printf("\nVolviendo al men� principal.\n\n");
						break;

						default:
							printf("\nError, opcion no valida, volviendo al men�.\n");

					}
				}
				while(opcionB != 3);

			break;

			case 3:
				if(flagKm == 1 && flagAerolineas == 1 && flagLatam == 1 )
				{
					debitoAerolineas = calcularDescuento(precioAerolineas, descuento);
					creditoAerolineas = calcularAumento(precioAerolineas, aumento);
					bitCoinAerolineas = dividirFlotante(precioAerolineas, bitcoin);
					aerolineasPorKm = dividirFlotante(precioAerolineas, km);

					debitoLatam = calcularDescuento(precioLatam, descuento);
					creditoLatam = calcularAumento(precioLatam, aumento);
					bitCoinLatam = dividirFlotante(precioLatam, bitcoin);
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
						printf("\n�ERROR! No se han ingresado Kil�metros.\n");
					}

					if(flagAerolineas == 0)
					{
						printf("\n�ERROR! No se han ingresado precios para Aerolineas.\n");
					}

					if(flagAerolineas == 0)
					{
						printf("\n�ERROR! No se han ingresado precios para Latam.\n");
					}

				}
 			break;

			case 4:
				if(flagCalculos == 1)
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
				else
				{
						printf("\n�ERROR! Faltan datos para realizar las operaciones.\n");
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
				salir = pedirLetra("Desea salir? 'S' o 'N' ");
				salir = reingresarChar(salir, 'S', 'N', "�ERROR! Opci�n no valida.", "Desea salir? 'S' para si, o 'N' para No.");
				if((salir == 'S') == 1)
				{
					printf("�Gracias, vuelva pronto!");
				}
			break;

			default:
				printf("\n�ERROR! Opcion no valida, volviendo al men�.\n");

		}



	}while(salir == 'N');

	return EXIT_SUCCESS;
}
