#ifndef INIT_DATA_LIST_H
#define INIT_DATA_LIST_H

#include <vector>
#include <iostream>
#include <numeric>

namespace Graph
{


    class InitDataList
    {
    private:
        const std::vector<std::vector<int>> data_list{};
        int scale{};
        std::vector<int> processed_data{};

    public:
        InitDataList(const std::vector<std::vector<int>> &data, int scale_);    
        void avg();

        std::vector<int>& getData();
       int& getScale();

        void print();
        virtual ~InitDataList();
    };

} // namespace graph

#endif // INIT_DATA_LIST_H