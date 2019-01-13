#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <wiringPi.h>

#define BTN1 7

using namespace std;
using namespace cv;

void initPin()
{
    pinMode(BTN1, INPUT);

    pullUpDnControl(BTN1, PUD_UP);
}

int main(int argc, char *argv[])
{
    // wiringPi setup
    wiringPiSetup () ;

    initPin();

    namedWindow( "Video", CV_WINDOW_AUTOSIZE );

    VideoCapture capture = VideoCapture(0);
    Mat src, binary;

    while (waitKey(1) != 'q')
    {
        if (digitalRead(BTN1) == LOW)
        {
            capture >> src;
            imshow("Video", src);
            delay(250);
        }
    }
    return 0;
}
