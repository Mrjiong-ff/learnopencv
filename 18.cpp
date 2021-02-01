#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

Mat src,dst;
Mat map_x,map_y;
int main(){
    src=imread("/home/ma/下载/test2.jpg");
    dst.create(src.size(),src.type());
    map_x.create(src.size(),CV_32FC1);
    map_y.create(src.size(),CV_32FC1);
    for(int j=0;j<src.rows;j++){
        for(int i=0;i<src.cols;i++){
            map_x.at<float>(j,i) = static_cast<float>(i);
            map_y.at<float>(j,i) = static_cast<float>(src.rows-j);
        }
    }
    remap(src,dst,map_x,map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
    imshow("dst",dst);
    waitKey(0);
    return 0;
}