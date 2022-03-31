#include <iostream>

int add(int a, int b)
{
    return a + b;
}
int add(int a, int b, int c)
{
    return a + b + c;
}
void test1()
{
    int a = 1, b = 2, c = 3;
    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a + b + c = " << add(a, b, c) << std::endl;
}
int main()
{
    test1();
    return 0;
}