#include <iostream>

void test1()
{
    int *p = new int(10);
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;
    delete p;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;//delete 后依旧能访问
}
void test2()
{
    int *p = new int[10]{0,1,2,3,4,5,6,7,8,9};
    for(int i = 0;i < 10;++i)
    {
        std::cout << "p + i = " << p + i << std::endl;
        std::cout << "*(p + i) = " << *(p + i) << std::endl;
    }
    delete[] p;
    for(int i = 0;i < 10;++i)
    {
        std::cout << "p + i = " << p + i << std::endl;
        std::cout << "*(p + i) = " << *(p + i) << std::endl;
    }
}
int main()
{
    //test1();
    test2();
    return 0;
}