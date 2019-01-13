#include <iostream>
#include <wiringPi.h>

#define BTN1 7
#define BTN2 0
#define BTN3 21
#define BTN4 22
#define LED 30

using namespace std;

void initPin()
{
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);
    pinMode(BTN3, INPUT);
    pinMode(BTN4, INPUT);
    pinMode(LED, OUTPUT);

    pullUpDnControl(BTN1, PUD_UP);
    pullUpDnControl(BTN2, PUD_UP);
    pullUpDnControl(BTN3, PUD_UP);
    pullUpDnControl(BTN4, PUD_UP);
}

int main(int argc, char *argv[])
{
    // wiringPi setup
    wiringPiSetup () ;

    //init pin
    initPin();

    digitalWrite(LED, LOW);

    // loop
    while (true)
    {
        if (digitalRead(BTN1) == LOW)
        {
            int currentState = digitalRead(LED);
            digitalWrite(LED, !currentState);
            delay(250);
        }
    }

    return 0;
}
