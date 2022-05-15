/*
 * entradas.h
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */

#ifndef ENTRADAS_H_
#define ENTRADAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int getString(char[], int);
int esNumerico(char str[], int);
int getInt(void);
int estaEnRangoInt(int numero, int minimo, int maximo);
int getValidInt(char mensaje[], char mensajeError[], float minimo, float maximo);
int esNumericoFlotante(char str[], int limite);
float getFloat(void);
int estaEnRangoFloat(float numero, float minimo, float maximo);
float getValidFloat(char mensaje[], char mensajeError[], int minimo, int maximo);
int esSoloLetras(char str[], int limite);
int getStringLetras(char str[], int longitud);
void getValidStingLetras(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int getStringAlfaNumerico(char cadena[], int longitud);
int esAlfaNumerico(char cadena[], int longitud);
void getValidStingAlfanumerico(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int esSoloLetrasNombre(char cadena[], int longitud);
int getStringNombre(char cadena[], int longitud);
void primeraMayuscula(char cadena[]);
void getValidStingLetrasNombre(char cadena[], int longitud, char mensaje[], char mensajeError[]);

#endif /* ENTRADAS_H_ */
