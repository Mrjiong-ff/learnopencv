#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,mid,dst;
int main(){
    src=imread("/home/ma/下载/renwu111.jpg");
    Canny(src,mid,50,200,3);
    imshow("canny",mid);
    cvtColor(mid,dst,COLOR_GRAY2BGR);
    vector<Vec4i>lines;
    HoughLinesP(mid,lines,1,CV_PI/180,80,50,10);
    for(size_t i=0;i<lines.size();i++){
        Point pt1,pt2;
        pt1.x=lines[i][1];
        pt1.y=lines[i][2];
        pt2.x=lines[i][3];
        pt2.y=lines[i][4];
        line(dst,pt1,pt2,Scalar(186,88,255),1,LINE_AA);
    }
    imshow("dst",dst);
    waitKey(0);
    return 0;
}