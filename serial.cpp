#include "Arduino.h"
#include "serial.h"

void printSerial(const char *str)
{
	Serial.println(str);
}

void printInteger(int num)
{
	Serial.println(num);
}

void printByte(char re)
{
	Serial.println((byte) re);
}

void printFloat(float f)
{
	Serial.println(f);
}
