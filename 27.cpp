//調參
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;


int main()
{


    Mat imgOriginal;
    Mat imgHSV;
    VideoCapture capture;
    capture.open(2);
    namedWindow("Control",WINDOW_AUTOSIZE);

    int LowH = 0;
    int HighH = 180;

    int LowS = 0;
    int HighS = 255;

    int LowV = 0;
    int HighV = 255;

//    int s1=0;
//    int s2=0;
    createTrackbar("LowH","Control",&LowH,180, NULL);
    createTrackbar("HighH", "Control", &HighH,180,NULL);

    createTrackbar("LowS", "Control", &LowS,255, NULL);
    createTrackbar("Highs", "Control", &HighS,255, NULL);

    createTrackbar("LowV", "Control", &LowV,255, NULL);
    createTrackbar("HighV", "Control", &HighV,255, NULL);
//    createTrackbar("S1","Control",&s1,100,NULL);
//    createTrackbar("s2","Control",&s2,100,NULL);
    while(capture.read(imgOriginal))
    {
//        imgOriginal=imread("/home/ma/下载/teammeach.jpg");
        cvtColor(imgOriginal,imgHSV,COLOR_BGR2HSV);
//        blur(imgHSV,imgHSV,Size(s1,s2));
//        imshow("Imghsv",imgHSV);
        Mat imgThresholded;
        //确定颜色显示的范围
        inRange(imgHSV, Scalar(LowH, LowS, LowV), Scalar(HighH, HighS,HighV),imgThresholded);
        namedWindow("imgThresholded",0);
        imshow("imgThresholded",imgThresholded);
        waitKey(1);
    }
     waitKey(0);
    return 0;
}


