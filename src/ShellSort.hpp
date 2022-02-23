//
// Created by pink on 2022/2/23.
//

#ifndef DATA_STRUCT_AND_ALGORITHM_SHELLSORT_HPP
#define DATA_STRUCT_AND_ALGORITHM_SHELLSORT_HPP

#include "Sort.hpp"

template <typename T>
class ShellSort : public Sort<T>{
private:
    void exch(T& m, T& n)
    {
        auto temp = std::move(m);
        m = std::move(n);
        n = std::move(temp);
    }
public:
    void sort(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp);
};

template <typename T>
void ShellSort<T>::sort(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp)
{
    size_t len = vec.size();
    int h = 1;
    while (h < len / 3) h = h * 3 + 1;
    while (h >= 1)
    {
        for(int i = h; i < len; ++i)
        {
            for(int j = i; j >= h && cmp(vec[j], vec[j-h]); j -= h) {
                exch(vec[j], vec[j - h]);
            }
        }
        h = h/3;
    }
}


#endif //DATA_STRUCT_AND_ALGORITHM_SHELLSORT_HPP
