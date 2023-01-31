#include "Includes.h"
#include<math.h>
#include <float.h>
#include <stdio.h>

// Configuration word for PIC16F877A
__CONFIG FOSC_HS;
__CONFIG WDTE_OFF;
__CONFIG PWRTE_ON ;
__CONFIG CP_OFF; 
__CONFIG BOREN_ON ;
__CONFIG LVP_OFF; 
__CONFIG CPD_OFF; 
__CONFIG WRT_OFF;
__CONFIG DEBUG_OFF;

void	identifyKey(char);
char ident(char volatile key);
double calc (double,double,char);
void Clear();

double num1;       // First number
char func;    // Function to be performed among two numbers
double num2;       // Second number
double result ; 
char res;
char hit;
int shift=0; 
char ans[16];
int count;
int decimal=0;
char k;
int n=1;

void SystemInit(void){};

// Main function
int main()
{
    InitKeypad();
    InitLCD();
 	{
        WriteCommandToLCD(1);       // clear display 
        WriteCommandToLCD(0x80);    // lcd cursor location 
        __delay_ms(500);
       WriteStringToLCD("Welcome");
			  __delay_ms(2400);
	WriteCommandToLCD(1);       // clear display 
  WriteCommandToLCD(0x80);    // lcd cursor location 

 BEGIN:
		decimal=0;
		
		while(1)
			{ 
				num1 = 0;
				num2 = 0;
				result = 0;
				res=' ';
				func = '+';
				
				hit =GetKey();
				k=ident(hit);
				switch(k)
					{
						case('0'):
							num1=0;
						break;						
						case('1'):
							num1=1;
						break;
						case('2'):
							num1=2;
						break;						
						case('3'):
							num1=3;
						break;
						case('4'):
							num1=4;
						break;						
						case('5'):
							num1=5;
						break;
						case('6'):
							num1=6;
						break;						
						case('7'):
							num1=7;
						break;
					  case('8'):
							num1=8;
						break;						
						case('9'):
							num1=9;
						break;
						case('D'):
							goto BEGIN;
						case('.'):
							break;
						case('w'):
							identifyKey(k);
						goto BEGIN;
						default:
							goto BEGIN;						
					}
				WriteCommandToLCD(1);       // clear display 
        WriteCommandToLCD(0x80);    // lcd cursor location 
					n=1;
				identifyKey(k);
				__delay_ms(500);
					
					operand1:	
				hit =GetKey();
				k=ident(hit);
				switch(k)
					{
						case('0'):
						if(decimal==0){
						num1=(num1*10)+(0);}
						else if(decimal==1){
						num1=(num1)+(0*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;						
						case('1'):
							if(decimal==0){
						num1=(num1*10)+(1);}
						else if(decimal==1){
						num1=(num1)+(1*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;
						case('2'):
							if(decimal==0){
						num1=(num1*10)+(2);}
						else if(decimal==1){
						num1=(num1)+(2*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;						
						case('3'):
							if(decimal==0){
						num1=(num1*10)+(3);}
						else if(decimal==1){
						num1=(num1)+(3*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;
						case('4'):
							if(decimal==0){
						num1=(num1*10)+(4);}
						else if(decimal==1){
						num1=(num1)+(4*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;						
						case('5'):
							if(decimal==0){
						num1=(num1*10)+(5);}
						else if(decimal==1){
						num1=(num1)+(5*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;
						case('6'):
							if(decimal==0){
						num1=(num1*10)+(6);}
						else if(decimal==1){
						num1=(num1)+(6*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;						
						case('7'):
							if(decimal==0){
						num1=(num1*10)+(7);}
						else if(decimal==1){
						num1=(num1)+(7*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;
					  case('8'):
							if(decimal==0){
						num1=(num1*10)+(8);}
						else if(decimal==1){
						num1=(num1)+(8*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;						
						case('9'):
							if(decimal==0){
						num1=(num1*10)+(9);}
						else if(decimal==1){
						num1=(num1)+(9*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto operand1;
						case('D'):
							goto operand1;
						case('+'):
							break;						
						case('x'):
							break;
						case('-'):
							break;
						case('/'):
							break;
						case('E'):
							break;
						case('.'):
							break;
						case('o'):
							break;
						case('*'):
							goto BEGIN;
						case('w'):
							identifyKey(k);
						goto BEGIN;
					  default:
							goto operand1;
					}
				identifyKey(k);
				__delay_ms(500);
					
					operand2:
					decimal=0;
				hit =GetKey();
				k=ident(hit);
				switch(k)
					{
						case('0'):
							num2=0;
						break;						
						case('1'):
							num2=1;
						break;
						case('2'):
							num2=2;
						break;						
						case('3'):
							num2=3;
						break;
						case('4'):
							num2=4;
						break;						
						case('5'):
							num2=5;
						break;
						case('6'):
							num2=6;
						break;						
						case('7'):
							num2=7;
						break;
					  case('8'):
							num2=8;
						break;						
						case('9'):
							num2=9;
						break;
						case('D'):
							goto operand2;
						case('o'):
							identifyKey(k);
							goto operand2;
						case('w'):
							identifyKey(k);
						goto BEGIN;
					  default:
							goto operand2;							
					}
					n=1;
				identifyKey(k);
				__delay_ms(500);	
				
					calculation:
				hit =GetKey();
				k=ident(hit);
				switch(k)
					{ case('0'):
						if(decimal==0){
						num2=(num2*10)+(0);}
						else if(decimal==1){
						num2=(num2)+(0*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;						
						case('1'):
							if(decimal==0){
						num2=(num2*10)+(1);}
						else if(decimal==1){
						num2=(num2)+(1*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;
						case('2'):
							if(decimal==0){
						num2=(num2*10)+(2);}
						else if(decimal==1){
						num2=(num2)+(2*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;						
						case('3'):
							if(decimal==0){
						num2=(num2*10)+(3);}
						else if(decimal==1){
						num2=(num2)+(3*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;
						case('4'):
							if(decimal==0){
						num2=(num2*10)+(4);}
						else if(decimal==1){
						num2=(num2)+(4*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;						
						case('5'):
							if(decimal==0){
						num2=(num2*10)+(5);}
						else if(decimal==1){
						num2=(num2)+(5*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;
						case('6'):
							if(decimal==0){
						num2=(num2*10)+(6);}
						else if(decimal==1){
						num2=(num2)+(6*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;						
						case('7'):
							if(decimal==0){
						num2=(num2*10)+(7);}
						else if(decimal==1){
						num2=(num2)+(7*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;
					  case('8'):
							if(decimal==0){
						num2=(num2*10)+(8);}
						else if(decimal==1){
						num2=(num2)+(8*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;						
						case('9'):
							if(decimal==0){
						num2=(num2*10)+(9);}
						else if(decimal==1){
						num2=(num2)+(9*(pow(0.1,n)));
							n++;
						}
						identifyKey(k);
						goto calculation;
						case('D'):
							goto calculation;
						case('o'):
							identifyKey(k);
							goto calculation;
					  case('*'):
							identifyKey(k);
						result=calc (num1, num2,func);
						break;
					  case('w'):
							identifyKey(hit);
						goto BEGIN;
						default:
							goto calculation;
					}
					sprintf( ans, "a %f b\n", result );
					
					WriteStringToLCD(ans);
								
				__delay_ms(500);
			}
	}
}


void identifyKey(char volatile key)
	{	if ((key=='0')|(key=='1')|(key=='2')
		|(key=='3')|(key=='4')|(key=='5')
		|(key=='6')|(key=='7')|(key=='8')|(key=='9'))
		{WriteDataToLCD(key);
		 return;
		}
		
		if (key=='D')
		{
			if(shift==0)
				{
					shift=1;
				}
				else if(shift==1)
				{
					shift=0;
				}
				return ;
		}
		
		
		if ((key =='+')|(key=='x')
			|(key=='-')|(key=='/')|(key=='.')|(key=='E'))
		{
			switch (key)
			{case('+'):
					key='+';
				 break;
				
			case('x'):
					key='x';
				 break;
			case('-'): 
					key='-';
				break;
			case('/'):
				key='/';
			 break;
			 case ('.'):
					key='.';
			 if(decimal==0)
			 {
					decimal=1;
				 WriteDataToLCD(key);
				  return ;
			 }
			 else if(decimal==1)
			 {
				 return;
			 }
				break;
			 
			 case('E'):
					key='E';
				break;
			}
		 WriteDataToLCD(key);
		 func=key;
		 return ;
		}
		if (key=='o')
		{
		
					key='o';
			return ;
		}
		 if(key=='w')
		{
			Clear();
			return;
		}	
				
			
		if (key ==('*'))
		{WriteDataToLCD('=');
		 return ;
		}
		
	}
	
double calc (double n1, double n2,char func)
{
	switch(func)
		 { 
			 case('+'):
				 result =(n1+n2);
			 break;
		   case('-'):
				 result =(n1-n2);
			 break;
		   case('x'):
				 result =(n1*n2);
			 break;
		   case('/'):
				 result =(n1/n2);
			 break;
				case('E'):
					result=n1*(pow(10,n2));
			
	  	}
			return result;
}

void Clear(){
	WriteCommandToLCD(1);       // clear display 
		 WriteCommandToLCD(0x80);    // lcd cursor location 
     num1 = 0;       // First number
		 func = 'A';    // Function to be performed among two numbers
		 num2 = 0;       // Second number
     result = 0; 
		 return;
}

char ident(char volatile key)
	{	if ((key=='0')|(key=='1')|(key=='2')
		|(key=='3')|(key=='4')|(key=='5')
		|(key=='6')|(key=='7')|(key=='8')|(key=='9'))
		{
		 return key;
		}
		
		if (key=='D')
		{
				return key;
		}
		
		
		if ((key =='A')|(key=='B')
			|(key=='C')|(key=='*'))
		{
			switch (key)
			{case('A'):
				if(shift==0)
				{
					key='+';
				}
				else if(shift==1)
				{
					key='x';
				}
				 break;
			 case('B'): 
				 if(shift==0)
				{
					key='-';
				}
				else if(shift==1)
				{
					key='/';
				}
			 break;
			 case ('C'):
				 if(shift==0)
				{
					key='.';
				}
				else if(shift==1)
				{
					key='E';
				}
				break;
			
			}
		 return key;
		}
		if (key=='#')
		{
		 if(shift==0)
				{  //back one space
					key='o';
				}
				else if(shift==1)
				{
					key='w';
				}	
				
				return key;
		}
			
		if (key ==('*'))
		{
		 return key;
		}
		
	}
