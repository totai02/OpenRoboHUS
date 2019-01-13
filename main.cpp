#include <iostream>
#include <signal.h>
#include <pigpio.h>
#include <cmath>

#define SERVO1 19

using namespace std;

int run = 1;

void stop(int signum)
{
   run = 0;
   gpioServo(SERVO1, 0);
   gpioTerminate();
}

void setServo(int servo, float angle)
{
    int gpioValue = round(angle / 180 * 2000) + 500;
    gpioServo(servo, gpioValue);
}

int main(int argc, char *argv[])
{
    // PiGpio setup
    if (gpioInitialise() < 0) return -1;

    setServo(SERVO1, 0);

    int servoDir = 1;
    int angle = 0;
    // loop
    while (true)
    {
        if (angle + servoDir > 180 || angle + servoDir < 0)
        {
            servoDir = -servoDir;
        }
        angle = angle + servoDir;
        setServo(SERVO1, angle);
        time_sleep(0.01);
    }

    return 0;
}
