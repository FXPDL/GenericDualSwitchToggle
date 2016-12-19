/* 
 * File:   switch1.h
 * Author: Nancy
 *
 * Created on August 1, 2016, 7:51 PM
 */

#ifndef SWITCH1_H
#define	SWITCH1_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SWITCH1_H */

#include <stdint.h>        /* For uint8_t definition */
#include "../system.h"
#include "hardware_controls.h"

#define Switch1_LED LATAbits.LATA2

#define Switch1_Stomp PORTAbits.RA4

#define Relay_Switch110 LATCbits.LATC1
#define Relay_Switch11 LATCbits.LATC2



void initSwitch1(void);
void updateSwitch1(void);
void setSwitch1State(int);
