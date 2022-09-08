#include "../include/initDataList.h"

namespace Graph
{

        InitDataList::InitDataList(const std::vector<std::vector<int>> &data, int scale_ = 1) : data_list{data}, scale{scale_}
        {
            processed_data.resize(data.capacity());
        }
        void InitDataList::avg()
        {
            int count{0};
            for (auto i : data_list)
            {
                processed_data[count] = std::accumulate(i.begin(), i.end(), 0.0);
                count++;
            }
        }

        std::vector<int>& InitDataList::getData(){
            return processed_data;
        }
        int& InitDataList::getScale(){
            return scale;
        }

        void InitDataList::print()
        {
            for (float i : processed_data)
            {
                std::cout << i << " - ";
            }
        }
        InitDataList::~InitDataList() = default;

} // namespace graph