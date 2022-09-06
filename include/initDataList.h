#ifndef INIT_DATA_LIST_H
#define INIT_DATA_LIST_H

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
        std::vector<U> processed_data{};

    public:
        InitDataList(const std::vector<T> &data, double scale_) : data_list{data}, scale{scale_}
        {
            processed_data.resize(data.capacity());
        }
        void avg()
        {
            int count{0};
            for (auto i : data_list)
            {
                processed_data[count] = std::accumulate(i.begin(), i.end(), 0.0);

                count++;
            }
        }
        void print()
        {
            for (float i : processed_data)
            {
                std::cout << i << " - ";
            }
        }
        virtual ~InitDataList() = default;
    };

} // namespace graph

#endif // INIT_DATA_LIST_H