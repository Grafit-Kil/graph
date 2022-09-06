#ifndef BAR_CHART_H
#define BAR_CHART_H

#include <opencv2/opencv.hpp>
#include "window.h"
//#include "initDataList.h"

namespace Graph
{
    class BarChart : public Window
    {
    private:
        std::string column_name{};
        std::string row_name{};

    public:
        BarChart(std::string_view name, int width, int height,
                 std::string_view x_name, std::string_view y_name);

        void imshow();
        
    };
}

#endif // BAR_CHART_H