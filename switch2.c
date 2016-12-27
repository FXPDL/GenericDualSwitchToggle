
/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include "state_manager.h"
#include "config_params.h"
#include "switch1.h"
#include "switch2.h"

int switch2_state = -1; //initialize to an invalid value so the initialize will run.
int switch2_pressed = 0;  
int switch2_up = 1;  
int switch2_down = 0;  
int switch2_toggle = 0;
int switch2_turning_on = 0;

void initSwitch2() {
    int initState = getSwitch2State();
    setSwitch2State(initState);
}

void updateSwitch2(void) {

    //http://www.kennethkuhn.com/electronics/debounce.c
    /* Step 1: Update the integrator based on the input signal.  Note that the 
    integrator follows the input, decreasing or increasing towards the limits as 
    determined by the input state (0 or 1). */

    if (Switch2_Stomp == 0) {
        if (switch2_pressed > 0) {
            switch2_pressed--;
        }
    } else if (switch2_pressed < debounce_limit) {
        switch2_pressed++;
    }

    /* Step 2: Update the output state based on the integrator.  Note that the
    output will only change states if the integrator has reached a limit, either
    0 or MAXIMUM. */

    if (switch2_pressed == 0) {
        switch2_down++;       
        
        //The switch is down.  
        //  On a short press:
        //      toggle the switch
        //  On a long press:
        //      turn the switch on (or leave it on if it already was)
        //      turn the other switch off

        //Switch1 was on, so if it is long press then kick in feedback.  If it is short, then turn off the switch1
        if (switch2_down >= long_press_limit) {
            switch2_down = long_press_limit; //try and prevent overflow
            setSwitch1State(0);
            switch2_toggle = 0;
        }
        
        if (switch2_state == 1) {  //Switch was on.
            if (switch2_up == 1) {
                switch2_toggle = 1;
                switch2_turning_on = 0;
            }
            
        } else {
            //switch2 was off, so turn it on
            switch2_turning_on = 1;
            switch2_toggle = 1;
          //  setSwitch2State(1);
        }

        switch2_up = 0;
    } else if (switch2_pressed >= debounce_limit) {
        if (switch2_toggle == 1) {
            setSwitch2State(switch2_turning_on);
        }
        Switch2_LED = switch2_state;
        switch2_turning_on = 0;
        switch2_toggle = 0;
        switch2_up = 1;
        switch2_down = 0;
        switch2_pressed = debounce_limit; /* defensive code if integrator got corrupted */
    }  
}

void setSwitch2State(int f_state) {
    if (switch2_state == f_state) {return;}
    switch2_state = f_state;
    Switch2_LED = f_state;
    Relay_Switch21 = f_state;
    Relay_Switch210 = !f_state;

    wait_ms(relay_delay);

    Relay_Switch21 = 0;
    Relay_Switch210 = 0;

    updateSwitch2State(switch2_state);  
    wait_ms(relay_delay);
}
