#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

#include <chrono>
#include <functional>
#include <string>
#include <memory>

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
    public:
        MinimalPublisher() : Node("minimal_publisher"), count_(0)
        {
            publisher_ = this->create_publisher<std_msgs::msg::Float32>("number",10);
            timer_ = this->create_wall_timer(500ms,std::bind(&MinimalPublisher::timer_callback, this));
        }

        ~MinimalPublisher()
        {

        }

    private:
        void timer_callback()
        {
            auto msg = std_msgs::msg::Float32();
            msg.data = count_;
            RCLCPP_INFO(this->get_logger(),"Number ===> %f", count_);
            publisher_->publish(msg);
            count_+=0.5;
        }

        rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        float count_;

};

int main(int argc, char * argv[])
{
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();

    return 0;
}