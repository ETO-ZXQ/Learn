/*
在考核主要任务的基础上实现节点分布：
一个节点读取图像，将图像发布，
另一个节点进行人脸识别处理
*/

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "imagePub");
  ros::NodeHandle nh;

  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("imageData", 1);

  cv::Mat image = cv::imread("origin.jpg");
  sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();

  ros::Rate loop_rate(5);

  while (nh.ok()) {
    pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
}
/*

find_package( catkin REQUIRED COMPONENTS
	roscpp
	std_msgs

)
添加  
cv_bridge
sensor_msgs
image_transport
--------------------------------------导致问题--------------------------------------------------------------------------

cv_bridge 与 opencv 冲突
本质：opencv3与opencv4冲突，cv_bridge 默认调用opencv4
导致:
编译时：
warning: libopencv_imgcodecs.so.3.4, needed by /usr/local/lib/libopencv_highgui.so.3.4.14, may conflict with libopencv_imgcodecs.so.4.2

运行时：
GTK+ 2.x symbols detected. Using GTK+ 2.x and GTK+ 3 in the same process is not supported
追踪与中断点陷阱 (核心已转储)

并其他程序也无法正常运行。
--------------------------------------------------------------------------------------------------------
编译时，编译命令后加-DWITH_GTK_2_X=ON
CMake Warning:
  Manually-specified variables were not used by the project:

    WITH_GTK_2_X

程序无法正常运行。
------------------------------------------------------------------------------------------------------------------

ROS知识(12)----cv_bridge依赖opencv版本的问题
cv_bridge默认依赖的oencv版本是2.4.8，如果安装了新的opencv版本，比如2.4.11，那么在编译cv_bridge时候会提示无法找到opencv 2.4.8.so的库。

为解决这个问题，必须要先把旧版本的cv_bridge卸载掉：

sudo apt-get remove ros-indigo-cv-bridge
然后下载新版本的cv_bridge：

git clone https://github.com/ros-perception/vision_opencv.git
将里面的cv_bridge包拿出来，放到工作空间中，重新编译：

catkin_make --pkg cv_bridge
---------------------------------------------------------
解决：
修改cv::bridge的配置文件
cd /opt/ros/noetic/share/cv_bridge/cmake/
sudo gedit cv_bridgeConfig.cmake

查看opencv安装路径：
sudo find / -iname "*opencv*"

更改：
if(NOT "include;/usr/include/opencv4 " STREQUAL " ")
  set(cv_bridge_INCLUDE_DIRS "")
  set(_include_dirs "include;/usr/include/opencv4")

set(libraries "XXXXXXXXXXX")
*/
