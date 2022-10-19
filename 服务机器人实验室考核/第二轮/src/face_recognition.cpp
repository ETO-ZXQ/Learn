/*实现摄像头下的人脸识别*/
# include "ros/ros.h"

# include <seeta/FaceDetector2.h>
# include <seeta/Struct_cv.h>
# include <seeta/PointDetector2.h>
# include <seeta/FaceRecognizer.h>

# include<iostream>
# include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
//注册人脸使用如下函数。返回值是人脸数据库的索引。如果失败返回-1。
int register_image(seeta::FaceDetector2 &FD, seeta::PointDetector2 &PD, seeta::FaceRecognizer2 &FR, const std::string &filename)
{
    cv::Mat mat = cv::imread(filename);
    if (mat.empty()) return -1;
    seeta::cv::ImageData image = mat;
    SeetaRect *face = FD.Detect(image);
    if (!face) return -1;
    SeetaPointF *points = PD.Detect(image, *face);
    if (!points) return -1;
    return FR.Register(image, points);  // Reture -1 if failed.
}
int main(int argc, char *argv[])
{
    //初始化
    seeta::FaceDetector2 FD("/home/eto_zxq/catkin_ws/include/SeetaFaceDetector2.0.ats");
    seeta::PointDetector2 PD("/home/eto_zxq/catkin_ws/include/SeetaPointDetector2.0.pts5.ats");
    seeta::FaceRecognizer2 FR("/home/eto_zxq/catkin_ws/include/SeetaFaceRecognizer2.0.ats");//对比用的

    //----------------人脸注册-----------------------
    int i = register_image(FD, PD, FR, "myFace.jpg"); 
    if(i==-1)
    {
        cout<<"人脸注册失败！"<<endl;
        return 0;
    }

    //打开摄像头视频流    
    VideoCapture cap(0);
    //判断是否打开
	if (!cap.isOpened())
	{
		printf("Can not open a camera\n");
		return -1;
	}
    
    Mat img;//声明一个保存图像的类
    
    int num = -1;//记录检测到的人脸数
    float similarity = 0;//人脸相似度
    	
    while (true) {
		cap.read(img);
        //人脸识别

        seeta::cv::ImageData image = img;
        SeetaRect *face = FD.Detect(image, &num);
        if(num>0)
        {
            SeetaPointF *points = PD.Detect(image, *face);
            //画矩形
            Rect rect = {face->x, face->y, face->width, face->height};
            rectangle(img, rect, Scalar(0, 0, 255), 4, 1, 0); 
            //打印相似度           
            FR.Recognize(image, points, &similarity);
            cout<<"检测到人脸！"<<endl;
            cout<<"similarity:"<<similarity<<endl;
        }
        //显示
        imshow("camera", img);
        waitKey(1);  
	}


    //关闭摄像头
    cap.release();
    //关闭图像窗口
    destroyAllWindows();

    return 0;
}