/*
 * passenger.c
 *
 *  Created on: 10 may. 2022
 *      Author: wilo waiko
 */

#include "ArrayPassenger.h"

/// @fn int Passenger_ObtenerID(void)
/// @brief Genera una id de manera privada.
///
/// @return Retorna el ID
static int Passenger_ObtenerID(void);
static int Passenger_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION Passenger_ObtenerID();
	static int Passenger_idIncremental = 0;
	return Passenger_idIncremental++;
}

/// @fn void hardcodeTypePassenger(Passenger[], int)
/// @brief Hardcodea 5 pasajeros.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array que contiene los pasajeros.
int hardcodePassenger(Passenger list[], int len)
{
	int retorno;
	int i;
	char name[5][51] = {"Lotus", "Teshin", "Nef", "Cressa", "Ergo"};
	char lastName[5][51] = {"Spacemom", "Dax", "Anyo", "Tal", "Glast"};
	float price[5] = {3000, 1000, 10000, 500, 1000 };
	char flycode[5][10] = {"juaNCit", "ESIUA6sw", "GAbr45pa", "ERn4ndeZ", "Juan17ju"};
	int typePassenger[5] = {1, 2, 0, 3, 2};
	int statusFlight[5] = {0, 0, 3, 1, 2};

	for(i = 0;  i < len; i++)
	{
		list[i].id = Passenger_ObtenerID();
		strcpy(list[i].name, name[i]);
		strcpy(list[i].lastName, lastName[i]);
		list[i].price = price[i];
		strcpy(list[i].flycode, flycode[i]);
		list[i].typePassenger = typePassenger[i];
		list[i].statusFlight = statusFlight[i];
		list[i].isEmpty = OCUPADO;
	}
	retorno = 1;

	return retorno;
}

/// @fn int initPassengers(Passenger*, int)
/// @brief Para indicar que todas las posiciones del array estan vacias,
/// esta funcion pone isEmpty en LIBRE (0), en todas las posiciones.
///
/// @param list Puntero al array de pasajeros.
/// @param len Tamaño del array
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

/// @fn int addPassenger(Passenger*, int, int, char[], char[], float, int, char[], int)
/// @brief Agregar en una lista existente de pasajeros los valores recibidos como parámetros
/// en la primera posición vacía.
///
/// @param list Puntero al array que contiene los pasajeros.
/// @param len Longitud del array que contiene los pasajeros.
/// @param id  ID del pasajero.
/// @param name Nombre del pasajero.
/// @param lastName Apellido del pasajero.
/// @param price Preci del vuelo.
/// @param typePassenger Typo de pasajero.
/// @param flycode Codigo de vuelo.
/// @param statusFlight Estado del vuelo.
/// @return Retorna -1 si hubo un error o 0 si tuvo exito.
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno;
	int index;

	retorno = -1;

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
		retorno = 0;
	}

	return retorno;
}

