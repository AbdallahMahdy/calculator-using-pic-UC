
#ifndef __INCLUDES_H
#define __INCLUDES_H

// Define CPU Frequency
// This must be defined, if __delay_ms() or 
// __delay_us() functions are used in the code
#define _XTAL_FREQ   20000000  


#include <htc.h> 
#include "LCD.h"
#include "Keypad.h"

// define Error (to be used inside calculator functions)
#define Error   13

// Some function declarations
int get_num(char);
char get_func(char);
void DispError(int);
void disp_num(int);

#endif