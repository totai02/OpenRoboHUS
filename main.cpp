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
    int lanBam = 0;
    while (true)
    {
        if (digitalRead(BTN3) == LOW)
        {
            lanBam++;
            delay(250);
        }

        if (digitalRead(BTN4) == LOW)   // Phải ấn giữ phím, vì đợi hết chu kì đèn nháy, mới đến lệnh này
        {
            lanBam = 0;
            digitalWrite(LED, LOW);
            delay(250);
        }

        if (lanBam == 1)
        {
            digitalWrite(LED, HIGH);
        }

        if (lanBam == 2)
        {
            digitalWrite(LED, !digitalRead(LED));
            delay(1000);
        }
    }

    return 0;
}
