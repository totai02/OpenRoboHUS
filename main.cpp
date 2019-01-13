#include <iostream>
#include <softPwm.h>
#include <wiringPi.h>

#define PWM1 16
#define PWM2 6

using namespace std;

void initPin()
{    softPwmCreate(PWM1, 0, 255);
    softPwmCreate(PWM2, 0, 255);
}

int main(int argc, char *argv[])
{
    // wiringPi setup
    wiringPiSetup () ;

    initPin();

    int speed = 255;

    // loop
    while (true)
    {
        cin >> speed;

        if (speed > 0)
        {
            softPwmWrite(PWM1, speed);
            softPwmWrite(PWM2, 0);
        }
        else
        {
            softPwmWrite(PWM1, 0);
            softPwmWrite(PWM2, -speed);
        }
    }

    return 0;
}
