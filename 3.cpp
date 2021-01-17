#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace cv;

bool LinearBlending()
{
    double alphaValue = 0.5;
    double betaValue;
    Mat srcImage2,srcImage3,dstImage;
    srcImage2 = imread("/home/ma/下载/test1.jpg");
    srcImage3 = imread("/home/ma/下载/test2.jpg");
    betaValue=(1.0 - alphaValue);
    addWeighted(srcImage2,alphaValue,srcImage3,betaValue,0.0,dstImage);
    imshow("src2",srcImage2);
    imshow("dst",dstImage);
    waitKey(0);
    return true;
}
int main(){
    LinearBlending();
    return 0;
}