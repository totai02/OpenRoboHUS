#include <iostream>
#include <signal.h>
#include <pigpio.h>
#include <wiringPi.h>
#include <cmath>

#define SERVO1 19
#define BTN1 7
#define BTN2 0
#define BTN3 21
#define BTN4 22

using namespace std;

void stop(int signum)
{
   gpioServo(SERVO1, 0);
   gpioTerminate();
}

void setServo(int servo, float angle)
{
    int gpioValue = round(angle / 180 * 2000) + 500;
    gpioServo(servo, gpioValue);
}

void initPin()
{
    pinMode(BTN1, INPUT);
    pinMode(BTN2, INPUT);
    pinMode(BTN3, INPUT);
    pinMode(BTN4, INPUT);

    pullUpDnControl(BTN1, PUD_UP);
    pullUpDnControl(BTN2, PUD_UP);
    pullUpDnControl(BTN3, PUD_UP);
    pullUpDnControl(BTN4, PUD_UP);
}

int main(int argc, char *argv[])
{
    // PiGpio setup
    if (gpioInitialise() < 0) return -1;

    // wiringPi setup
    wiringPiSetup () ;

    setServo(SERVO1, 0);

    // loop
    while (true)
    {
        if (digitalRead(BTN1) == LOW)
        {
            setServo(SERVO1, 10);
        }
        if (digitalRead(BTN2) == LOW)
        {
            setServo(SERVO1, 50);
        }
        if (digitalRead(BTN3) == LOW)
        {
            setServo(SERVO1, 120);
        }
    }

    return 0;
}
