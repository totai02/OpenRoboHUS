#include <iostream>
#include <softPwm.h>
#include <wiringPi.h>

#define PWM1_1 16
#define PWM1_2 6
#define PWM2_1 31
#define PWM2_2 11


using namespace std;

void initPin()
{
    softPwmCreate(PWM1, 0, 255);
    softPwmCreate(PWM2, 0, 255);
}

void forward()
{
    softPwmWrite(PWM1_1, 150);
    softPwmWrite(PWM1_2, 0);
    softPwmWrite(PWM2_1, 150);
    softPwmWrite(PWM2_2, 0);
    delay(1000);
    stop();
}

void backward()
{
    softPwmWrite(PWM1_1, 0);
    softPwmWrite(PWM1_2, 150);
    softPwmWrite(PWM2_1, 0);
    softPwmWrite(PWM2_2, 150);
    delay(1000);
    stop();
}

void turnLeft()
{
    softPwmWrite(PWM1_1, 150);
    softPwmWrite(PWM1_2, 0);
    softPwmWrite(PWM2_1, 0);
    softPwmWrite(PWM2_2, 150);
    delay(500);
    stop();
}

void turnRight()
{
    softPwmWrite(PWM1_1, 0);
    softPwmWrite(PWM1_2, 150);
    softPwmWrite(PWM2_1, 150);
    softPwmWrite(PWM2_2, 0);
    delay(500);
    stop();
}

void stop()
{
    softPwmWrite(PWM1, 0);
    softPwmWrite(PWM2, 0);
}

int main(int argc, char *argv[])
{
    // wiringPi setup
    wiringPiSetup () ;

    initPin();

    int dir;

    // loop
    while (true)
    {
        cin >> dir;

        if (dir == 1)
        {
            forward();
        }

        if (dir == 2)
        {
            backward();
        }

        if (dir == 3)
        {
            turnLeft();
        }

        if (dir == 4)
        {
            turnRight();
        }

    }

    return 0;
}
