/*
 * Main file of pio2.X
 * Author: mosee
 *
 * A LED is connected to RA4 and a push-button is connected to RB14.
 * When the button is pressed, the LED is turned on. Otherwise it's turned off.
 * 
 * Created on 27 January 2021, 11:32
 */

/* Changes compared to pio1.X:
 *  - The definition of FCY and the inclusion of libpic30.h were removed:
 *    we don't use __delay_ms()
 *  - The configuration bits definition were moved to configuration.c 
 *    We don't need to modify them and it makes the main file cleaner.
 *    To create a new file:
 *       - go to Files/New Files
 *       - in Categories, select C
 *       - in File Types, select C Source File
 *  - We use the short names to access TRIS, PORT and LAT bits
 */


#include <xc.h>         // Contains SFR variables definition

int main(void) {
    /* Setup
     * Configure RB14 as an input is not mandatory, as it is its default state.
     * There are two main reasons to do it:
     *  - All the pins used appears in the setup, so that reading the
     *    setup code gives an idea of the circuit.
     *  - It may happens that initialisation functions are called in the setup.
     *    These functions (if poorly written), may change the state of SFR */
    _TRISA4 = 0;   // Configure the LED pin as a digital output pin
    _TRISB14 = 1;  // Configure the button pin as a digital input pin

    // Main (infinite) loop
    while(1) {
        /* This creates the software equivalent of a direct connection between
         * LED and the button */
        _LATA4 = _RB14;
    }
    
    return 0;
}
