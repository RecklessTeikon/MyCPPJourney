#include <iostream>

void test1()
{
    int a = 10, b =20, c = 10;
    const int *p = &a;//只是不能通过指针修改指针指向的值，指针本身是可以修改的。而且被指向的值可以通过其他方式修改
    //a = 20;
    //*p = 20;
    std::cout << "p = " << p << std::endl;
    p = &b;
    //p = &c;
    std::cout << "after change p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;
}
void test2()
{
    int a = 10, b =20, c = 10;
    int * const p = &a;//指针本身不能修改
    //p = &b;
    //p = &c;
    *p = 20;//但是可以通过指针修改指向变量的值
}
int main()
{
    //test1();
    //test2();
    //const int * const p 总之啥都不能改。
    return 0;
}