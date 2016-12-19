/* 
 * File:   config_params.h
 * Author: Nancy
 *
 * Created on December 18, 2016, 10:54 PM
 */

#ifndef CONFIG_PARAMS_H
#define	CONFIG_PARAMS_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_PARAMS_H */

#define Switch1_LED LATAbits.LATA2
#define Switch1_Stomp PORTAbits.RA4
#define Relay_Switch110 LATCbits.LATC1
#define Relay_Switch11 LATCbits.LATC2


#define Switch2_LED  LATCbits.LATC5
#define Switch2_Stomp PORTAbits.RA5
#define Relay_Switch21 LATCbits.LATC0
#define Relay_Switch210 LATCbits.LATC4

int long_press_limit = 20000000; 