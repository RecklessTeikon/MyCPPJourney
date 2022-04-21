#include <iostream>
#include <vector>

using std::vector;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
 HeapSort(T *arr, size_t size, Compare com)
 :vec(arr, arr + size)
 {
    sort(com);
 }
 void heapAdjust(size_t pos,size_t len,Compare &com)
 {
    int dad = pos;
    int son = dad * 2 + 1;
    while(son < len)
    {
        if(son + 1 < len && vec[son] < vec[son + 1])
        {
            son += 1;
        }
        if(vec[son] > vec[dad])
        {
            T temp = vec[son];
            vec[son] = vec[dad];
            vec[dad] = temp;
            dad = son;
            son = dad * 2 + 1;
        }
        else break;
    }
 }
 void sort(Compare &com)
 {
    int i;
    for(i = vec.size() / 2 - 1; i >= 0; --i)
    {
        heapAdjust(i, vec.size(), com);
    }
    T temp = vec[0];
    vec[0] = *(vec.end() - 1);
    *(vec.end() - 1) = temp;
    for(i = vec.size() - 1; i > 1; --i)
    {
        heapAdjust(0, i, com);
        T temp = vec[0];
        vec[0] = vec[i - 1];
        vec[i - 1] = temp;
    }
 }
 void print()
 {
     for(auto &elem: vec)
        {
            std::cout << elem << std::endl;
        }
 }

private:
 vector<T> vec;
};
int main()
{
    std::less<int> com;
    int arr[10] = {4, 3, 6, 2, 8, 1, 9, 5, 0, 7};
    HeapSort<int> hsort(arr, 10, com);
    hsort.print();
    return 0;
}