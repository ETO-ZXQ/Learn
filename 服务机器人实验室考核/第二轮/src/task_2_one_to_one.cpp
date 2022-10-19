/*
实现 1 对 1 的人脸识别，
原图像和目的图像都只有一张人脸，
识别后打印出相似度(—个小于1的浮点数），
目的图像用矩形框出人脸（借助 OpenCv) , 
写入图像保存
*/


# include "ros/ros.h"

# include<iostream>
# include<opencv2/opencv.hpp>
# include <opencv2/core.hpp>
# include <opencv/highgui.h>

# include <seeta/FaceDetector2.h>
# include <seeta/Struct_cv.h>
# include <seeta/PointDetector2.h>
# include <seeta/FaceRecognizer.h>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //相似度初始化
    float similar = 0;   

    //-------------人脸检测-------------------------
    //初始化
    seeta::FaceDetector2 FD("/home/eto_zxq/catkin_ws/include/SeetaFaceDetector2.0.ats");
    seeta::PointDetector2 PD("/home/eto_zxq/catkin_ws/include/SeetaPointDetector2.0.pts5.ats");
    seeta::FaceRecognizer2 FR("/home/eto_zxq/catkin_ws/include/SeetaFaceRecognizer2.0.ats");//对比用的
    //加载原图像
    Mat origin = cv::imread("origin.jpg");
    //人脸检测，人脸对齐，人脸特征提取，保存特征
    seeta::cv::ImageData image1 = origin;
    SeetaRect *face1 = FD.Detect(image1);
    SeetaPointF points1[5];
    PD.DetectEx(image1, *face1, points1);

    //对比图一样处理
    Mat target = imread("target.jpg");
    seeta::cv::ImageData image2 = target;
    SeetaRect *face2 = FD.Detect(image2);
    SeetaPointF points2[5];
    PD.DetectEx(image2, *face2, points2);



    //脸部特征对比 相似性
    similar = FR.Compare(image1, points1, image2, points2);
    
    //---------结果输出---------------------------
    
    
	if (similar <= 0.75)
    {
        cout <<"fail!!!" << endl;
        return 0;
    }	
	else
	{
		cout << "Similarity: " << similar << endl;
 
		//画矩形
		Rect rect = {face2->x, face2->y, face2->width, face2->height};
		rectangle(target,rect,Scalar(0,0,255),4,1,0);
		//结果保存
		imwrite("target_finish.jpg", target);
	}
	
    
    
    
    imshow("out", target);  //展示图片
	cv::waitKey(0);
    
    destroyAllWindows();
    return 0;
}