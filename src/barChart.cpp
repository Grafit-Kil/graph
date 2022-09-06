#include "../include/barChart.h"
#include "../include/initDataList.h"

namespace Graph
{

    BarChart::BarChart(std::string_view name, int width, int height,
                       std::string_view x_name, std::string_view y_name)
        : Window{name, width, height}, column_name{x_name}, row_name{y_name}
    {
    }

    void BarChart::imshow()
    {
        // Apsis and Ordinate line
        cv::line(getWindowMat(), cv::Point(100, window_height - 100),
                 cv::Point(100, 100), cv::Scalar(255, 255, 111), 3);

        cv::line(getWindowMat(), cv::Point(100, window_height - 100),
                 cv::Point(window_width - 100, window_height - 100), cv::Scalar(50, 50, 255), 3);

        cv::putText(getWindowMat(), row_name, cv::Point(((window_width / 2) - 100), (window_height - 20)),
                    cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 0), 1, 8, false);

        // rotate apsis text for ordinat text
        cv::Mat rotateText(window_width, window_width, CV_8UC3, cv::Scalar(0, 0, 0));
        cv::putText(rotateText, column_name, cv::Point((window_width / 2) - 100, 100),
                    cv::FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 0), 1, 8, false);

        cv::Mat rot_mat = getRotationMatrix2D(cv::Point(window_width / 2, window_width / 2), 90.0, 1.0);
        cv::warpAffine(rotateText, rotateText, rot_mat, rotateText.size());
        rotateText(cv::Rect(20, 0, rotateText.cols - 20, rotateText.rows)).copyTo(rotateText(cv::Rect(0, 0, rotateText.cols - 20, rotateText.rows)));
        cv::resize(rotateText, rotateText, cv::Size(window_width, window_height), cv::INTER_LINEAR);
        getWindowMat() = getWindowMat() + rotateText;

        cv::rectangle(getWindowMat(),cv::Point(120,120),cv::Point(180,window_height-100),cv::Scalar(0, 255, 0),-1);               
        cv::rectangle(getWindowMat(),cv::Point(220,120),cv::Point(280,window_height-100),cv::Scalar(0, 255, 0),-1);               
        cv::rectangle(getWindowMat(),cv::Point(320,120),cv::Point(380,window_height-100),cv::Scalar(0, 255, 0),-1);               
        cv::rectangle(getWindowMat(),cv::Point(420,120),cv::Point(480,window_height-100),cv::Scalar(0, 255, 0),-1);               
        cv::rectangle(getWindowMat(),cv::Point(520,120),cv::Point(580,window_height-100),cv::Scalar(0, 255, 0),-1);               





        cv::imshow(window_name, getWindowMat());
    }

}