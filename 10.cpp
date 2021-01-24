#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat grad_x,grad_y;
Mat absgrad_x,absgrad_y,dst;
Mat src;
int main(){
    src=imread("/home/ma/下载/renwu111.jpg");
    Sobel(src,grad_x,CV_16S,1,0,3,1,1,BORDER_DEFAULT);
    convertScaleAbs(grad_x,absgrad_x);
    imshow("x",absgrad_x);
    Sobel(src,grad_y,CV_16S,1,0,3,1,1,BORDER_DEFAULT);
    convertScaleAbs(grad_y,absgrad_y);
    imshow("y",absgrad_y);
    addWeighted(absgrad_x,0.5,absgrad_y,0.5,0,dst);
    imshow("show",dst);
    waitKey(0);
    return 0;
}