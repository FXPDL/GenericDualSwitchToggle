/* 
 * File:   switch2.h
 * Author: Nancy
 *
 * Created on December 18, 2016, 10:39 PM
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
#include "system.h"
#include "mcc_generated_files/hardware_controls.h"



void initSwitch2(void);
void updateSwitch2(void);
void setSwitch2State(int);
void setSwitch2OffStart(void);
void setSwitch2OffFinish(void);