/// @fn int loadPassenger(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief Pide al usuario que ingrese los datos de un pasajero.
///
/// @param list Array que contiene los pasajeros.
/// @param len Longitud del array de pasajeros.
/// @param listType Array que contiene los tipos de pasajeros.
/// @param typeLen Tamaño del array que contiene los tipos de pasajeros.
/// @param listStatus Array que contiene los estados de vuelo.
/// @param statusLen Tamaño del array que contiene los estados de vuelo.
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

	retorno = 0;
	//PIDO LOS DATOS PARA CADA CAMPO DE LA ESTRUCTURA
	printf("\nINGRESE LOS DATOS\n");
	id = Passenger_ObtenerID();
	getValidStingLetrasNombre(name, sizeof(name), "Ingrese el nombre", "\nError, nombre no valido.\n");
	getValidStingLetrasNombre(lastName, sizeof(lastName), "Ingrese el apellido", "\nError, appelido no valido.\n");
	getValidStingAlfanumerico(flycode, sizeof(flycode), "Ingrese el codigo de vuelo", "\nError, codigo no valido.\n");
	price = getValidFloat("Ingrese el precio", "\nError, monto no valido\n", 1, 200000);
	typePassenger = loadTypePassenger(listType, typeLen);
	statusFlight = loadstatusFlight(listStatus, statusLen);

	if(addPassenger(list, len, id, name, lastName, price, typePassenger, flycode, statusFlight) == 0)
	{
		//SI ADD PASSENGER TUVO EXITO A CARGAR RETORNO 1
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

/// @fn int findPassengerById(Passenger*, int, int)
/// @brief Encuentra a un pasajero por el id y retorna la posicion del array.
///
/// @param list Puntero al array de pasajeros.
/// @param len Tamaño del array.
/// @param id ID del pasajeo a buscar.
/// @return Retorna la posicion del indice del pasajero o -1 si el tamaño
/// del array es invalido, o el puntero apunta a NULL o no encontro pasajero.
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


/// @fn int searchForValidID(Passenger[], int)
/// @brief Le pide al usuario que ingrese un ID, si es valido guarada el indice
/// y lo retorna, si no lre pregunta al usario si quiere buscar otro.
///
/// @param list Array de que contien los pasajeros.
/// @param len Tamaño del array.
/// @return Retorna el indice si lo consigui, si no retorna -1.
int searchForValidID(Passenger list[], int len)
{
	int id;
	int index;
	int retorno;

	retorno = -1;
	do
	{
		//PIDO EL ID
		printf("\nIngrese ID a dar de baja: ");
		id = getInt();
		//BUSCO EL INDICE QUE COINCIDA CON EL ID
		index = findPassengerById(list, len, id);
		//SI EL INDICE ES -1 ES PORQUE NO EXISTE EL ID
		if(index == -1)
		{
			//MUESTRO QUE EL ID NO SE ENCONTRO
			printf("\nID no encontrado.");
			//PREGUNTO SI QUIERE BUSCAR OTR
			if(searchAgain())
			{
				//CONTINUIE PARA SI
				continue;
			}
			else
			{
				//BREAK PARA NO
				break;
			}

		}
		else
		{
			//SI EL INDICE NO ES -1 LO GUARDO EN RETORNO
			retorno = index;
		}
	}
	while(retorno == -1);

	return retorno;
}

/// @fn int searchAgain()
/// @brief Pregunta al usuario si quiere buscar otro ID.
///
/// @return Retorna 1 si la respuesta fue SI o si 0 la respuesta fuen NO.
int searchAgain()
{
	int retorno;
	int opcion;

	do
	{
		opcion = mostrarMenuSN("\n¿Ingresar otro ID?");
			switch(opcion)
			{
				case 1:
					retorno = 1;
				break;

				case 2:
					printf("\nVolviendo al menu de modificaciones\n");
					retorno = 0;
				break;

				default:
					printf("\nOpcion no valida");
			}
	}
	while(opcion != 1 && opcion != 2);

	return retorno;
}

/// @fn void showOnePassenger(Passenger, TypePassenger, StatusFlight)
/// @brief Imprime por pantalla un pasajero.
///
/// @param list Variable de tipo estructura que contiene los datos del pasajero.
/// @param listType Variable del tipo estructura que contiene los datos del tipo de pasajero.
/// @param listStatus Variable del tipo estructuira que contiene los datos de los estados de vuelo.
void showOnePassenger(Passenger list, TypePassenger listType, StatusFlight listStatus)
{
	//PRINTF DE UN SOLO PASAJERO
	printf("%5d %20s %20s %20.2f %20s %20s %20s\n", list.id, list.name, list.lastName, list. price, list.flycode, listType.nameTypePassenger, listStatus.nameStatus );
}


/// @fn int printPassenger(Passenger[], int, TypePassenger[], int, StatusFlight[], int)
/// @brief Imprime por pantalla el contenido del array de pasajeros.
///
/// @param list Array que contien los pasajeros.
/// @param len Tamaño del array de pasajeros.
/// @param listType Array que contiene los tipos de pasajeros.
/// @param lenType Tamaño del array de los tipos de pasajeros.
/// @param listStatus Array que contiene el estado de los vuelos.
/// @param lenStatus Tamaño del array que contiene el estado de los vuelos.
/// @return Retorna 1 si pudo mostrar los pasajeros, 0 si no pudo.
int printPassenger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus)
{
	int i;
	int retorno;
	int cantidad;

	retorno = 0;
	cantidad = 0;
	//CABECERA
	printf("\n%5s %20s %20s %20s %20s %20s %20s\n", "ID", "Nombre", "Apellido", "Precio", "Ccodigo de vuelo", "Clase", "Estado");

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


/// @fn int removePassenger(Passenger*, int, int)
/// @brief Remueve un pasajero por su ID (Pone isEptry en LIBRE (0))
///
/// @param list Puntero que apunta al array de pasajeros.
/// @param len Tamaño del array de pasajeros.
/// @param id ID del pasajero que va a ser removido.
/// @return Retorna 0 si removio al pasajero con exito o -1 si no lo pudo remover.
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
/// @brief Si hay pasajeros los muestra, pide al usuario un ID valido y si esta lo da de baja.
///
/// @param list Array que contien los pasajeros.
/// @param len Tamaño del array de pasajeros.
/// @param listType Array que contiene los tipos de pasajeros.
/// @param lenType Tamaño del array de los tipos de pasajeros.
/// @param listStatus Array que contiene el estado de los vuelos.
/// @param lenStatus Tamaño del array que contiene el estado de los vuelos.
/// @return Retorna 1 si dio de baja con exito o 0 si no tuvo extito.
int downPassenger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus)
{
	int retorno;
	int flag;
	int index;

	retorno = 0;
	flag = 0;
	//LISTO TODOS LOS PASAJEROS
	if(printPassenger(list, len, listType, lenType, listStatus, lenStatus))
	{
		//BANDERA EN 1 SI HAY PASAJEROS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY PASAJEROS PARA DAR DE BAJA
	if (flag)
	{
		//OBTENGO INDICE DEL ARRAY DE PASAJEROS A DAR DE BAJA
		index = searchForValidID(list, len);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		if(index != -1 &&saveChanges())
		{
			//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			 if(removePassenger(list, len, list[index].id) == 0)
			 {
				//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
				retorno = 1;
			 }
		}
	}
	return retorno;
}

/// @fn int modifyPassanger(Passenger[], int, TypePassenger[], int, StatusFlight[], int, int)
/// @brief Muestra la lista de pasajeros (si hay), pide al usuario que ingrese un ID, si el ID es valido
/// Modifica un pasajero en base a la opcion elegida(1 Nombre, 2, apellido, 3 precio de vuelo,
/// 4 tipo de pasajero, 4 Codigo de vuelo). Una vez modificado pregunta al usuario si desea guardar los cambios.
///
/// @param list Array que contien los pasajeros.
/// @param len Tamaño del array de pasajeros.
/// @param listType Array que contiene los tipos de pasajeros.
/// @param lenType Tamaño del array de los tipos de pasajeros.
/// @param listStatus Array que contiene el estado de los vuelos.
/// @param lenStatus Tamaño del array que contiene el estado de los vuelos.
/// @param opcion Opcion elegida.
/// @return Retorna 1 si se pudo modificar con exito, o 0 si no se pudo modificar.
int modifyPassanger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus, int opcion)
{
	int retorno;
	int index;
	int flag;
	Passenger auxiliar;

	flag = 0;
	retorno = 0;
	//LISTO TODOS LOS PASAJEROS
	if(printPassenger(list, len, listType, lenType, listStatus, lenStatus))
	{
		//BANDERA EN 1 SI HAY ALBUMS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY PASAJEROS PARA MODIFICAR
	if (flag)
	{

		//OBTENGO INDEX DEL ARRAY DE PASAJEROS A MODIFICAR
		index = searchForValidID(list, len);

		//SI EL INDEX ES DISTINTO A -1
		if(index != -1)
		{
			//COPIO EL CONTENIDO DEL ARRAY EN EL AUXILIAR PARA MODIFICAR LO QUE NECESITE
			auxiliar = list[index];

			//DEPENDIENDO DE LO SELECIONADO EN EL MENU, MODIFICA NOMBRE, APELLIDO, PRECIO,  TIPO O CODIGO DE VUELO
			switch(opcion)
			{
				case 1:
					auxiliar = modifyName(auxiliar);
					if(saveChanges())
					{
						list[index] = auxiliar;
						retorno = 1;
					}
				break;

				case 2:
					auxiliar = modifyLastName(auxiliar);
					if(saveChanges())
					{
						list[index] = auxiliar;
						retorno = 1;
					}
				break;

				case 3:
					auxiliar = modifyPrice(auxiliar);
					if(saveChanges())
					{
						list[index] = auxiliar;
						retorno = 1;
					}
				break;

				case 4:
					auxiliar = modifyType(auxiliar, listType, lenType);
					if(saveChanges())
					{
						list[index] = auxiliar;
						retorno = 1;
					}
				break;
				case 5:
					auxiliar =  modifyCode(auxiliar);
					if(saveChanges())
					{
						list[index] = auxiliar;
						retorno = 1;
					}
				break;

			//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
			}
		}
	}

	return retorno;
}


/// @fn Passenger modifyName(Passenger)
/// @brief Modifica el nombre de un pasajero.
///
/// @param list Variable del tipo estructura que contiene el nombre.
/// @return Retorna la estructura con el nombre modificado.
Passenger modifyName(Passenger list)
{
	getValidStingLetrasNombre(list.name, sizeof(list.name), "Ingrese un nuevo nombre", "Error");
	return list;
}

/// @fn Passenger modifyLastName(Passenger)
/// @brief Modifica el apellido del pasajero.
///
/// @param list Variable del tipo estructura que contiene el apellido.
/// @return Retorna la estructura con el apellido modificado.
Passenger modifyLastName(Passenger list)
{
	getValidStingLetrasNombre(list.lastName, sizeof(list.lastName), "Ingrese un nuevo pellido", "Error");
	return list;
}

/// @fn Passenger modifyPrice(Passenger)
/// @brief Modifica el precio del vuelo.
///
/// @param list Variable del tipo estructura que contiene el precio.
/// @return Retorna la estructura con el precio modificado.
Passenger modifyPrice(Passenger list)
{
	list.price = getValidFloat("\nIngrese el nuevo importe", "Error, importe no valido" , 1, 200000);

	return list;
}

/// @fn Passenger modifyType(Passenger, TypePassenger[], int)
/// @brief Modifica el tipo de pasajero.
///
/// @param list Variable del tipo estructura que contiene le tipo de pasajero.
/// @param listType Array con los tipos de pasajeros.
/// @param lenType Tamaño del array de los tipos de pasajeros.
/// @return Retorna la estructura con el tipo de pasajero modificado..
Passenger modifyType(Passenger list, TypePassenger listType[], int lenType)
{
	list.typePassenger = loadTypePassenger(listType, lenType);
	return list;
}

/// @fn Passenger modifyCode(Passenger)
/// @brief  Modifica el codigo de vuelo.
///
/// @param list Variable del tipo estructura que contiene el codigo de vuelo.
/// @return Retorna la estructura con el codigo de vuelo modificado.
Passenger modifyCode(Passenger list)
{
	getValidStingAlfanumerico(list.name, sizeof(list.name), "Ingrese un nuevo codigo", "Error. codigo no valido");
	return list;
}

/// @fn int saveChanges()
/// @brief Pregunta al usuario si quiere guardar los cambios.
///
/// @return Retorna 1 si la opcion es SI o 0 si la opcion es NO.
int saveChanges()
{
	int retorno;
	int opcionCambios;

	do
	{
		opcionCambios = mostrarMenuSN("¿Confirmar Cambios?");
		switch(opcionCambios)
		{
			case 1:
				retorno = 1;
			break;
			case 2:
				retorno = 0;
			break;
			default:
			printf("Opcion no valida");
		}
	}
	while(opcionCambios != 1 && opcionCambios != 2);

	return retorno;
}

/// @fn int sortPassengers(Passenger*, int, int)
/// @brief Ordena los elementos el array de pasajeros, el
/// indicar orden ARRIBA o ABAJO
///
/// @param list Puntero al array de pasajeros.
/// @param len Tamaño del array.
/// @param order Orden en el que se va a ordenar, 1 Ascendente, 0 Descendente
/// @return  Retorna 1 si pudo ordenarlos o 0 si no pudo.
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

				case 0:
					for (i = 0; i < len - 1; i++)
					{
						for (j = i + 1; j < len; j++)
						{
							//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
							if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
							{
								//PRIME CRITERIO DE ORDENAMIENTO, POR APELLIDO
								if (strcmp(list[i].lastName, list[j].lastName) < 0)
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
									if(list[i].typePassenger <  list[j].typePassenger)
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

/// @fn int sortPassengers(Passenger*, int, int)
/// @brief Ordena los elementos el array de pasajeros, el
/// indicar orden ARRIBA o ABAJO
///
/// @param list Puntero al array de pasajeros.
/// @param len Tamaño del array.
/// @param order Orden en el que se va a ordenar, 1 Ascendente, 0 Descendente
/// @return  Retorna 1 si pudo ordenarlos o 0 si no pudo.
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

				case 0:
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



/// @fn int totalPassenger(Passenger[], int)
/// @brief  Cuenta la cantidad de pasajeros que esten dados de alta.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array que contiene los pasajeros.
/// @return Retorna la cantidad de total de pasajeros.
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

/// @fn float totalImportePassenger(Passenger[], int)
/// @brief Cuenta suma los importes de los pasajeros que esten dados de alta.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array que contiene los pasajeros.
/// @return Retona el importe total.
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

/// @fn float promedioImportePassenger(Passenger[], int)
/// @brief Calcula el promedio de importe de los pajeros.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array que contiene los pasajeros.
/// @return Retorna el promedio del importe.
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

/// @fn int superiorPromedioPassenger(Passenger[], int)
/// @brief Cuanta la cantidad de pasajeros que superen el promedio de importe
/// que esten dados de alta.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array que contiene los pasajeros.
/// @return Retorna la cantidad de pasajeros qu superen el promedio.
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

/// @fn void informarPrecio(Passenger[], int)
/// @brief Muestra por pantalla el importe total de todos los pasajeros,
/// eñ promedio del importe y cuantos pasajeros superan el promedio.
///
/// @param list Array que contiene los pasajeros.
/// @param len Tamaño del array que contiene los pasajeros.
void informarPrecio(Passenger list[], int len)

{
	float totalImporte;
	float promedio;
	int superiorPromedio;

	totalImporte = totalImportePassenger(list, len);
	promedio = promedioImportePassenger(list, len);
	superiorPromedio =  superiorPromedioPassenger(list, len);

	printf("\nLISTADO TOTAL, PROMEDIO Y SUPERIORES AL PROMEDIO");
	printf("\nEl precio total de los pasajes es: $%.2f.", totalImporte);
	printf("\nEl promedio de los precios de los pasajes es: $%.2f.", promedio);
	printf("\nHay %d pasajero/os que supera/an el promedio.\n", superiorPromedio);

}


