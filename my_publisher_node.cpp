#include "ros/ros.h"//#roslibrary
#include "std_msgs/Int8.h"
#include <sstream>//for showing the string


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");//intialize node

  ros::NodeHandle n;//access point to enable the node to talk to the ros system

  
  ros::Publisher Integer_pub;//creating object

   Integer_pub= n.advertise<std_msgs::	Int8>("chatter",50);//advertise=publish data , 50 is the size , string is the type , chatter is the name of the topic

  ros::Rate loop_rate(1);//publish speed rate

  int integer_ass =20;  
  while (ros::ok())//checkes if the ros node still running
  {

  
  ROS_INFO_STREAM("Value of integer_ass = " << integer_ass);//print massege on my terminal




    ros::spinOnce();

    loop_rate.sleep();//1/looprate = application of the loop time
    if(integer_ass==100)
    {
      ros::shutdown();
    }
    ++integer_ass;
  }
    

  return 0;
}