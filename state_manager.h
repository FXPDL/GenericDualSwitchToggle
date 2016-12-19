/* 
 * File:   state_manager.h
 * Author: Nancy
 *
 * Created on August 7, 2016, 6:45 PM
 */

#ifndef STATE_MANAGER_H
#define	STATE_MANAGER_H

#ifdef	__cplusplus
extern "C" {
#endif



#ifdef	__cplusplus
}
#endif

#endif	/* STATE_MANAGER_H */

#include <stdint.h>        /* For uint8_t definition */
#include "HEF.h"

typedef struct {
    int switch1;
    int switch2;
} PedalState;

void initStateManager(void);
PedalState getCurrentState(void);
int getSwitch1State(void);
int getSwitch2State(void);
void updateSwitch1State(int);
void updateSwitch2State(int);
void saveState(void);
