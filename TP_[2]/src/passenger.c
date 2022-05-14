/*
 * passenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: wilo waiko
 */

#include <string.h>
#include "passenger.h"
#include "entradas.h"
#include "menu.h"

/// @fn int Passenger_ObtenerID(void)
/// @brief Genera una id de manera privada.
///
/// @return
static int Passenger_ObtenerID(void);
static int Passenger_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION Passenger_ObtenerID();
	static int Passenger_idIncremental = 0;
	return Passenger_idIncremental++;
}


/// @fn int initPassengers(Passenger*, int)
/// @brief Para indicar que todas las posiciones del array estan vacias,
/// esta funcion pone isEmpty en LIBRE (0), en todas las posiciones.
///
/// @param list puntero al array de pasajeros.
/// @param len tamaño del array
/// @return Retorna -1 si hubo un error o 0 si inicializo.
int initPassengers(Passenger* list, int len)
{
	int retorno;
	int i;

	retorno = -1;
	if (list != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok

Programación I – Laboratorio I

UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 5
*/
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno;
	int index;

	//BUSCO ESPACIO EN ARRAY
	index = getFreeIndex(list, len);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//GUARDO EN LISTA EN LA POSICION LIBRE QUE RECIBI LOS VALORES QUE ME LLEGARON
		list[index].id = id;
		strcpy(list[index].name, name);
		strcpy(list[index].lastName, lastName);
		list[index].price = price;
		list[index].typePassenger = typePassenger;
		strcpy(list[index].flycode, flycode);
		list[index].statusFlight = statusFlight;
		list[index].isEmpty = OCUPADO;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 1;
	}

	return retorno;

}

