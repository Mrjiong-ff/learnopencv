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
    cvtColor(mid,dst,COLOR_GRAY2BGR);
    vector<Vec2f>lines;
    HoughLines(mid,lines,1,CV_PI/180,150,0,0);
    for(size_t i=0;i<lines.size();i++){
        float rho=lines[i][0],theta=lines[i][1];
        Point pt1,pt2;
        double a=cos(theta),b=sin(theta);
        double x0 = a*rho,y0 = b*rho;
        pt1.x = cvRound(x0+1000*(-b));
        pt1.y = cvRound(y0+1000*(a));
        pt2.x = cvRound(x0-1000*(-b));
        pt2.y = cvRound(y0-1000*(a));
        line(dst,pt1,pt2,Scalar(55,100,195),1,LINE_AA);
    }
    imshow("dst",dst);
    waitKey(0);
    return 0;
}