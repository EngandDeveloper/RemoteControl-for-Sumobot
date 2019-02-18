/*==============================================================================
	Project: Activity1-Input
	Version: 1.0 				
	Target: UBMP1.0				Processor: PIC16F1459

	A simple input program to test the buttons and LEDs.
==============================================================================*/

#include	"xc.h"				// XC general include file

#include	"stdint.h"			// Include integer definitions
#include	"stdbool.h"			// Include Boolean (true/false) definitions

#include	"UBMP.h"			// Include UBMP constant symbols and functions

// TODO Set linker ROM ranges to 'default,-0-B03' under "Memory model" pull-down.
// TODO Set linker Code offset to '0xB04' under "Additional options" pull-down.
unsigned char LEDlevel; // LEDlevel variable control LED3
unsigned char LEDlevel2; // LEDlevel2 variable is for separate controls of LED3 and LED4.

void buttonCheck(void){
    
    if(S2 == 0)
       {
            if(LEDlevel < 255)
            {
                LEDlevel++;
            }
            else  // to add voice to warn user
            {
                if(LEDlevel = 255)
                {
                    LED3 = 1;
                    P1 = 1;             // to warn user this is the maximum level
                __delay_us(866);
                P1 = 0;
                __delay_us(173);
                }
            }
        }
                     
    if(S5 == 0)
       {
            if(LEDlevel != 0)
            {
               LEDlevel--;
            }
            else
            {
                if(LEDlevel = 0)
                {
                    LED3 = 0;
                }
            }
       }
       
    if(S3 == 0) 
       {
        if(LEDlevel2 < 255)
            {
               LEDlevel2++;        
            }
            else
            {
                if(LEDlevel2 = 255)
                    LED4 = 1;       // to warn user this is the max level
                P1 = 1;
                __delay_us(866);
                P1 = 0;
                __delay_us(173);
            }
        }
       
    if(S4 == 0)
       {
        if(LEDlevel2 != 0)
            {
               LEDlevel2--;
            }
            else
            {
                if(LEDlevel2 = 0)
                {
                    LED4 = 0;
                }
            }
        }    
}


void pwm(void)
{
  
    for(unsigned char i=255; i != 0; i--)
    {
        if(i == LEDlevel)
        {
            LED3 = 1;
        }
        
        if(i == LEDlevel2)
        {
            LED4 = 1;
        }
        
        __delay_us(40);    // optional delay to prevent blinking in LEDs
    }
        LED3 = 0;
        LED4 = 0;
}


/*==============================================================================
	Main program loop. The main() function is called first by the compiler.
==============================================================================*/

int main(void)
{
	initOsc();					// Initialize oscillator
	initPorts();				// Initialize I/O pins and peripherals
//	initANB();					// Optional - Initialize PORTB analogue inputs
        
   LEDlevel == 0;
   LEDlevel2 == 0;
   
   while(1)					// Repeat the main loop continuously
	{   
       buttonCheck();
       pwm();
       
       /*for(unsigned char a = 1 ; a!=0; a++ )
       {       
            if(a == 1)
            {
                buttonCheck();
                pwm();
            }    
            __delay_us(5);
            
            if(a == 2)
            {
                for(unsigned char x = 0; x < 10; x++){
                  pwm();  
                }
                buttonCheck();
            }
       }*/
       
       
       if (S1 == 0)				// Enter the bootloader if S1 is pressed.
		{
			asm("movlp 0x00");
			asm("goto 0x001C");
		}
	}
}

