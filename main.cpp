#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int lowH = 0;
int highH = 255;
int lowS = 0;
int highS = 255;
int lowV = 0;
int highV = 255;

Mat binaryImage(const Mat &src)
{
    Mat imgHSV, binary;
    cvtColor(src, imgHSV, COLOR_BGR2HSV);

    inRange(imgHSV, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), binary);

    return binary;
}

int main(int argc, char *argv[])
{
    namedWindow( "Video", CV_WINDOW_AUTOSIZE );
    namedWindow( "Threshold", CV_WINDOW_AUTOSIZE );

    cvCreateTrackbar("LowH", "Threshold", &lowH, 179);
    cvCreateTrackbar("HighH", "Threshold", &highH, 179);

    cvCreateTrackbar("LowS", "Threshold", &lowS, 255);
    cvCreateTrackbar("HighS", "Threshold", &highS, 255);

    cvCreateTrackbar("LowV", "Threshold", &lowV, 255);
    cvCreateTrackbar("HighV", "Threshold", &highV, 255);

    VideoCapture capture = VideoCapture(0);
    Mat src, binary;

    while (waitKey(1) != 'q')
    {
        capture >> src;
        resize(src, src, src.size() / 3);

        binary = binaryImage(src);

        imshow("Video", src);
        imshow("Threshold", binary);
    }
    return 0;
}
