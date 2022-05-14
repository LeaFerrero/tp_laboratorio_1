/*
 * operaciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Leandro Ferrero
 */


/// @fn float sumarFlotante(int, int)
/// @brief Fecive dos flotante, los suma y retorna el resultado.
///
/// @param numeroUno Primer flotante que va a ser sumado.
/// @param numeroDos Segundo flotante a ser sumado.
/// @return el resultado de la suma.
float sumar(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno +numeroDos;

	return resultado;
}

/// @fn float restarFlotante(float, float)
/// @brief Recibe dos flotantes, al primero se le resta el segundo y devuelve el resultado..
///
/// @param numeroUno Es el minuendo
/// @param numeroDos Es el sustraendo.
/// @return la diferencia de la resta.
float restar(float numeroUno, float numeroDos)
{
	float  resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}

/// @fn float multilicarFlotante(float, float)
/// @brief Recibe un flotante y un entero, multiplica el primero por el segundo.
///
/// @param numeroUno El multiplicando.
/// @param numeroDos El multiplicador.
/// @return el producto de la multiplicacion.
float multilicar(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

/// @fn float dividirFlotante(float, float)
/// @brief Recibe dos flotantes, divide el primero por el segundo y retorna el resultado.
///
/// @param numeroUno Es el dividendo.
/// @param numeroDos Es el divisor.
/// @return El cociente.
float dividir(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
}

/// @fn float calcularDescuento(float, int)
/// @brief Recibe un flotante y un entero, calcula el porcentaje de descuento y retorna el resultado con el descuento aplicado
/// llama a la funncion multiplicar que recibe
///
/// @param numero El numero al que se le va a calcular el porcentaje de descuento.
/// @param porcentaje El porcentaje que se va a descontar.
/// @return El resultado con el descuento aplicado.
float calcularDescuento(float numero, int porcentaje)
{
	float numeroDescontado;
	float numeroConDescuento;

	numeroDescontado = multilicar(numero, porcentaje) / 100;
	numeroConDescuento = restar(numero, numeroDescontado);

	return numeroConDescuento;
}

/// @fn float calcularAumento(float, int)
/// @brief Recibe un flotante y un entero, calcula el porcentaje de aumento y retorna el resultado con el aumento aplicado
///
/// @param numero El numero al que se le va a calcular el aumento.
/// @param porcentaje El porcentaje que se le va a sumar.
/// @return El resultado con el aumento aplicado.
float calcularAumento(float numero, int porcentaje)
{
	float numeroAumentado;
	float numeroConAumento;

	numeroAumentado = multilicar(numero, porcentaje) / 100;
	numeroConAumento = sumar(numero, numeroAumentado);

	return numeroConAumento;
}


