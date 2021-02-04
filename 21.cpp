#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,dst;
int main(){
    src=imread("/home/ma/下载/test1.jpg",0);
    Canny(src,src,3,15,3);
    dst=Mat::zeros(src.rows,src.cols,CV_8UC3);
    vector<vector<Point>>contours;
    vector<Vec4i>hierarchy;
    findContours(src,contours,hierarchy,RETR_CCOMP,CHAIN_APPROX_SIMPLE);
    for(int index=0;index>=0;index=hierarchy[index][0]){
        Scalar color=Scalar(255,255,255);
        drawContours(dst,contours,index,color,FILLED,8,hierarchy);
    }
    imshow("dst",dst);
    waitKey(0);
    return 0;
}