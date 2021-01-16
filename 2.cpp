#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;
void colorReduce(Mat& inputImage,Mat& outputImage,int div);
int main(){
    Mat src,dst;
    src=imread("/home/ma/下载/test1.jpg");
    dst.create(src.rows,src.cols,src.type());
    double time0 = static_cast<double>(getTickCount());
    colorReduce(src,dst,32);
    time0 = ((double)getTickCount()-time0)/getTickFrequency();
    cout<<time0<<"s"<<endl;
    imshow("dst",dst);
    waitKey(0);
    return 0;
}
void colorReduce(Mat &inputImage, Mat &outputImage, int div){
    outputImage = inputImage.clone();
    int rowNumber = outputImage.rows;
    int colNumber = outputImage.cols;
    for(int i=0;i<rowNumber;i++){
        uchar* data = outputImage.ptr<uchar>(i);
        for(int j=0;j<colNumber;j++){
            data[j] = data[j]/div*div + div/2;
        }
    }
}