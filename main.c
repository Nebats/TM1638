#include <avr/io.h>
#include "tm1638.h" // including the h library
#include <util/delay.h>
int main()
{
	TM1638 display;  // declaring the object for the class TM1638

	

	display.setChars("TM1638");       //setting display characters
	display.setLEDs(0xAA, 0x55);

	_delay_ms(3000);    //putting a delay of 3 milli seconds

	display.clear();  // clearing the display
	display.clearLEDs();   // clearing all LED lights


	// Count up and handle buttons as well...

	uint32_t i = 0;
	while (1)    // starting an infinite loop
	{
		if (i == 0)
		display.clear();

		display.setNumber(i++);
		display.setLEDs(i >> 8, display.getButtons());  
	}
}