/// @fn int getFreeIndex(Passenger[], int)
/// @brief Reccorre el array de pasajeros, si hay un indice libre lo retona.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array
/// @return Retorna -1 si no pudo obtener el indice, o el indice si pudo otenerlo.
int getFreeIndex(Passenger list[], int len)
{
	int retorno;
	int i;

	retorno = -1;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (list[i].isEmpty == LIBRE)
			{
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @fn int loadPassenger(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief
///
/// @param list
/// @param len
/// @param listType
/// @param typeLen
/// @param listStatus
/// @param statusLen
/// @return
int loadPassenger(Passenger list[], int len, TypePassenger listType[], int typeLen, StatusFlight listStatus[], int statusLen)
{
	int retorno;
	int id;
	char name[51];
	char lastName[51];
	char flycode[10];
	float price;
	int typePassenger;
	int statusFlight;

	id = Passenger_ObtenerID();
	getValidStingLetrasNombre(name, sizeof(name), "Ingrese su nombre", "Error");
	getValidStingLetrasNombre(lastName, sizeof(lastName), "Ingrese su apellido", "Error");
	getValidStingAlfanumerico(flycode, sizeof(flycode), "El codigo de vuelo", "Error");
	price = getValidFloat("Ingrese el precio", "Error, monto no valido", 1, 200000);
	typePassenger = loadTypePassenger(listType, typeLen);
	statusFlight = loadstatusFlight(listStatus, statusLen);

	if(addPassenger(list, len, id, name, lastName, price, typePassenger, flycode, statusFlight))
	{
		retorno = 1;
	}

	return retorno;
}


/// @fn int findPassengerById(Passenger*, int, int)
/// @brief Encuentra a un pasajero por el id y retorna la posicion del array.
///
/// @param list Puntero al array de pasajeros.
/// @param len Tamaño del array-
/// @param id ID del pasajeo a buscar.
/// @return Retorna la posicion del indice del pasajero o -1 si el tamaño
/// del array es invalido, o el puntero apunta a NULL o no encontro pasajero
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno;
	int i;

	retorno = -1;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(list != NULL && len > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (list[i].id == id  && list[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


/// @fn int Passenger_buscarPorIDValido(Passenger[], int)
/// @brief
///
/// @param list
/// @param len
/// @return
int Passenger_buscarPorIDValido(Passenger list[], int len)
{
	int id;
	int index;
	int opcion;
	int retorno;

	retorno = -1;
	do
	{
		printf("\nIngrese ID: ");
		id = getInt();
		index = findPassengerById(list, len, id);
		if(index == -1)
		{
			printf("\nID no encontrado.");
			opcion = mostrarMenuSN("¿Ingresar otro ID?");
			switch(opcion)
			{
				case 1:
					continue;
				break;
				case 2:
					break;
				break;
			}
		}
		else
		{
			retorno = index;
		}
	}
	while(retorno == -1 && opcion != 2);

	return retorno;
}

/// @fn void showOnePassenger(Passenger, TypePassenger, StatusFlight)
/// @brief Imprime por pantalla un pasajero.
///
/// @param list
/// @param listType
/// @param listStatus
void showOnePassenger(Passenger list, TypePassenger listType, StatusFlight listStatus)
{
	//PRINTF DE UN SOLO Gen
	printf("\n%5d\t\t%s\t\t%s\t\t%.2f\t\t%s\t\t%s\t\t%s", list.id, list.name, list.lastName, list. price, list.flycode, listType.nameTypePassenger, listStatus.nameStatus );
}

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
/// @fn int printPassenger(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief Imprime por pantalla el contenido del array de pasajeros.
///
/// @param list Array que contien los pasajeros.
/// @param len Tamaño del array de pasajeros.
/// @param listType Array que contiene los tipos de pasajeros.
/// @param lenType Tamaño del array de los tipos de pasajeros.
/// @param listStatus Array que contiene el estado de los vuelos.
/// @param lenStatus Tamaño del array que contiene el estado de los vuelos.
/// @return
int printPassenger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus)
{
	int i;
	int retorno = 0;
	int cantidad = 0;

	//CABECERA
	printf("\n%5s%20s\t\t%s\t\t%s\t\t%s\t\t%s\t\t\%s", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO DE VUELO", "CLASE", "ESTADO");


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (list != NULL && len > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < len; i++)
		{
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (list[i].isEmpty == OCUPADO)
			{
				//MUESTRO UN SOLO Gen
				showOnePassenger(list[i], listType[list[i].typePassenger], listStatus[list[i].statusFlight]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO PASAJEROS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno;
	int i;

	retorno = -1;

	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].id == id)
		{
			list[i].isEmpty = LIBRE;
			retorno = 0;
		}
	}

	return retorno;
}

/// @fn int downPassenger(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief
///
/// @param list
/// @param len
/// @param listType
/// @param lenType
/// @param listStatus
/// @param lenStatus
/// @return
int downPassenger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus)
{
	int retorno = 0;
	int flag = 0;
	int index;

	//LISTO TODOS LOS ALBUMS
	if(printPassenger(list, len, listType, lenType, listStatus, lenStatus))
	{
		//BANDERA EN 1 SI HAY ALBUMS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY ALBUMS PARA DAR DE BAJA
	if (flag)
	{
		//PIDO ID A DAR DE BAJA
		//OBTENGO INDEX DEL ARRAY DE ALBUMM A DAR DE BAJA
		index = Passenger_buscarPorIDValido(list, len);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		 if(removePassenger(list, len, list[index].id) == 0)
		 {
			//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			retorno = 1;
		 }
	}
	return retorno;
}

/// @fn int modifyPassanger(Passenger[], int, TypePassenger[], int, StatusFlight[], int, int)
/// @brief
///
/// @param list
/// @param len
/// @param listType
/// @param lenType
/// @param listStatus
/// @param lenStatus
/// @param opcion
/// @return
int modifyPassanger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus, int opcion)
{
	int retorno;
	int index;
	int flag = 0;
	Passenger auxiliar;


	//LISTO TODOS LOS Gen
	if(printPassenger(list, len, listType, lenType, listStatus, lenStatus))
	{
		//BANDERA EN 1 SI HAY ALBUMS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//OBTENGO INDEX DEL ARRAY DE ALBUMS A MODIFICAR
		index = Passenger_buscarPorIDValido(list, len);

		//COPIO EL CONTENIDO DEL ARRAY EN EL AUXILIAR PARA MODIFICAR LO QUE NECESITE
		auxiliar = list[index];

		//DEPENDIENDO DE LO SELECIONADO EN EL MENU, MODIFICA EL TITULO, EL IMPORTE O LA FECHA
		switch(opcion)
		{
			case 1:
				auxiliar = modifyName(auxiliar);
				if(saveChanges(list, auxiliar, index))
				{
					retorno = 1;
				}
			break;

			case 2:
				auxiliar = modifyLastName(auxiliar);
				if(saveChanges(list, auxiliar, index))
				{
					retorno = 1;
				}
			break;

			case 3:
				auxiliar = modifyPrice(auxiliar);
				if(saveChanges(list, auxiliar, index))
				{
					retorno = 1;
				}
			break;

			case 4:
				auxiliar = modifyType(auxiliar, listType, lenType);
				if(saveChanges(list, auxiliar, index))
				{
					retorno = 1;
				}
			break;
			case 5:
				auxiliar =  modifyCode(auxiliar);
				if(saveChanges(list, auxiliar, index))
				{
					retorno = 1;
				}
			break;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		}
	}

	return retorno;
}

// o Nombre o Apellido o Precio o Tipo de pasajero o Código de vuelo

Passenger modifyName(Passenger list)
{
	getValidStingLetrasNombre(list.name, sizeof(list.name), "Ingrese un nuevo nombre", "Error");
	return list;
}

Passenger modifyLastName(Passenger list)
{
	getValidStingLetrasNombre(list.lastName, sizeof(list.lastName), "Ingrese un nuevo pellido", "Error");
	return list;
}

Passenger modifyPrice(Passenger list)
{
	list.price = getValidFloat("\nIngrese el nuevo importe", "Error, importe no valido" , 1, 200000);

	return list;
}

Passenger modifyType(Passenger list, TypePassenger listType[], int lenType)
{
	list.typePassenger = loadTypePassenger(listType, lenType);
	return list;
}

Passenger modifyCode(Passenger list)
{
	getValidStingAlfanumerico(list.name, sizeof(list.name), "Ingrese un nuevo codigo", "Error. codigo no valido");
	return list;
}

int saveChanges(Passenger list[], Passenger auxiliar, int index)
{
	int retorno;
	int opcionCambios;

	opcionCambios = mostrarMenuSN("¿Confirmar Cambios?");
	switch(opcionCambios)
	{
		case 1:
			list[index] = auxiliar;
			retorno = 1;
		break;
		case 2:
			retorno = 0;
		break;
		default:
		printf("Opcion no valida");
	}

	return retorno;
}

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order)
{
		int retorno;
		int i;
		int j;
		Passenger auxiliar;

		retorno = 0;
		/** EJEMPLO DE SORT CON ID DE Gen
		    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
		    CASE 1 -> MENOR A MAYOR (ASCENDENTE)
		    CASE 0 -> MAYOR A MENOR (DESCENDENTE)
		    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
		*/

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (list != NULL && len > 0)
		{
			switch (order)
			{
				case 1:
					for (i = 0; i < len - 1; i++)
					{
						for (j = i + 1; j < len; j++)
						{
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
							{
								//PRIME CRITERIO DE ORDENAMIENTO, POR APELLIDO
								if (strcmp(list[i].lastName, list[j].lastName) > 0)
								{
									//INTERCAMBIO POSICIONES EN ARRAY
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
									//SI HAY DOSAPPELLIDOS IGUALES
								if(strcmp(list[i].lastName, list[j].lastName) == 0)
								{
									//SEGUNDO CRITERIO, POR TIPO
									if(list[i].typePassenger >  list[j].typePassenger)
									{
										//INTERCAMBIO LAS POSICIONES
										auxiliar = list[i];
										list[i] = list[j];
										list[j] = auxiliar;
									}
								}
							}
						}
					}
				retorno = 1;
				break;

			}
		}
	return retorno;
}

int totalPassenger(Passenger list[], int len)
{
	int totalPassenger;
	int i;
	totalPassenger = 0;

	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			totalPassenger ++;
		}
	}

	return totalPassenger;
}

float totalImportePassenger(Passenger list[], int len)
{
	int totalImporte;
	int i;

	totalImporte = 0;
	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			totalImporte += list[i].price;
		}
	}

	return totalImporte;
}

float promedioImportePassenger(Passenger list[], int len)
{
	float promedio;
	float totalImporte;
	int totalAlbums;

	totalImporte = totalImportePassenger(list, len);
	totalAlbums = totalPassenger(list, len);

	if(totalAlbums > 0)
	{
		promedio = totalImporte / totalAlbums;
	}

	return promedio;
}

int superiorPromedioPassenger(Passenger list[], int len)
{
	float promedio;
	int i;
	int cantidad;

	cantidad = 0;
	promedio = promedioImportePassenger(list, len);

	for(i = 0; i < len; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].price > promedio)
		{
			cantidad ++;
		}
	}
	return cantidad;
}

