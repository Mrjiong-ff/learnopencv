#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,dst1;
int s1,s2,x,y,s3,s4;
void on_hui(int, void*){
    cvtColor(src,dst1,COLOR_BGR2GRAY);
    GaussianBlur(dst1,dst1,Size(2*s1+1,2*s2+1),x,y);
    boxFilter(dst1,dst1,src.depth(),Size(30,30),Point(s3,s4));
//    blur(dst1,dst1,Size(2*s3+1,2*s4+1));
    threshold(dst1,dst1,185,255,THRESH_BINARY);
    imshow("dst1",dst1);
    waitKey(0);
}
int main(){
    src=imread("/home/ma/下载/project.jpg");
    s1=0;
    s2=0;
    x=0;
    y=0;
    s3=-1;
    s4=-1;
    namedWindow("dst1",0);
    createTrackbar("s1","dst1",&s1,27,on_hui);
    createTrackbar("s2","dst1",&s2,27,on_hui);
    createTrackbar("x","dst1",&x,50,on_hui);
    createTrackbar("y","dst1",&y,50,on_hui);
    createTrackbar("s3","dst1",&s3,10,on_hui);
    createTrackbar("s","dst1",&s4,10,on_hui);
    on_hui(s1,0);
    on_hui(s2,0);
    on_hui(x,0);
    on_hui(y,0);
    on_hui(s3,0);
    on_hui(s4,0);
    return 0;
}
        }
    }
    imshow("yuanshi",g_srcImage);
    imshow("xiaoguo",g_dstImage);
}