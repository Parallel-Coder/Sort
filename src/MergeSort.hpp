//
// Created by pink on 2022/2/23.
//

#ifndef DATA_STRUCT_AND_ALGORITHM_MERGESORT_HPP
#define DATA_STRUCT_AND_ALGORITHM_MERGESORT_HPP

#include "Sort.hpp"

template <typename T>
class MergeSort : public Sort<T>{
private:
    void exch(T& m, T& n)
    {
        auto temp = std::move(m);
        m = std::move(n);
        n = std::move(temp);
    }

    void merge(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp, int lo, int mid, int hi);
    void sort(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp, int lo, int hi);

    std::vector<T> cp_v;
public:
    void sort(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp);
};

template <typename T>
void MergeSort<T>::merge(std::vector <T> &vec, std::function<bool(T &, T &)> &cmp, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;

    for(int i = lo; i < hi; ++i) cp_v[i] = vec[i];

    for(int k = lo; k <= hi ; k++)
    {
        if      ( i > mid)              v[k] = cp_v[j++];
        else if ( j > hi)               v[k] = cp_v[i++];
        else if (cmp(cp_v[j], cp_v[i])) v[k] = cp_v[j++];
        else                            v[k] = cp_v[i++];
    }
}

template <typename T>
void MergeSort<T>::sort(std::vector <T> &vec, std::function<bool(T &, T &)> &cmp) {
    cp_v = std::vector<T>(vec.size());
    sort(vec, 0, vec.size() - 1);
}

template <typename T>
void MergeSort<T>::sort(std::vector<T> &vec, std::function<bool(T&, T&)> &cmp, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) >> 1;
    sort(vec, lo, mid);
    sort(vec, mid + 1, hi);
    merge(vec, lo, mid, hi);
}


#endif //DATA_STRUCT_AND_ALGORITHM_MERGESORT_HPP
