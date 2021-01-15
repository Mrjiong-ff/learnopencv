#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
#define window "混合";
const int Maxvalue =100;
int Avalue;
double dAvalue;
double dBetavalue;
Mat src1,src2,dst;
void oTrackbar(int,void*){
    dAvalue=(double)Avalue/Maxvalue;
    dBetavalue=(1.0-dAvalue);
    addWeighted(src1,dAvalue,src2,dBetavalue,0.0,dst);
    imshow("window",dst);
}
int main(){
    src1=imread("/home/ma/下载/test1.jpg",1);
    src2=imread("/home/ma/下载/test1.jpg");
    Avalue=70;
    char trackbarname[50];
    sprintf(trackbarname,"混合度：%d",Avalue);
    namedWindow("window",1);
    createTrackbar(trackbarname,"window",&Avalue,Maxvalue,oTrackbar);
    oTrackbar(Avalue,0);
    waitKey(0);
    return 0;
}