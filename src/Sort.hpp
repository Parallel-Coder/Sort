#ifndef DATA_STRUCT_AND_ALGORITHM_SORT_HPP
#define DATA_STRUCT_AND_ALGORITHM_SORT_HPP

#include <functional>
#include <vector>

template<typename T>
class Sort {
public:
	virtual void sort(std::vector<T>& vec, std::function<bool(T&, T&)>& cmp) = 0;
};

#endif