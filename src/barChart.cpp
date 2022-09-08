#include "../include/barChart.h"

namespace Graph
{

    BarChart::BarChart(std::string_view name, int width, int height,
                       std::vector<std::vector<int>> data, int scl,
                       std::string_view x_name, std::string_view y_name)
        : Window{name, width, height}, InitDataList{data, scl}, column_name{x_name}, row_name{y_name} {}

    void BarChart::imshow()
    {
        // Apsis and Ordinate line
        cv::line(getWindowMat(), cv::Point(100, getHeight() - 100),
                 cv::Point(100, 100), cv::Scalar(255, 255, 111), 3);

        cv::line(getWindowMat(), cv::Point(100, getHeight() - 100),
                 cv::Point(getWidth() - 100, getHeight() - 100), cv::Scalar(50, 50, 255), 3);

        cv::putText(getWindowMat(), row_name, cv::Point(((getWidth() / 2) - 100), (getHeight() - 20)),
                    cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(219, 131, 31), 1, 8, false);

        // rotate apsis text for ordinat text
        cv::Mat rotateText(getWidth(), getWidth(), CV_8UC3, cv::Scalar(0, 0, 0));

        // Column Bars
        int column_begin{150};
        int column_end{210};
        int bar_value_begin{190};
        for (auto i : getData())
        {
            std::string bar_value = std::to_string(i);
            std::cerr << i << " - ";

            cv::rectangle(getWindowMat(), cv::Point(column_begin, (getHeight() - 100) - (i / getScale())),
                          cv::Point(column_end, getHeight() - 100), cv::Scalar(123, 145, 73), -1);

            // Print bar value for rotateText
            cv::putText(rotateText, bar_value, cv::Point(150, column_begin + 60),
                        cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 255, 255), 2, cv::INTER_MAX, false);

            column_begin += 70;
            column_end += 70;
        }

        cv::putText(rotateText, column_name, cv::Point(((getWidth() + 100) / 2) - 100, 100),
                    cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(181, 124, 31), 1, 8, false);

        cv::Mat rot_mat = getRotationMatrix2D(cv::Point(getWidth() / 2, getWidth() / 2), 90.0, 1.0);
        cv::warpAffine(rotateText, rotateText, rot_mat, rotateText.size());

        rotateText(cv::Rect(20, 0, rotateText.cols - 20, rotateText.rows)).copyTo(rotateText(cv::Rect(0, 0, rotateText.cols - 20, rotateText.rows)));
        cv::resize(rotateText, rotateText, cv::Size(getWidth(), getHeight()), cv::INTER_LINEAR);
        getWindowMat() = getWindowMat() + rotateText;

        cv::imshow(getName(), getWindowMat());
    }

}