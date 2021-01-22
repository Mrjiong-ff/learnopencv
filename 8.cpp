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
    dst1=src;
    resize(dst1,dst2,Size(dst1.cols/2,dst1.rows/2),(0,0),(0,0),3);
    resize(dst1,dst3,Size(dst1.cols*1.5,dst1.rows*1.5),(0,0),(0,0),3);
    imshow("dst2",dst2);
    imshow("dst3",dst3);
    waitKey(0);
    return 0;
}