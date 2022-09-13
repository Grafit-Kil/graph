#include "../include/initDataList.h"

namespace Graph
{

    InitDataList::InitDataList(const std::vector<std::vector<int>> &data, int scale_ = 1) : data_list{data}, scale{scale_}
    {
        processed_data.resize(data.capacity());
    }
    void InitDataList::mean()
    {
        int count{0};
        for (auto i : data_list)
        {
            if (i.size() > 0)

            {
                processed_data[count] = std::accumulate(i.begin(), i.end(), 0.0);
            }
            count++;
        }
    }

    void InitDataList::min()
    {
        int count{0};
        for (auto i : data_list)
        {
            if (i.size() > 0)
            {
                processed_data[count] = *std::min_element(i.begin(), i.end());
            }
            count++;
        }
    }
    void InitDataList::max()
    {
        int count{0};

        for (auto i : data_list)
        {
            if (i.size() > 0)
            {
                processed_data[count] = *std::max_element(i.begin(), i.end());
            }
            count++;
        }
    }

    void InitDataList::range()
    {
        int count{0};
        int max;
        int min;
        for (auto i : data_list)
        {
            if (i.size() > 0)
            {
                min = *std::min_element(i.begin(), i.end());
                max = *std::max_element(i.begin(), i.end());
                processed_data[count] = (max - min);
            }
            count++;
        }
    }

    void InitDataList::size()
    {
        int count{0};
        for (auto i : data_list)
        {
            if (i.size() > 0)
            {
                processed_data[count] = i.size();
            }
            else{
                processed_data[count] = 0;
            }
            count++;
        }
    }

    std::vector<int> &InitDataList::getData()
    {
        return processed_data;
    }
    int &InitDataList::getScale()
    {
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