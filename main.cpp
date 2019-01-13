#include <iostream>
#include <softPwm.h>
#include <wiringPi.h>

#define BTN1 7
#define BTN2 0

#define PWM1 16
#define PWM2 6

using namespace std;

void initPin()
{
    pinMode(BTN1, INPUT);
    softPwmCreate(PWM1, 0, 255);
    softPwmCreate(PWM2, 0, 255);

    pullUpDnControl(BTN1, PUD_UP);
}

int main(int argc, char *argv[])
{
    // wiringPi setup
    wiringPiSetup () ;

    initPin();

    int speed = 100;

    // loop
    while (true)
    {
        if (digitalRead(BTN1) == LOW)
        {
            softPwmWrite(PWM1, speed);
            softPwmWrite(PWM2, 0);
        }
        else if (digitalRead(BTN2) == LOW)
        {
            softPwmWrite(PWM1, 0);
            softPwmWrite(PWM2, speed);
        }
        else
        {
            softPwmWrite(PWM1, 0);
            softPwmWrite(PWM2, 0);
        }
    }

    return 0;
}
