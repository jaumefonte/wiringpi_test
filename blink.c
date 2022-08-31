#include <wiringPi.h>
#include <stdio.h>

#define ledPin 0
void main(void)
{
    printf("Program is starting ... \n");
    wirinPiSetup();

    pinMode(ledPin, OUTPUT);
    printf("Using pin "+ledPin+"\n");
    while(1)
    {
        digitalWrite(ledPin, HIGH);
        printf("led turned on  >>>>\n");
        delay(1000);
        digitalWrite(ledPin, LOW);
        printf("led turned off <<<<\n");
        delay(1000);
    }
}