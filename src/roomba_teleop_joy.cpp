#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

class Teleop_roomba
{
public:
	Teleop_roomba();

private:
	void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

	ros::NodeHandle nh_;

	int linear_, angular_;
	double l_scale_, a_scale_;
	ros::Publisher twist_pub_;
	ros::Subscriber joy_sub_;

};

Teleop_roomba::Teleop_roomba():
	linear_(1),
	angular_(3)
{
	nh_.param("axis_linear", linear_, linear_);
	nh_.param("axis_angular", angular_, angular_);
	nh_.param("scale_angular", a_scale_, a_scale_);
	nh_.param("scale_linear", l_scale_, l_scale_);


	twist_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel",1);

	joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &Teleop_roomba::joyCallback, this);

}

void Teleop_roomba::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	geometry_msgs::Twist twist;
	twist.angular.z = /*a_scale_ */ joy->axes[angular_];
	twist.linear.x = /*l_scale_ */ joy->axes[linear_];
	twist_pub_.publish(twist);
}

int main(int argc, char** argv)
{
	ros::init(argc,argv, "teleop_roomba");
	Teleop_roomba teleop_roomba;
	
	ros::spin();
}
