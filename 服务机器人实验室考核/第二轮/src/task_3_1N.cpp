/*
实现 1 对多的人脸识别，
原图像只有一张人脸，
目的图像有多张人脸（包含原图像的人脸），
在目的图像中准确框出此人脸，
写入图像保存，打印相似度
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

    float similar = 0;//记录每张脸的相似度
	int flag = 0;//记录是否有所需人脸
	int num;//合照中记录人脸张数


    //向数据库注册原图人脸
	int i = register_image(FD, PD, FR, "origin.jpg"); 
    if(i==-1)
    {
        cout<<"人脸注册失败！"<<endl;
        return 0;
    }
    
    //Recognize face and get all faces' similars
    Mat mat = imread("group.jpeg");
    seeta::cv::ImageData image = mat;
    SeetaRect *face = FD.Detect(image, &num);
    if(num>0)
    {
        //对每张人脸分别进行比对
        while (num > 0) 
        {
            SeetaPointF *points = PD.Detect(image, *face);
            FR.Recognize(image, points, &similar);
            //对相似度设阈值
            if (similar > 0.64)
            {
                flag++;

                cout << "匹配成功!" << endl;
                cout << "Similarity: " << similar << endl;  //打印相似度


                //画矩形
                Rect rect = {face->x, face->y, face->width, face->height};
                rectangle(mat, rect, Scalar(0, 0, 255), 4, 1, 0);
            }
            face ++;	
            num --;	  
        }
        if (flag == 0)
        {
            cout << "合照中没有要检测的人脸!" << endl;
            return 0;
        }
        //保存最终图片
        imwrite("group_finish.jpg", mat);
    }
    else
    {
        cout<<"合照中未检测到人脸！"<<endl;
        return 0;
    }

    //展示结果
    imshow("out", mat);  
	waitKey(0);
    
    destroyAllWindows();
    
    //Clear face database
    FR.Clear();

    return 0;
}