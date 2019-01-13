#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    namedWindow( "Video", CV_WINDOW_AUTOSIZE );

    VideoCapture capture = VideoCapture(0);
    Mat src;

    while (waitKey(1) != 'q')
    {
        capture >> src;
        imshow("Video", src);
    }
    return 0;
}
