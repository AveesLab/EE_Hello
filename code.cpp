#include "ee.h"
#include "Arduino.h"
#include "serial.h"
#include "Timer1.h"

#define TIMER1_US	1000000U	/* 1 sec */

void loop(void)
{
	;
}

void setup(void)
{
	Serial.begin(9600);
	startTimer1(TIMER1_US);
}

int main(void)
{
	EE_mcu_init();

	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();

    printfSerial("%4lu: OS Begins...", 0ul);
	StartOS(appmode1);	/* never returns */

	return 0;
}
