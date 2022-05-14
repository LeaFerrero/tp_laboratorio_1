/*
 * entradas.c
 *
 *  Created on: 1 may. 2022
 *      Author: wilo waiko
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "entradas.h"

/// @fn int getString(char[], int)
/// @brief Lee del buffer de entrada hasta que encuantra un '\n' o hasta que haya copiado en cadena
/// un valor maximo de 'longitud - 1' caracteres.
///
/// @param cadena Array donde se cargar el texto ingresado
/// @param longitud Longitud que define el tamaño de cadena
/// @return Retorna 0 si se obtiene una cadena y -1 si no
int getString(char cadena[], int longitud)
{
	int retorno;

	retorno = -1;
	char auxiliar[5099];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(auxiliar, sizeof(auxiliar), stdin) != NULL)
		{
			if(auxiliar[strnlen(auxiliar, sizeof(auxiliar)) - 1] == '\n')
			{
				auxiliar[strnlen(auxiliar, sizeof(auxiliar)) - 1] = '\0';
			}
			if(strnlen(auxiliar, sizeof(auxiliar)) <= longitud)
			{
				strncpy(cadena, auxiliar, longitud);
				retorno = 0;
			}
		 }
	 }
	return retorno;
}

/// @fn int esNumerico(char[], int)
/// @brief Verifica si el valor recibido es numerico, positivo o negativo
///
/// @param cadena cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return 1 si es nœmerico y 0 si no lo es
int esNumerico(char cadena[], int longitud)
{
	int retorno;
   	int i;
   	retorno = 1;
 	for(i = 0; i < longitud && cadena[i] != '\0'; i++)
    {

    	if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
    	{
    		continue;
    	}
    	if(!isdigit(cadena[i]))
    	{
    		retorno = 0;
    		break;
    	}

   }
   return retorno;
}

/// @fn int getInt(void)
/// @brief Verifica si la cadena ingresada es numerica entera, si lo es,
/// convierte la cadena en numero entero y lo retorna.
///
/// @return Retorna el numero entero.
int getInt(void)
{
	int retorno;
	char auxiliar[50];
	if(getString(auxiliar, sizeof(auxiliar)) == 0 && esNumerico(auxiliar, sizeof(auxiliar)))
	{
		retorno = atoi(auxiliar);
	}
	return retorno;
}


/// @fn int esNumerico(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letras, aceptando puntos y/o comas.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena.
/// @return 1 si es nœmerico y 0 si no lo es
int esSoloLetras(char cadena[], int longitud)
{
    int retorno;
    int i;

    retorno = 1;
    for(i = 0; i < longitud && cadena[i] != '\0'; i++)
    {
    	if(cadena[i] == '.' || cadena[i] == ',' || cadena [i] == 'ñ')
    	{
    		continue;
    	}
        if(cadena[i] != ' ' && !isalpha(cadena[i]))
        {
        	retorno = 0;
        	break;
        }
    }

    return retorno;
}

/// @fn int esAlfaNumerico(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letras y/o numeros.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena.
/// @return 1 si es alfa nœmerica y 0 si no lo es
int esAlfaNumerico(char cadena[], int longitud)
{
    int retorno;
    int i;

    retorno = 1;
    for(i = 0; i < longitud && cadena[i] != '\0'; i++)
    {
        if(!isalpha(cadena[i]) && !isdigit(cadena[i]))
        {
        	retorno = 0;
        	break;
        }
    }

    return retorno;
}

/// @fn int getStringLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta solo por letras,
/// de ser asi la copia.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return Retorna 1 si la cadena esta compuesta solo por letras y 0 si no
int getStringLetras(char cadena[], int longitud)
{
	int retorno;
	char auxiliar[51];
	retorno = 0;
	if(getString(auxiliar, sizeof(auxiliar)) == 0 && esSoloLetras(auxiliar, sizeof(auxiliar)))
	{
		if(strnlen(auxiliar, sizeof(auxiliar)) <= longitud)
		{
			strncpy(cadena, auxiliar, longitud);
			retorno = 1;
		}
	}
	return retorno;
}

/// @fn int esNumericoFlotante(char[], int)
/// @brief Verifica si el valor recibido es numérico flotantes, positivo o negativo
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud
/// @return 1 si es númerico y 0 si no lo es
int esNumericoFlotante(char cadena[], int longitud)
{
	int retorno;
	int flagPunto;

	retorno = 1;
	flagPunto = 0;
	for(int i = 0; i < longitud && cadena[i] != '\0'; i++)
	{
    	if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
    	{
    		continue;
    	}
		if (cadena[i] == '.' && flagPunto == 0)
		{
			flagPunto = 1;
			continue;
		}
		if(!isdigit(cadena[i]))
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/// @fn int getInt(void)
/// @brief Verifica si la cadena ingresada es numerica flotante, si lo es,
/// convierte la cadena en flotante y la retorna.
///
/// @return  El numero entero.
float getFloat(void)
{
	float retorno;
	char auxiliar[50];
	if(getString(auxiliar, sizeof(auxiliar)) == 0 && esNumericoFlotante(auxiliar, sizeof(auxiliar)))
	{
		retorno = atof(auxiliar);
	}
	return retorno;
}

///@fn int getValidInt(char[], char[], int, int)
///@brief Solicita un numero entero al usuario, luego de verificarlo devuelve el resultado
///@param mensaje Es el mensaje a ser mostrado
///@param mensajeError Es el mensaje de Error a ser mostrado
///@param minimo Es el numero maximo a ser aceptado
///@param maximo Es el minimo minimo a ser aceptado
///@return Retorna el numero entero
int getValidInt(char mensaje[], char mensajeError[], float minimo, float maximo)
{
	int numero;

	printf("%s: ", mensaje);
	numero = getInt();

	while(!estaEnRangoInt(numero, minimo, maximo))
	{
		printf("%s.\n", mensajeError);
		printf("%s: ", mensaje);
		numero = getInt();
	}

	return numero;
}

/// @fn int estaEnRango(int, int, int)
/// @brief Verifica que el numero este debtro del rango
///
/// @param numero El numero a er abalizado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el minimo maximo a ser aceptado
/// @return
int estaEnRangoInt(int numero, int minimo, int maximo)
{
	int retorno;

	retorno = 1;

	if(numero < minimo || numero > maximo)
	{
		retorno = 0;
	}
	return retorno;
}

/// @fn int estaEnRango(float, float, float)
/// @brief Verifica que el numero este debtro del rango
///
/// @param numero El numero a er abalizado
/// @param minimo Es el numero minimo a ser aceptado
/// @param maximo Es el minimo maximo a ser aceptado
/// @return
int estaEnRangoFloat(float numero, float minimo, float maximo)
{
	int retorno;

	retorno = 1;

	if(numero < minimo || numero > maximo)
	{
		retorno = 0;
	}
	return retorno;
}

/// @fn float getValidFloat(char[], char[], int, int)
/// @brief  Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
///
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param minimo Es el numero maximo a ser aceptado
/// @param maximo Es el minimo minimo a ser aceptado
/// @return Retorna el numero flotante
float getValidFloat(char mensaje[], char mensajeError[], int minimo, int maximo)
{
	float numero;

	printf("%s: ", mensaje);
	numero = getFloat();

	while(!estaEnRangoFloat(numero, minimo, maximo))
	{
		printf("%s.", mensajeError);
		printf("\n%s: ", mensaje);
		numero = getFloat();
	}

	return numero;
}

/// @fn int validarFeha(int, int, int)
/// @brief Verifica que la fecha sea valida.
///
/// @param dia El dia de la fecha
/// @param mes	El mes de la fecha
/// @param anio	El anio de la fecha
/// @return 0 si la fecha es invalida y 1 si es valida
int validarFeha(int dia, int mes, int anio)
{
	int retorno;

	retorno = 0;

	switch (mes)
	{
		case 2:
			if(dia <= 28)
			{
				retorno = 1;
			}
			else
			{
				if(((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) && dia <= 29)
				{
					retorno = 1;
				}
			}
		break;

		case 4:
		case 6:
		case 9:
		case 11:
			if(dia <= 30)
			{
				retorno = 1;
			}
		break;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(dia <= 31)
			{
				return 1;
			}
	}
		return retorno;
}

/// @fn void getValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena al usuario compuesta solo por letras
///
/// @param cadena
/// @param longitud Longitud de la cadena.
/// @param mensaje El mensaje a ser mostrado
/// @param mensajeError El mensaje de error a ser mostrado
void getValidStingLetras(char cadena[], int longitud, char mensaje[], char mensajeError[])
{
	printf("%s: ", mensaje);
	while(!getStringLetras(cadena, longitud))
	{
		printf("%s.", mensajeError);
		printf("\n%s: ", mensaje);

	}
}

/// @fn void getValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena alfanumerica al usuario al usuario.
///
/// @param cadena
/// @param longitud Longitud de la cadena.
/// @param mensaje El mensaje a ser mostrado
/// @param mensajeError El mensaje de error a ser mostrado
void getValidStingAlfanumerico(char cadena[], int longitud, char mensaje[], char mensajeError[])
{
	printf("%s: ", mensaje);
	while(!getStringAlfaNumerico(cadena, longitud))
	{
		printf("%s.", mensajeError);
		printf("\n%s: ", mensaje);
	}
}

/// @fn int getStringLetras(char[], int)
/// @brief Verifica si la cadena esta compuesta por letras y/o numeros,
/// de ser asi la copia.
///
/// @param cadena Array con la cadena a ser analizada
/// @param longitud Longitud de la cadena
/// @return Retorna 1 si la cadena esta compuesta solo por letras y 0 si no
int getStringAlfaNumerico(char cadena[], int longitud)
{
	int retorno;
	char auxiliar[51];
	retorno = 0;
	if(getString(auxiliar, sizeof(auxiliar)) == 0 && esAlfaNumerico(auxiliar, sizeof(auxiliar)))
	{
		if(strnlen(auxiliar, sizeof(auxiliar)) <= longitud)
		{
			strncpy(cadena, auxiliar, longitud);
			retorno = 1;
		}
	}
	return retorno;
}

void primeraMayuscula(char cadena[])
{
	int i;
	int cantidad;
	strlwr(cadena);
	cadena[0] = toupper(cadena[0]);

	cantidad = strlen(cadena);

	for(i = 0; i < cantidad; i++ )
	{
		if(cadena[i] == ' ')
		{
			cadena[i+1] = toupper(cadena[i+1]);
		}
	}
}

/// @fn void getValidStingLetras(char[], int, char[], char[])
/// @brief Solicita una cadena al usuario compuesta solo por letras y pasa la primera letra a mayuscula
///
/// @param cadena
/// @param longitud Longitud de la cadena.
/// @param mensaje El mensaje a ser mostrado
/// @param mensajeError El mensaje de error a ser mostrado
void getValidStingLetrasNombre(char cadena[], int longitud, char mensaje[], char mensajeError[])
{
	printf("%s: ", mensaje);
	while(!getStringLetras(cadena, longitud))
	{
		printf("%s.", mensajeError);
		printf("\n%s: ", mensaje);

	}

	primeraMayuscula(cadena);
}

