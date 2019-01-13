#include <iostream>
#include <wiringPi.h>

#define BTN1 7
#define BTN2 0
#define BTN3 21
#define BTN4 22

using namespace std;

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
    // wiringPi setup
    wiringPiSetup () ;

    //init pin
    initPin();

    // loop
    while (true)
    {
        if (digitalRead(BTN1) == LOW)
        {
            cout << "BTN1 press." << endl;
            delay(250);
        }

        if (digitalRead(BTN2) == LOW)
        {
            cout << "BTN2 press." << endl;
            delay(250);
        }

        if (digitalRead(BTN3) == LOW)
        {
            cout << "BTN3 press." << endl;
            delay(250);
        }

        if (digitalRead(BTN4) == LOW)
        {
            cout << "BTN4 press." << endl;
            delay(250);
        }
    }

    return 0;
}
