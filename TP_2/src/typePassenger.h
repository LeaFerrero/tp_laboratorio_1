/*
 * typePassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: wilo waiko
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include <stdio.h>
#include <string.h>
#include "entradas.h"

struct{

	int idTypePassenger;
	char nameTypePassenger[51];

}typedef TypePassenger;

void hardcodeTypePassenger(TypePassenger list[], int len);
void showTypePassenger(TypePassenger list[], int len);
int loadTypePassenger(TypePassenger list[], int len);

#endif /* TYPEPASSENGER_H_ */
