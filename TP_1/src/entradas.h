/*
 * entradas.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef ENTRADAS_H_
#define ENTRADAS_H_

float pedirFlotante(char mensaje[]);

char pedirLetra(char mensaje[]);

float reingresar(float numero, int aComparar, char mensajeUno[], char mensajeDos[]);

#endif /* ENTRADAS_H_ */
