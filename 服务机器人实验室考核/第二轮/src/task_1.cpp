/*
实现摄像头的拍照功能：打开电脑自带的 USB 摄像头，实现每按下一个空格键，
即保存当前的摄像头图像，图像保存的位置自定
*/
# include "ros/ros.h"

# include<iostream>
# include<opencv2/opencv.hpp>
# include <time.h>

using namespace std;
using namespace cv;
int main(int argc, char *argv[])
{
    cout<<"press 'space' to save a photo 'q' to finish"<<endl;
    //初始化ROS节点
    //ros::init(argc,argv,"task_1");
    //创建节点句柄
    //ros::NodeHandle nh;
    
    //打开摄像头视频流    
    VideoCapture cap(0);
    //判断是否打开
	if (!cap.isOpened())
	{
		printf("Can not open a camera\n");
		return -1;
	}
    Mat img;//声明一个保存图像的类
    char key = 'a';
    //显示一张图片作控制台
    Mat control = imread("origin.jpg");
    imshow("control", control);
    //时间
    time_t t; 
    char tmp[32]={};
    string name = "";
    

    while(true)
    {   
        //判断按键
        while(true)
        {
            
            key = waitKey(0);
            if(key == ' ') break;
            if(key == 'q') return 0;
        }

        cap.read(img);
        //用时间组成照片名
        t = time(0);
        strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&t));
        name = name.append(tmp);
        name = name.append(".jpg");
        //写入保存
        imwrite(name, img);
        cout<<"capture "<<name<<endl;
        name = "";
    }
    //关闭摄像头
    cap.release();
    //关闭图像窗口
    destroyAllWindows();
    return 0;
}