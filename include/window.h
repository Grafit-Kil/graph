#ifndef WINDOW_H
#define WINDOW_H

#include <string_view>
#include <string>
#include <opencv2/opencv.hpp>

namespace Graph
{
    class Window
    {
    private:
        cv::Mat window;
        std::string window_name{};
        int window_width{};
        int window_height{};

    public:
        Window(std::string_view name, int width, int height);
        cv::Mat &getWindowMat();
        std::string& getName();
        int &getWidth();
        int &getHeight();
        virtual void imshow() = 0;
        virtual ~Window();
    };
}

#endif // WINDOW_H