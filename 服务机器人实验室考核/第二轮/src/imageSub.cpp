#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <cv_bridge/cv_bridge.h>
# include <seeta/FaceDetector2.h>
# include <seeta/Struct_cv.h>
# include <seeta/PointDetector2.h>
# include <seeta/FaceRecognizer.h>

using namespace cv;
using namespace std;

void imageCallback(const sensor_msgs::ImageConstPtr& msg)
{
  int num = -1;

  cv::Mat img = cv_bridge::toCvShare(msg, "bgr8")->image;

  cv::imshow("view", img);
  cv::waitKey(0);
  cv::destroyWindow("view");
  //-----------人脸识别----------------------
  //初始化
  seeta::FaceDetector2 FD("/home/eto_zxq/catkin_ws/include/SeetaFaceDetector2.0.ats");
  seeta::PointDetector2 PD("/home/eto_zxq/catkin_ws/include/SeetaPointDetector2.0.pts5.ats");
  seeta::FaceRecognizer2 FR("/home/eto_zxq/catkin_ws/include/SeetaFaceRecognizer2.0.ats");//对比用的

  seeta::cv::ImageData image = img;


  SeetaRect *face = FD.Detect(image, &num);
  if (!face) return;
  //遍历人脸
  for (int i = 0; i < num; i++, face++)
	{
		SeetaPointF *points = PD.Detect(image, *face);
		if (!points)
			return;
		else{
			Rect rect = {face->x, face->y, face->width, face->height}; 
		  rectangle(img,rect, Scalar(0,0,255),4,1,0);
    }
	}
  cout<<"成功检测到人脸!"<<endl;
	imshow("face", img);
	moveWindow("face", 0, 0);
  waitKey(0);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "imageSub");
  ros::NodeHandle nh;

  cv::namedWindow("view");
  //cv::startWindowThread();
  image_transport::ImageTransport it(nh);
  image_transport::Subscriber sub = it.subscribe("imageData", 1, imageCallback);
  
  
  ros::spin();
}