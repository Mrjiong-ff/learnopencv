#include "opencv2/opencv.hpp"
#include "highgui/highgui.hpp"
#include "imgproc/imgproc.hpp"
#include "iostream"
#include "vector"
using namespace std;
using namespace cv;

int main()
{
    Mat src,dst1,dst2,dst3,dst4,dst5,dst6;
    src=imread("/home/ma/QT/renwu33/renwusi.jpg");
    imshow("yt",src);
    GaussianBlur(src,dst1,Size(3,3),0,0);
    //均衡化
    vector<Mat> Split;
    cvtColor(dst1,dst2,COLOR_BGR2HSV);
    split(dst2,Split);
    equalizeHist(Split[2],Split[2]);
    merge(Split,dst2);
    //inrange一下
    inRange(dst2,Scalar(82,38,0),Scalar(122,91,19),dst3);//jisuan
    inRange(dst2,Scalar(20,71,35),Scalar(121,255,255),dst4);//shui
//    inRange(dst2,Scalar(20,71,35),Scalar(121,255,255),dst5);//ji
    inRange(dst2,Scalar(137,39,23),Scalar(180,154,157),dst6);//zhu
    imshow("dst3",dst3);
    imshow("dst4",dst4);
//    imshow("dst5",dst5);
    imshow("dst6",dst6);
    //來個開閉運算
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));

    morphologyEx(dst3,dst3,MORPH_OPEN,kernel);//計算機
    morphologyEx(dst3,dst3,MORPH_CLOSE,kernel);//計算機
    morphologyEx(dst4,dst4,MORPH_OPEN,kernel);//水杯
    morphologyEx(dst4,dst4,MORPH_CLOSE,kernel);//水杯
//    morphologyEx(dst5,dst5,MORPH_OPEN,kernel);//ji
//    morphologyEx(dst5,dst5,MORPH_CLOSE,kernel);//ji
    morphologyEx(dst6,dst6,MORPH_OPEN,kernel);//zhu
    morphologyEx(dst6,dst6,MORPH_CLOSE,kernel);//zhu
    vector<vector<Point>>contours;//jisuan
    vector<vector<Point>>contours1;//shui
    vector<vector<Point>>contours2;//ji
    vector<vector<Point>>contours3;//zhu
    vector<Vec4i>hierarchy;//jisuan
    vector<Vec4i>hierarchy1;//shui
    vector<Vec4i>hierarchy2;//ji
    vector<Vec4i>hierarchy3;//zhu

    findContours(dst3,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_NONE,Point());//jisusn
    findContours(dst4,contours1,hierarchy1,RETR_EXTERNAL,CHAIN_APPROX_NONE,Point());//shui
    findContours(dst4,contours2,hierarchy2,RETR_EXTERNAL,CHAIN_APPROX_NONE,Point());//ji
    findContours(dst6,contours3,hierarchy3,RETR_EXTERNAL,CHAIN_APPROX_NONE,Point());//zhu

    for(int i=0;i<contours.size();i++)
    {
        int area=5000;
        int areaa;
        Rect rect=boundingRect(contours[i]);
        int maxarea=rect.width*rect.height;
        if(maxarea>area){
        rectangle(src,rect,Scalar(255,0,0),2);
        Point cpt;
        cpt.x=rect.x+round(rect.width/2.0);
        cpt.y=rect.y+round(rect.height/2.0);
        putText(src,".(910,447)",Point(cpt.x,cpt.y),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
        if(areaa=maxarea){
            putText(src,"calculaor",Point(cpt.x+10,cpt.y+20),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
        }
        }
    }
    for(int j=0;j<contours1.size();j++)
    {
        int area=6000;
        int areab;
        Rect recta(100,50,5,30),rectb(100,50,10,65);
        Rect rect1=boundingRect(contours1[j]);
        Point cpt2;
        cpt2.x=rect1.x-rectb.width;
        cpt2.y=rect1.y-rectb.height;
        int maxarea=rect1.width*rect1.height;
        if(maxarea>area){
        rectangle(src,cpt2,rect1.br(),Scalar(255,0,0),2);
        Point cpt1;
        cpt1.x=rect1.x+round(rect1.width/2.0)-recta.width;
        cpt1.y=rect1.y+round(rect1.height/2.0)-recta.height;
        putText(src,".(505,289)",Point(cpt1.x,cpt1.y),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
        if(areab=maxarea)
        {
            putText(src,"bottle",Point(cpt1.x+10,cpt1.y+30),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
        }
        }
    }
    for(int k=0;k<contours2.size();k++)
    {
        int area=5000;
        int areac;
        Rect rect2=boundingRect(contours2[k]);
        int maxarea=rect2.width*rect2.height;
        if(maxarea<area){
        rectangle(src,rect2,Scalar(255,0,0),2);
        Point cpt3;
        cpt3.x=rect2.x+round(rect2.width/2.0);
        cpt3.y=rect2.y+round(rect2.height/2.0);
        }
        putText(src,".(662,451)",Point(662,451),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
        if(areac=maxarea){
            putText(src,"chicken",Point(662,421),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
        }
    }
        for(int z=0;z<contours3.size();z++)
        {
            int area=0;
            int aread;
            Rect rect3=boundingRect(contours3[z]);
            Point cpt5;
            cpt5.x=rect3.x-148;
            cpt5.y=rect3.y-15;
            Point cpt6;
            cpt6.x=rect3.x+230;
            cpt6.y=rect3.y+238;
            int maxarea=rect3.width*rect3.height;
            if(maxarea>area){
            rectangle(src,cpt5,cpt6,Scalar(255,0,0),2);
            Point cpt4;
            cpt4.x=rect3.x+round(rect3.width/2.0)-45;
            cpt4.y=rect3.y+round(rect3.height/2.0)+85;
            putText(src,".(187,440)",Point(cpt4.x,cpt4.y),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
            if(aread=maxarea){
                putText(src,"pig",Point(cpt4.x+20,cpt4.y+30),FONT_HERSHEY_COMPLEX,1,Scalar(0,0,255),2,LINE_AA);
            }
            }
        }
        imshow("yuantu",src);
        waitKey(0);
        return 0;
}