void informarPrecio(Passenger list[], int len)
{
	float totalImporte;
	float promedio;
	int superiorPromedio;

	totalImporte = totalImportePassenger(list, len);
	promedio = promedioImportePassenger(list, len);
	superiorPromedio =  superiorPromedioPassenger(list, len);

	printf("\nEl precio total de los pasajes es: $%.2f.", totalImporte);
	printf("\nEl promedio de los precios de los pasajes es: $%.2f.", promedio);
	printf("\nHay %d pasajero/os que supera/an el promedio.", superiorPromedio);

}

int ordenarPasajerosCodigo(Passenger* list, int len, int order)
{
		int retorno;
		int i;
		int j;
		Passenger auxiliar;

		retorno = 0;
		/** EJEMPLO DE SORT CON ID DE Gen
		    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
		    CASE 1 -> MENOR A MAYOR (ASCENDENTE)
		    CASE 0 -> MAYOR A MENOR (DESCENDENTE)
		    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
		*/

		//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
		if (list != NULL && len > 0)
		{
			switch (order)
			{
				case 1:
					for (i = 0; i < len - 1; i++)
					{
						for (j = i + 1; j < len; j++)
						{
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
							{
								//PRIME CRITERIO DE ORDENAMIENTO, POR APELLIDO
								if (strcmp(list[i].flycode, list[j].flycode) > 0)
								{
									//INTERCAMBIO POSICIONES EN ARRAY
									auxiliar = list[i];
									list[i] = list[j];
									list[j] = auxiliar;
								}
									//SI HAY DOSAPPELLIDOS IGUALES
								if(strcmp(list[i].flycode, list[j].flycode) == 0)
								{
									//SEGUNDO CRITERIO, POR TIPO
									if(list[i].statusFlight >  list[j].statusFlight)
									{
										//INTERCAMBIO LAS POSICIONES
										auxiliar = list[i];
										list[i] = list[j];
										list[j] = auxiliar;
									}
								}
							}
						}
					}
				retorno = 1;
				break;

			}
		}
	return retorno;
}

