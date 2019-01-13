#include <iostream>
#include <pigpio.h>
#include <signal.h>

#define SERVO1 19

using namespace std;

int run = 1;

void stop(int signum)
{
    run = 0;
    gpioServo(SERVO1, 0);
    gpioTerminate();
}

void setServo(int servo, int angle)
{
    int gpioValue = angle * 2000 / 180 + 500;
    gpioServo(servo, gpioValue);
}

int main()
{
    // gpio setup
    if (gpioInitialise() < 0) return 1;
    gpioSetSignalFunc(SIGINT, stop);

    setServo(SERVO1, 0);

    int servoDir = 1;
    int angle = 0;

    while (run)
    {
        if (angle + servoDir > 180 || angle + servoDir < 0)
        {
            servoDir = -servoDir;
        }
        angle = angle + servoDir;
        setServo(SERVO1, angle);
        time_sleep(0.02);
    }

    return 0;
}
