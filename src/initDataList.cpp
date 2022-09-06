//#include "../include/initDataList.h"

// 1 average +
// 2 peak
// 3 lowest
// 4 merge

/*
namespace Graph
{

    template <class T, class U>
    InitDataList<T, U>::InitDataList(const std::vector<T> &data, double scale_) : data_list{data}, scale{scale_}
    {
        calc.resize(data_list.capacity());
    }
    template <class T, class U>
    void InitDataList<T, U>::averageee()
    {
        int count{0};
        for (auto i : data_list)
        {
            calc[count] = std::accumulate(i.begin(), i.end(), 0.0);

            count++;
        }
    }

    template <class T, class U>
    void InitDataList<T,U>::printtt()
    {
        for (float i : calc)
        {
            std::cout << i;
        }
    }
} // namespace graph
*/


#include <vector>
#include <iostream>
#include <numeric>

namespace Graph
{

    template <class T, class U>
    class InitDataList
    {
    private:
        const std::vector<T> data_list{};
        double scale{};
        std::vector<U> calc{};

    public:
        InitDataList(const std::vector<T> &data, double scale_) : data_list{data}, scale{scale_}
    {
        calc.resize(data_list.capacity());
    }
        void averageee()
    {
        int count{0};
        for (auto i : data_list)
        {
            calc[count] = std::accumulate(i.begin(), i.end(), 0.0);

            count++;
        }
    }

        void printtt()
    {
        for (float i : calc)
        {
            std::cout << i;
        }
    }
        virtual ~InitDataList() = default;
    };

} // namespace graph


void test()
{
/*
    Graph::BarChart bc{"window", 3840, 2160, "Children", "Color"};
    Graph::BarChart bc2{"window2", 2560, 1440, "Stacked Bar Chart", "Group Series(x)"};
    Graph::BarChart bc3{"window3", 1920, 1080, "Data From ISTAT", "YearS"};
    Graph::BarChart bc4{"window4", 1280, 720, "New Revenue", "City"};
    Graph::BarChart bc5{"window5", 854, 480, "Records", "Age Group xXx"};
    bc.imshow();
    bc2.imshow();
    bc3.imshow();
    bc4.imshow();
    bc5.imshow();
    cv::waitKey();*/

    std::vector<int> vec1{1, 2, 3};
    std::vector<int> vec2{4, 5, 6};
    std::vector<int> vec3{7, 8, 9};
    std::vector<std::vector<int>> vec4{vec1, vec2, vec3};
    Graph::InitDataList<std::vector<int>, int> db{vec4, 3};
    db.averageee();
    db.printtt();
}

int main()
{
    test();
}