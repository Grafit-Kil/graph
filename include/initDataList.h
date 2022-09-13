#ifndef INIT_DATA_LIST_H
#define INIT_DATA_LIST_H

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

namespace Graph
{
    enum algorithm
    {
        mean,
        min,
        max,
        range,
        size
    };

    class InitDataList
    {
    private:
        const std::vector<std::vector<int>> data_list{};
        int scale{};
        std::vector<int> processed_data{};

    public:
        InitDataList(const std::vector<std::vector<int>> &data, int scale_);
        void mean();
        void min();
        void max();
        void range();
        void size();

        void select(algorithm sec)
        {
            switch (sec)
            {
            case algorithm::mean:
                mean();
                break;
            case algorithm::min:
                min();
                break;
            case algorithm::max:
                max();
                break;
            case algorithm::range:
                range();
                break;
            case algorithm::size:
                size();
                break;
            default:
                break;
            }
        }

        std::vector<int> &getData();
        int &getScale();

        void print();
        virtual ~InitDataList();
    };

} // namespace graph

#endif // INIT_DATA_LIST_H