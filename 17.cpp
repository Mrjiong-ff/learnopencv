#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,mid,dst;
int main(){
    src=imread("/home/ma/下载/test2.jpg");
    cvtColor(src,mid,COLOR_BGR2GRAY);
    GaussianBlur(mid,mid,Size(9,9),2,2);
    vector<Vec3f>circles;
    HoughCircles(mid,circles,HOUGH_GRADIENT,1.5,10,200,100,0,0);
    for(size_t i=0;i<circles.size();i++){
        Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(src,center,3,Scalar(0,255,0),-1,8,0);
        circle(src,center,radius,Scalar(155,50,255),3,8,0);
    }
    imshow("src",src);
    waitKey(0);
    return 0;
}