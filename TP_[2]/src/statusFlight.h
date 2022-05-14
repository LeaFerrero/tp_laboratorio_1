/*
 * statusFlight.h
 *
 *  Created on: 13 may. 2022
 *      Author: wilo waiko
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

struct{

	int idStatus;
	char nameStatus[51];

}typedef StatusFlight;

void hardcodestatusFlight(StatusFlight list[], int len);
void showstatusFlight(StatusFlight list[], int len);
int loadstatusFlight(StatusFlight list[], int len);



#endif /* STATUSFLIGHT_H_ */
