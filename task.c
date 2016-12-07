#include "ee.h"
#include "Arduino.h"
#include "serial.h"
#include "Timer1.h"

/* Timer1 ISR2 */
ISR2(timer1_handler)
{
    static unsigned long c = 0;
    TickType cycle;
    GetAlarm(counter1, &cycle);
    CounterTick(counter1);
    printfSerial("\n%4lu: ", ++c);
}

TASK(TaskL1) {
    printfSerial("TaskL1 begins. ");
    delay(2100);
    printfSerial("TaskL1 finishes. ");
    TerminateTask();
};

TASK(TaskL2) {
    printfSerial("TaskL2 begins. ");
    delay(2100);
    printfSerial("TaskL2 finishes. ");
    TerminateTask();
};
