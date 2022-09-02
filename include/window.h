#ifndef WINDOW_H
#define WINDOW_H

#include <string_view>
#include <string>
#include <opencv2/opencv.hpp>


namespace Graph
{
    class Window
    {
    protected:
        std::string window_name{};
        int window_width{};
        int window_height{};

    public:
        Window(std::string_view name, int width, int height );

        virtual ~Window();
    };
}

#endif //WINDOW_H