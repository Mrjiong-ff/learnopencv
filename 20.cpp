#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,dst;
int main(){
    src=imread("/home/ma/下载/test2.jpg");
    cvtColor(src,src,COLOR_BGR2GRAY);
    equalizeHist(src,dst);
    imshow("dst",dst);
    waitKey(0);
    return 0;
}