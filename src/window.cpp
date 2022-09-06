#include "../include/window.h"

namespace Graph
{

    Window::Window(std::string_view name = "Window", int width = 800, int height = 600)
        : window_name{name}, window_width{width}, window_height{height}
    {
        window = cv::Mat(window_height, window_width, CV_8UC3, cv::Scalar(0, 0, 0));
    }

    Window::~Window() = default;

}