/*
实现多对多的人脸识别，原图像有多张人脸，
目的图像是包含原图像所有人脸的合照，
在目的图像中准确框出对应人脸，
并且在框旁边打印出对应名字（名字自定义取，必须原图像对应），
之后写入图像保存
*/

# include "ros/ros.h"

# include <iostream>
# include <opencv2/opencv.hpp>
# include <opencv2/core.hpp>
# include <opencv/highgui.h>

# include <seeta/FaceDetector2.h>
# include <seeta/Struct_cv.h>
# include <seeta/PointDetector2.h>
# include <seeta/FaceRecognizer.h>

using namespace std;
using namespace cv;

//注册人脸使用如下函数。返回值是人脸数据库的索引。如果失败返回-1。
int register_image(seeta::FaceDetector2 &FD, seeta::PointDetector2 &PD, seeta::FaceRecognizer2 &FR, const std::string &filename, std::string name[])
{
    int num;//记录人脸数量
    int index;//记录人脸索引


    cv::Mat mat = cv::imread(filename);
    if (mat.empty()) return -1;
    seeta::cv::ImageData image = mat;
    SeetaRect *face = FD.Detect(image, &num);
    if (!face) return -1;
    //遍历人脸，并输入名字
    for (int i = 0; i < num; i++, face++)
	{
		SeetaPointF *points = PD.Detect(image, *face);
		if (!points)
			return -1;
		else  //注册
			index = FR.Register(image, points); // Reture -1 if failed.
        //显示每一张人脸，并框出，输入名字
		Rect rect = {face->x, face->y, face->width, face->height}; 
		rectangle(mat,rect, Scalar(0,0,255),4,1,0);
		imshow("face", mat);
		moveWindow("face", 0, 0);
		waitKey(1000);
        //输入名字
        cout << "检测到一张人脸，请输入name：" <<endl;
		cin >> name[i];
        cvDestroyWindow("face");
        //写名字
		putText(mat, name[i], Point(face->x, face->y-10), FONT_HERSHEY_SIMPLEX, 0.95, Scalar(0, 255, 0), 2);
	}
    imwrite("NN_origin_finish.jpg", mat);
	return index;
}

int main(int argc, char *argv[])
{  
    //初始化
    seeta::FaceDetector2 FD("/home/eto_zxq/catkin_ws/include/SeetaFaceDetector2.0.ats");
    seeta::PointDetector2 PD("/home/eto_zxq/catkin_ws/include/SeetaPointDetector2.0.pts5.ats");
    seeta::FaceRecognizer2 FR("/home/eto_zxq/catkin_ws/include/SeetaFaceRecognizer2.0.ats");//对比用的

    float similar = 0;//记录比对的相似度
    int who = -1;//记录返回最像人脸索引
    string name[20];//记录原图像人脸姓名
    string text;//每个人名
    

    //------------------人脸注册---------------------
    
    int index = register_image(FD, PD, FR, "NN_origin.jpg", name);//索引从0开始
    if(index==-1)
    {
        cout<<"人脸注册失败！"<<endl;
        return 0;
    }
 

    //-------------------人脸检测-----------------------------------------
    //加载目标图像
    int num;//目标图像中记录人脸张数
    Mat mat = imread("NN_target.jpg");
	seeta::cv::ImageData image = mat;
	SeetaRect *face = FD.Detect(image, &num);
    //依次遍历 目标图像每张脸 与 注册人脸比对
	for (int i = 0; i < num; i++, face++)
	{
        //生成每张脸的特征
		SeetaPointF *points = PD.Detect(image, *face);
 
        //Recognize face and get the most similar face index
        who = FR.Recognize(image, points, &similar);
        if (similar >= 0.5)
        {
            Rect rect = {face->x, face->y, face->width, face->height};  //画矩形
            rectangle(mat, rect, Scalar(0, 0, 255), 4, 1, 0);
            text = name[who];   //打印名字
            putText(mat, text, Point(face->x, face->y-10), FONT_HERSHEY_SIMPLEX, 0.95, Scalar(0, 255, 0), 2);
        }		
    }
    //保存绘制完成的目标图像
    imwrite("NN_target_finish.jpg", mat);
    //展示结果
    imshow("out", mat);  
	waitKey(0);
    
    destroyAllWindows();
    
    //Clear face database
    FR.Clear();

    return 0;
}