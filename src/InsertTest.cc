// InsertTest


#include "InsertSort.hpp"
#include <assert.h>
#include <algorithm>

static bool cmp(int& i, int& j)
{
	return i < j;
}

int main(int argc, char* argv[])
{
	InsertSort<int> sorter;
	std::vector<int> v = {1,9,2,3,4,5,6,12,534,123,5,4657,	123, 345};
	std::vector<int> cp_v(v);
    std::function<bool(int&, int&)> f_cmp(cmp);
	sorter.sort(v, f_cmp);
	sort(cp_v.begin(), cp_v.end(), cmp);

	assert(v == cp_v);
}