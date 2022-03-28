#include <iostream>
#if 0
int add(int a)
{
    return a;
}
int add(int a, int b)
{
    return a + b;
}
#endif
int add(int a, int b = 0, int c = 0)
{
    return a + b + c;
}
void test1()
{
    int x = 1, y = 2, z = 3;
    std::cout << "x = " << add(x) << std::endl;
    std::cout << "x + y = " << add(x, y) << std::endl;
    std::cout << "x + y + z = " << add(x, y, z) << std::endl;
}
int main()
{
    test1();
    return 0;
}