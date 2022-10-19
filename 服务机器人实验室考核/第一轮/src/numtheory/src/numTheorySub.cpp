# include "ros/ros.h"
# include "numtheory/ShuLie.h"
# include "iostream"
# include <algorithm>

/*
    订阅方实现：
        1.包含头文件；
        2.初始化 ROS 节点；
        3.创建节点句柄；
        4.创建订阅者对象；
        5.编写订阅逻辑并处理数据
        6.spin()函数
*/
//辗转相除法求最大公因数
/*
param a : 大数
param b : 小数
return  : a, b最大公约数 
*/

int gcd(int a, int b)
{
	return ((b==0) ? (a) : (gcd(b, a%b)));
}
/*
param x : 下标 0~x
param a : 待求数组 
return  : a[0]~a[x]的最大公约数 
*/
int gcd_n(int x, int a[])
{
	return ((x==0) ? (a[0]) : (gcd(a[x], gcd_n(x-1, a))));
}
void doS(const numtheory::ShuLie::ConstPtr &s){
    int num[4];
    int delta[3];
    int n=1,i,d;
    num[0]=s->a; num[1]=s->b;num[2]=s->c;num[3]=s->d;

    //排序
    std::sort(num,num+4);//从小到大
    //求公差
    for(i=0; i<3; i++)
        delta[i] = num[i+1] - num[i];
    //求这三个公差的最大公因数
    d = gcd_n(2, delta);        
    if(d==0){
        std::cout<<n<<'\n';
        return;
    }

    //求项数
    n = (num[3]-num[0])/d + 1;

    std::cout<<n<<'\n';


}
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");//解决乱码
    //初始化ROS节点
    ros::init(argc,argv,"numTheorySub");

    //创建节点句柄
    ros::NodeHandle nh;

    //创建订阅者对象
    ros::Subscriber sub = nh.subscribe<numtheory::ShuLie>("numTheory", 10, doS);
    ROS_INFO("订阅方start");
    //回调函数处理数据


    //spin()函数
    ros::spin();

    return 0;
}