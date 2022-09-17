#include "../include/lineChart.h"

namespace Graph
{

    LineChart::LineChart(std::string_view name, int width, int height,
                         std::vector<std::vector<int>> data, int scl,
                         std::string_view x_name, std::string_view y_name)
        : Window{name, width, height}, InitDataList{data, scl}, column_name{x_name}, row_name{y_name} {}

    void LineChart::setBarName(const std::vector<std::string> &) {}
    void LineChart::imshow()
    {
        cv::imshow(getName(), getWindowMat());
    }
}