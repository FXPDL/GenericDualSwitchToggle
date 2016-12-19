/* 
 * File:   switch2.h
 * Author: Nancy
 *
 * Created on August 1, 2016, 8:16 PM
 */

#ifndef SWITCH2_H
#define	SWITCH2_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* SWITCH2_H */

#include <stdint.h>        /* For uint8_t definition */
#include "../system.h"
#include "hardware_controls.h"

#define Switch2_LED  LATCbits.LATC5
#define Switch2_Stomp PORTAbits.RA5
#define Relay_Switch2 LATCbits.LATC0
#define Relay_Switch20 LATCbits.LATC4

void initSwitch2(void);
void updateSwitch2(void);
void setSwitch2State(int);
