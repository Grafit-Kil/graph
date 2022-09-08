#include "../include/window.h"

namespace Graph
{

    Window::Window(std::string_view name = "Window", int width = 800, int height = 600)
        : window_name{name}, window_width{width}, window_height{height}
    {
        window = cv::Mat(window_height, window_width, CV_8UC3, cv::Scalar(0, 0, 0));
    }
    cv::Mat &Window::getWindowMat() { return window; }
    std::string &Window::getName() { return window_name; }
    int &Window::getWidth() { return window_width; }
    int &Window::getHeight() { return window_height; }
    Window::~Window() = default;

}