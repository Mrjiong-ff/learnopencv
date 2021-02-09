#include<opencv2/opencv.hpp>
#include<iostream>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{

    VideoCapture capture;
    capture.open(2);//开摄像头
    Mat frame, src,dst;
    vector<vector<Point>> contours;
    vector<Vec4i> hireachy;
    Rect rect;
    Point2f center;
    float radius = 200;
    while (capture.read(frame))
    {
        double t=(double)getTickCount();
        cvtColor(frame, src, COLOR_BGR2HSV);
        inRange(src, Scalar(0, 43, 46), Scalar(10, 255, 255), dst);
        findContours(dst, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));//得到最大边界
        if (contours.size() > 0)
        {
            double maxArea = 0;
            for (int i = 0; i < contours.size(); i++)
            {
                double area = contourArea(contours[static_cast<int>(i)]);
                if (area > 0)
                {
//                    maxArea = area;//最大
                    rect = boundingRect(contours[static_cast<int>(i)]);
                    minEnclosingCircle(contours[static_cast<int>(i)], center, radius);
                    circle(frame, Point(center.x, center.y), (int)radius, Scalar(0, 255, 0), 2);//建立一个圆形框
                }
            }
        }
        imshow("input", frame);
        imshow("output", dst);
        t=((double)getTickCount()-t)/getTickFrequency();
        int fps=int(1.0/t);
        cout<<"FPS:"<<fps<<endl;
        waitKey(1);
    }
    capture.release();//关闭摄像头
    return 0;
}
