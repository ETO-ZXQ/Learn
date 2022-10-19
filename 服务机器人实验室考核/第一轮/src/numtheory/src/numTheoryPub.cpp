# include "ros/ros.h"
# include "numtheory/ShuLie.h"
# include "iostream"

/*
    发布方实现：
        1.包含头文件；
        2.初始化 ROS 节点；
        3.创建节点句柄；
        4.创建发布者对象；
        5.编写发布逻辑并发布数据
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    // 初始化 ROS 节点；
    ros::init(argc, argv, "numTheoryPub");
    // 创建节点句柄；
    ros::NodeHandle nh;
    // 创建发布者对象；
    ros::Publisher pub = nh.advertise<numtheory::ShuLie>("numTheory", 10);    
    ROS_INFO("发布方start");
    // 编写发布逻辑并发布数据

    int a,b,c,d;
    numtheory::ShuLie s;


    while(ros::ok())
    {        
        //输入
        printf("请输入四个正整数：\n");
        std::cin>>a>>b>>c>>d;
        s.a = a;
        s.b = b;
        s.c = c;
        s.d = d;

        //核心：发布数据
        pub.publish(s);
        ROS_INFO("Successfully send!");

        //建议
        ros::spinOnce;

    }

    return 0;
}