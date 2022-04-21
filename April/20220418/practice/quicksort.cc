#include <iostream>
#include <vector>

using std::vector;

template<typename T,typename Compare=std::less<T>>
class MyQsort
{
public:
	MyQsort(T *arr, size_t size, Compare com)
    :_vec(arr, arr + size)
    {
        quick(0, size - 1, com);
    }
	void quick(int left, int right, Compare &com)
    {
        int p = partition(left, right, com);
        if(p > left)
        quick(left, p - 1, com);
        if(right > p + 1)
        quick(p + 1, right, com);
    }
	int partition(int left, int right, Compare &com)
    {
        int j = right, k = right;
        for(;j > left; --j)
        {
            if(com(_vec[left], _vec[j]))
            {
                T temp = _vec[j];
                _vec[j] = _vec[k];
                _vec[k] = temp;
                --k;
            }
        }
        T temp = _vec[left];
        _vec[left] = _vec[k];
        _vec[k] = temp;

        return k;
    }
	void print()
    {
        for(auto &elem: _vec)
        {
            std::cout << elem << std::endl;
        }
    }
private:
	vector<T> _vec;
};

int main()
{
    std::less<int> com;
    int arr[10] = {4, 3, 6, 2, 8, 1, 9, 5, 0, 7};
    MyQsort<int> sort(arr, 10, com);
    sort.print();
    return 0;
}