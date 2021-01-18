#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace cv;

bool ROI_AddImage()
{
    Mat srcImage1 = imread("/home/ma/下载/test1.jpg");
    Mat logoImage = imread("/home/ma/下载/u=3504997918,3963210850&fm=26&gp=0.jpg");
    Mat ROIimage = srcImage1(Rect(200,250,logoImage.cols,logoImage.rows));
    Mat mask = imread("/home/ma/下载/u=3504997918,3963210850&fm=26&gp=0.jpg",0);
    logoImage.copyTo(ROIimage,mask);
    imshow("add",srcImage1);
    waitKey(0);
    return true;
}
int main(){
    ROI_AddImage();
    return 0;
}