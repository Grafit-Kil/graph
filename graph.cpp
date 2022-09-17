// example BarChart

#include "include/barChart.h"

int main()
{
    
    cv::Mat img;
    img = cv::imread("img/rgb.png");

    std::vector<std::vector<int>> colors{};
    colors.resize(6);

    //pixel BGR values
    for (int i{0}; i < img.rows; i++)
    {

        for (int j{0}; j < img.cols; j++)
        {
            if (0 == img.at<cv::Vec3b>(i, j)[0] && 0 == img.at<cv::Vec3b>(i, j)[1] && 0 == img.at<cv::Vec3b>(i, j)[2])
            {
                colors[0].push_back(1);
            }
            else if (255 == img.at<cv::Vec3b>(i, j)[0] && 255 == img.at<cv::Vec3b>(i, j)[1] && 255 == img.at<cv::Vec3b>(i, j)[2])
            {
                colors[1].push_back(1);
            }
            else if (255 == img.at<cv::Vec3b>(i, j)[0] && 0 == img.at<cv::Vec3b>(i, j)[1] && 0 == img.at<cv::Vec3b>(i, j)[2])
            {
                colors[2].push_back(1);
            }
            else if (0 == img.at<cv::Vec3b>(i, j)[0] && 255 == img.at<cv::Vec3b>(i, j)[1] && 0 == img.at<cv::Vec3b>(i, j)[2])
            {
                colors[3].push_back(1);
            }
            else if (0 == img.at<cv::Vec3b>(i, j)[0] && 0 == img.at<cv::Vec3b>(i, j)[1] && 255 == img.at<cv::Vec3b>(i, j)[2])
            {
                colors[4].push_back(1);
            }
            else
            {
                colors[5].push_back(1);
            }
        }
    }

    // bar chart creation
    Graph::BarChart bc{"Colors", 1100, 850, colors, 40, "COLORS", "SCORE"};

    // Bar names
    std::vector<std::string> bar_name{"Black", "White", "Blue", "Green", "Red", "Others"};

    //Calculation for dataset
    bc.size();
    
    //Setup bar name
    bc.setBarName(bar_name);

    //Window desing and show
    bc.imshow();

    cv::waitKey(0);
}
