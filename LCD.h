
// Function Declarations for Generic Functions.c

#ifndef __LCD
#define __LCD

// Define Pins
#define LCD_E    			RD0     // Enable pin for LCD
#define LCD_RS	 			RD1     // RS pin for LCD
#define LCD_Data_Bus_D4		RD4		// Data bus bit 4
#define LCD_Data_Bus_D5		RD5		// Data bus bit 5
#define LCD_Data_Bus_D6		RD6		// Data bus bit 6
#define LCD_Data_Bus_D7		RD7		// Data bus bit 7

// Define Pins direction registrers
#define LCD_E_Dir     			TRISD0
#define LCD_RS_Dir   	 		TRISD1
#define LCD_Data_Bus_Dir_D4   	TRISD4
#define LCD_Data_Bus_Dir_D5     TRISD5
#define LCD_Data_Bus_Dir_D6  	TRISD6
#define LCD_Data_Bus_Dir_D7 	TRISD7

// Define which port is being used for data bus
#define LCD_PORT	PORTD

// Constants
#define E_Delay       500  


// Function Declarations
void WriteCommandToLCD(unsigned char);
void WriteDataToLCD(char);
void InitLCD(void);
void WriteStringToLCD(const char*);
void ClearLCDScreen(void);


#endif