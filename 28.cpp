//#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
//#include<opencv2/highgui/highgui.hpp>
//#include"opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;


    Mat dst1,dst2,dst3;
    //濾波參數值
    int boxFilterValue=3;
    int MeanBlurValue=3;
    int GaussianBlurValue=3;

    //軌跡條回調函數
    void boxFilter(int,void *);
    void on_MeanBlur(int,void *);
    void on_GaussianBlur(int,void *);

int main(){
//    system("color5E");
    Mat src=imread("/home/ma/下载/IMG_20200927_090246.jpg");
    if(src.data){
//        printf("could not load image...");
//        return -1;
//    }
    dst1=src.clone();
    dst2=src.clone();
    dst3=src.clone();

    imshow("intput",src);

    namedWindow("boxFilter",WINDOW_AUTOSIZE);//窗口
    createTrackbar("內核值","boxfilter",&boxFilterValue,30,boxFilter);//滑動條
//    boxFilter(boxFilterValue,0);

//    namedWindow("MeanFilter",WINDOW_AUTOSIZE);//窗口
//    createTrackbar("內核值","MeanBlur",&MeanBlurValue,30,NULL);//滑動條
//    on_MeanBlur(MeanBlurValue,0);

//    namedWindow("GaussianBlur",WINDOW_AUTOSIZE);//窗口
//    createTrackbar("內核值","GaussianBlur",&GaussianBlurValue,30,NULL);//滑動條
//    on_GaussianBlur(GaussianBlurValue,0);


//    boxFilter(src,dst1,-1,Size(boxFilterValue+1,boxFilterValue+1));
//    imshow("boxFilter",dst1);

//    blur(src,dst2,Size(MeanBlurValue+1,MeanBlurValue+1),Point(-1,-1));
//    imshow("MeanBlur",dst2);

//    GaussianBlur(src,dst3,Size(GaussianBlurValue*2+1,GaussianBlurValue*2+1),0,0);
//    imshow("GaussianBlur",dst3);


    waitKey(0);
    return 0;
}
}

