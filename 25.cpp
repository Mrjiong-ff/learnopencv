#include<opencv2/opencv.hpp>
#include<highgui.hpp>



using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture;
	capture.open(0);//开摄像头
	if (!capture.isOpened())//如果开启失败
	{
		printf("can not open video file   \n");
		return -1;
	}
	Mat frame, dst;
	Mat kernel;
	
	kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	namedWindow("input", WINDOW_AUTOSIZE);
	namedWindow("output", WINDOW_AUTOSIZE);

	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hireachy;
	Rect rect;
	Point2f center;
	float radius = 20;

	while (capture.read(frame))
	{
		cvtColor(frame, frame, COLOR_BGR2HSV);
		inRange(frame, Scalar(100, 43, 46), Scalar(124, 255, 255), dst);
		morphologyEx(dst, dst, MORPH_OPEN, kernel);//边界
		findContours(dst, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));//得到最大边界
		if (contours.size() > 0)
		{
			double maxArea = 0;
			for (int i = 0; i < contours.size(); i++)
			{
				double area = contourArea(contours[static_cast<int>(i)]);
				if (area > maxArea)
				{
					maxArea = area;//最大
					rect = boundingRect(contours[static_cast<int>(i)]);
					minEnclosingCircle(contours[static_cast<int>(i)], center, radius);
				}
			}
		}

		circle(frame, Point(center.x, center.y), (int)radius, Scalar(0, 255, 0), 2);//建立一个圆形框

		imshow("input", frame);
		imshow("output", dst);

		waitKey(1);
	}

	capture.release();//关闭摄像头
	return 0;
}