#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

#include <memory>

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
    public:
        MinimalSubscriber() : Node("minimal_subscriber")
        {
            subscriber_ = this->create_subscription<std_msgs::msg::Float32>("number",10,std::bind(&MinimalSubscriber::topic_callback, this, _1));
        }

        ~MinimalSubscriber()
        {

        }

    private:
        void topic_callback(const std_msgs::msg::Float32::SharedPtr msg) const
        {
            RCLCPP_INFO(this->get_logger(),"Sub topic number ::::::> %f",msg->data);
        }

        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscriber_;

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<MinimalSubscriber>());
    rclcpp::shutdown();

    return 0;
}