#ifndef BARCHART_H
#define BARCHART_H

#include <opencv2/opencv.hpp>
#include "window.h"

namespace Graph
{

    class BarChart : public Window
    {
    private:
        std::string column_name{};
        std::string row_name{};
        cv::Mat barc;

    public:
        BarChart(std::string_view name, int width, int height,
                 std::string_view x_name, std::string_view y_name);


        void imshow();
        
    };
}

#endif // BARCHART_H