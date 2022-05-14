/*
 * entradas.h
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */

#ifndef ENTRADAS_H_
#define ENTRADAS_H_

int getString(char[], int);
int esNumerico(char str[], int); //v
int getInt(void);
int esSoloLetras(char str[], int limite); //v
int getStringLetras(char str[], int longitud);
int esNumericoFlotante(char str[], int limite);//v
float getFloat(void);
int estaEnRangoInt(int numero, int minimo, int maximo);//v
int estaEnRangoFloat(float numero, float minimo, float maximo);
int getValidInt(char mensaje[], char mensajeError[], float minimo, float maximo);
float getValidFloat(char mensaje[], char mensajeError[], int minimo, int maximo);
int validarFeha(int dia, int mes, int anio);
void getValidStingLetras(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int getStringAlfaNumerico(char cadena[], int longitud);
void getValidStingAlfanumerico(char cadena[], int longitud, char mensaje[], char mensajeError[]);
int esAlfaNumerico(char cadena[], int longitud);
void primeraMayuscula(char cadena[]);
void getValidStingLetrasNombre(char cadena[], int longitud, char mensaje[], char mensajeError[]);

#endif /* ENTRADAS_H_ */
