#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;
Mat src,dst1,dst2,dst3;
int main(){
    src=imread("/home/ma/下载/test1.jpg");
//    Mat kernal=getStructuringElement(MORPH_RECT,Size(9,9));
//    morphologyEx(src,dst1,MORPH_BLACKHAT,kernal);
    Rect ccomp;
    floodFill(src,Point(50,300),Scalar(155,255,55),&ccomp,Scalar(20,20,20),Scalar(20,20,20));
    imshow("dst1",src);
    waitKey(0);
    return 0;
}