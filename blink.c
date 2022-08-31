#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>

volatile sig_atomic_t stop;
#define ledPin 0
void inthand(int signum)
{
    stop = 1;
}
void cleanPin(int pin)
{
digitalWrite(pin, LOW);
pinMode(pin INPUT);
}
void main(void)
{
    printf("Program is starting ... \n");
    wiringPiSetup();
    signal(SIGINT, inthand);
    pinMode(ledPin, OUTPUT);
    while(!stop)
    {
        digitalWrite(ledPin, HIGH);
        printf("led turned on  >>>>\n");
        delay(1000);
        digitalWrite(ledPin, LOW);
        printf("led turned off <<<<\n");
        delay(1000);
    }
    cleanPin(ledPin);
}