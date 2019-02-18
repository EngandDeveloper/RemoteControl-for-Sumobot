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

void pulse40k(unsigned char pulses)
{
    for(pulses; pulses != 0 ; pulses--)
    {
        LED2 = !LED2;
        __delay_us(12);
    }
    
    LED2 = 0;
}


void sony(unsigned char command) // Bitcounter to keep track of the signal recieved by remote
{
    pulse40k(192);
    __delay_us(600);
    for(unsigned char bitCounter = 7; bitCounter != 0; bitCounter--)
    {
        if((command & 0b00000001) == 1)
        {
            pulse40k(96);
        }
        else
        {
            pulse40k(48);
        }
        __delay_us(600);
        command = command >> 1;
    }
}

int main(void)
{
	initOsc();					// Initialize oscillator
	initPorts();				// Initialize I/O pins and peripherals

    

    while(1)					// Repeat the main loop continuously
	{   
        

	}
}