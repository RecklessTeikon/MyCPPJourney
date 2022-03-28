#include <iostream>
namespace name
{
    extern int nint;
}
// int number = 5;
namespace
{
    int number = 777;
}
namespace test
{
    int number = 10;
    void print()
    {
        std::cout << "test::print() is called." << std::endl;
        std::cout << "the number is :" << number << std::endl;
    }
    namespace testtest
    {
        int number = 20; //就近原则，优先使用相同命名空间的实体
        void print()
        {
            std::cout << "testtest::print() is called." << std::endl;
            std::cout << "the number is :" << number << std::endl;
        }
    }
}
// using test::number;
using namespace test;
void test1()
{
    // print();
}
void test2()
{
    // test::print();
}
void test3()
{
    test::testtest::print(); //命名空间嵌套使用
}
void test4()
{
    // extern int gint;

    // extern int aint;
    // std::cout << "global number =" << test::number << std::endl;
    // std::cout << "number =" << number << std::endl;
    // std::cout << "gint =" << gint << std::endl;
    std::cout << "nint =" << name::nint << std::endl;
    // std::cout << "aint =" << aint << std::endl;
}
int main()
{
    // test1();
    // test2();
    // test3();
    test4();
    return 0;
}