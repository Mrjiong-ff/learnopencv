#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,dst;
Mat dst_wrap,dst_warpRotateScale,dst_wrapTransform;
int main(){
    src=imread("/home/ma/下载/test2.jpg");
    Point2f srcPoints[3];
    Point2f dstPoints[3];
    srcPoints[0]=Point2f(0,0);
    srcPoints[1]=Point2f(0,src.rows);
    srcPoints[2]=Point2f(src.cols,0);

    dstPoints[0]=Point2f(0,src.rows*0.3);
    dstPoints[1]=Point2f(src.cols*0.25,src.rows*0.75);
    dstPoints[2]=Point2f(src.cols*0.75,src.rows*0.25);

    Mat M1=getAffineTransform(srcPoints,dstPoints);
    warpAffine(src,dst_wrap,M1,src.size());
    imshow("dst",dst_wrap);
    waitKey(0);
    return 0;
}