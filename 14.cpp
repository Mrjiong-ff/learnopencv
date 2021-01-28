Scharr算子
#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,src_gray,dst,abs_dst;
int main(){
    src=imread("/home/ma/下载/test1.jpg");
    GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
    cvtColor(src,src_gray,COLOR_BGR2GRAY);
    Laplacian(src_gray,dst,CV_16S,3,1,0,BORDER_DEFAULT);
    imshow("dst",dst);
    convertScaleAbs(dst,abs_dst);
    waitKey(0);
    return 0;
}