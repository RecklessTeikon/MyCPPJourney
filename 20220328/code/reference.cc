#include <iostream>

void swap(int &a, int &b);
void test1()
{
    int a = 1, b = 2;
    swap(a , b);
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}
int &add(int a, int b, int &c)
{
    c = a + b;
    return c;
}
int main()
{
    int c;
    int arr[5] = {0,1,2,3,4};
    //test1();
    std::cout << "add = " << add(3,4,c) << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "arr[0] = " << arr[0] << std::endl;
    std::cout << "after add arr[0] = " << add(arr[1],arr[2],arr[0]) << std::endl;

    for(int i = 0; i < 5 ; ++i)
    {
        std::cout << "arr[i] = " << arr[i] << std::endl;
    }
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}