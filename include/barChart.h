#ifndef BAR_CHART_H
#define BAR_CHART_H

#include <opencv2/opencv.hpp>
#include "window.h"
#include "initDataList.h"

namespace Graph
{

    class BarChart : public Window, public InitDataList
    {
    private:
        std::string column_name{};
        std::string row_name{};
        std::vector<int> columnNumber;

    public:
        BarChart(std::string_view name, int width, int height,
                 std::vector<std::vector<int>> data, int scl,
                 std::string_view x_name = "", std::string_view y_name = "");

        void setBarName(const std::vector<std::string>&) override;
        void imshow() override;
    };
}

#endif // BAR_CHART_H