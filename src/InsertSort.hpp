//
// Created by pink on 2022/2/22.
//

#ifndef DATA_STRUCT_AND_ALGORITHM_INSERTSORT_HPP
#define DATA_STRUCT_AND_ALGORITHM_INSERTSORT_HPP

#include "Sort.hpp"

template <typename T>
class InsertSort : public Sort<T>{
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
void InsertSort<T>::sort(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp)
{
	size_t len 	= vec.size();
    for(int i = 0; i < len; ++i)
    {
        auto& temp = vec[i];
        for(int j = 0; j < i; ++j)
        {
            if (cmp(temp, vec[j]))
            {
                exch(vec[i], vec[j]);
            }
        }
    }

}




#endif //DATA_STRUCT_AND_ALGORITHM_INSERTSORT_HPP
