#include<iostream>
#include<opencv2/photo/photo.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
Mat srcImage1,inpaintMask;
#define WINDOWNAME1 Src
#define WINDOWNAME2 Dst
Point previousPoint(-1,-1);
static void On_Mouse(int event,int x,int y,int flags,void*){
    if(event==EVENT_LBUTTONUP ||!(flags & EVENT_FLAG_LBUTTON)){
        previousPoint = Point(-1,-1);
    }else if(event == EVENT_LBUTTONDOWN){
        previousPoint =Point(x,y);
    }else if(event==EVENT_MOUSEMOVE&&(flags & EVENT_FLAG_LBUTTON)){
        Point pt(x,y);
        if(previousPoint.x<0){
            previousPoint = pt;
            line(inpaintMask,previousPoint,pt,Scalar::all(255),5,8,0);
            line(srcImage1,previousPoint,pt,Scalar::all(255),5,8,0);
        }
    }
}
int main(){
    Mat srcImage;
    srcImage = imread("/home/ma/下载/test1.jpg");
    srcImage1 = srcImage.clone();
    inpaintMask = Mat::zeros(srcImage1.size(),CV_8U);
    imshow("Src",srcImage1);
    setMouseCallback("Src",On_Mouse,0);
    while(1){
        char c = (char)waitKey();
        if(c==27){
            inpaintMask = Scalar::all(0);
            srcImage.copyTo(srcImage1);
            imshow("Src",srcImage1);
        }
        if(c =='1'||c==' '){
            Mat inpaintedImage;
            inpaint(srcImage1,inpaintMask,inpaintedImage,3,INPAINT_TELEA);
            imshow("Dst",inpaintedImage);
        }
    }
    return 0;
}