# include "ros/ros.h"
# include "prinum/NM.h"
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
    ros::init(argc, argv, "priNumPub");
    // 创建节点句柄；
    ros::NodeHandle nh;
    // 创建发布者对象；
    ros::Publisher pub = nh.advertise<prinum::NM>("PriNum", 10);    
    ROS_INFO("发布方start");
    // 编写发布逻辑并发布数据

    int n,m;
    prinum::NM nm;



    while(ros::ok())
    {        
        //输入处理
        printf("请输入 N M\n");
        while(1){
            std::cin>>n>>m;
            if((m>2)&&(n>m)) 
                break;
            else
                printf("error require:3<N,2<M<N  请重新输入！\n");

        }            
        
        nm.N = n;
        nm.M = m;
        //核心：发布数据
        pub.publish(nm);
        ROS_INFO("消息发送成功! n=%d,m=%d ",n,m);

        //建议
        ros::spinOnce;

    }

    return 0;
}