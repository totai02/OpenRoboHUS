#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <wiringPi.h>

#define BTN1 7
#define BTN2 0

using namespace std;
using namespace cv;

void initPin()
{
    pinMode(BTN2, INPUT);

    pullUpDnControl(BTN2, PUD_UP);
}

int main(int argc, char *argv[])
{
    // wiringPi setup
    wiringPiSetup () ;

    initPin();

    namedWindow( "Video", CV_WINDOW_AUTOSIZE );

    VideoCapture capture = VideoCapture(0);
    VideoWriter writer("video.avi",CV_FOURCC('M','J','P','G'), 30, Size(640, 480));
    Mat src, binary;

    while (waitKey(1) != 'q')
    {
        if (digitalRead(BTN2) == LOW)
        {
            capture >> src;
            writer.write(src);
            imshow("Video", src);
        }
    }

    writer.release();
    return 0;
}
