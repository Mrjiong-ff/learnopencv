#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,dst,edge,gray;
int main(){
    src=imread("/home/ma/下载/test1.jpg");
//    dst.create(src.size(),src.type());
    cvtColor(src,gray,COLOR_BGR2GRAY);
    blur(gray,edge,Size(3,3));
    imshow("gray",gray);
    Canny(edge,edge,3,9,3);
    imshow("edge",edge);
//    dst=Scalar::all(0);
    src.copyTo(dst,edge);
    imshow("canny",dst);
    waitKey(0);
    return 0;
}