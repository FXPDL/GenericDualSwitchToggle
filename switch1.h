/* 
 * File:   switch1.h
 * Author: Nancy
 *
 * Created on December 18, 2016, 10:38 PM
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
#include "system.h"
#include "mcc_generated_files/hardware_controls.h"





void initSwitch1(void);
void updateSwitch1(void);
void setSwitch1State(int);
