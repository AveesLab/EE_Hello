#include "ee.h"
#include "Arduino.h"
#include "serial.h"
#include "Timer1.h"

extern int led;

/* Timer1 ISR2 */
ISR2(timer1_handler)
{
	TickType cycle;
	GetAlarm(counter1, &cycle);
	printInteger(cycle);
	CounterTick(counter1);
}

TASK(TaskL1) {
	printSerial("TaskL1 begins");
	printSerial("TaskL1 finishes");
	TerminateTask();
};
