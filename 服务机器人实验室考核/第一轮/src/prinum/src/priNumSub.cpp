# include "ros/ros.h"
# include "prinum/NM.h"
# include "iostream"

/*
    订阅方实现：
        1.包含头文件；
        2.初始化 ROS 节点；
        3.创建节点句柄；
        4.创建订阅者对象；
        5.编写订阅逻辑并处理数据
        6.spin()函数
*/
void doPri(const prinum::NM::ConstPtr &nm){
    int n = nm->N;
    int m = nm->M;
    int i,j;
    int pri = 5,count = 2,minMAX = 2,limit = 2;
    bool flag = true;
    //求素数
    std::cout<<2<<" "<<3<<" ";//2,3必有
    if(m>3) minMAX = 3;
    
    for(pri;pri<=n;pri++){
        limit = pri/2;
        for(i=2;i<=limit;i++){
            if(pri%i==0){
                flag = false;
                break;
            }
        }
        if(flag){
            //是素数 输出
            count++;
            std::cout<<pri<<" ";
            if(count%5==0) std::cout<<'\n';  //换行
            if(pri<m) minMAX = pri;

        }
        flag = true;
    }

    if(count%5!=0) std::cout<<'\n';
    std::cout<<minMAX<<'\n';

}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");//解决乱码
    ROS_INFO("订阅方start");

    //初始化ROS节点

    ros::init(argc,argv,"priNumSub");

    
    //创建节点句柄
    ros::NodeHandle nh;

    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe("PriNum", 10, doPri);

    //回调函数处理数据


    //spin()函数
    ros::spin();

    return 0;
}