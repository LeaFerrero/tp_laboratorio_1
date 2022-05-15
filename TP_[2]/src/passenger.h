/*
 * passenger.h
 *
 *  Created on: 10 may. 2022
 *      Author: wilo waiko
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statusFlight.h"
#include "typePassenger.h"
#include "passenger.h"
#include "entradas.h"
#include "menu.h"

#define LIBRE 0
#define OCUPADO 1

struct{

	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}typedef Passenger;

/** INICIALIZAR */
int initPassengers(Passenger* list, int len);

/** HARDCODEO DE PASAJEROS */
int hardcodePassenger(Passenger list[], int len);

/** AÑADIR PASAJERO */
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int loadPassenger(Passenger list[], int len, TypePassenger listType[], int typeLen, StatusFlight listStatus[], int statusLen);

/** BUSCAR POR ID*/
int findPassengerById(Passenger* list, int len,int id);
int getFreeIndex(Passenger list[], int len);
int Passenger_buscarPorIDValido(Passenger list[], int len);
int searchAgain();

/** MOSTRAR */
void showOnePassenger(Passenger list, TypePassenger listType, StatusFlight listStatus);
int printPassenger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus);

/** BAJA */
int downPassenger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus);

/** MODIFICACIONES */
int modifyPassanger(Passenger list[], int len, TypePassenger listType[], int lenType, StatusFlight listStatus[], int lenStatus, int opcion);
Passenger modifyName(Passenger list);
Passenger modifyLastName(Passenger list);
Passenger modifyPrice(Passenger list);
Passenger modifyType(Passenger list, TypePassenger listType[], int lenType);
Passenger modifyCode(Passenger list);
int saveChanges();

/** ORDENAMIENTO */
int sortPassengers(Passenger* list, int len, int order);
int ordenarPasajerosCodigo(Passenger* list, int len, int order);

/** CALCULOS */
int totalPassenger(Passenger list[], int len);
float totalImportePassenger(Passenger list[], int len);
float promedioImportePassenger(Passenger list[], int len);
int superiorPromedioPassenger(Passenger list[], int len);
void informarPrecio(Passenger list[], int len);



#endif /* PASSENGER_H_ */
