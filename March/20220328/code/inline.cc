#include <iostream>
#define MAXVAL(x, y) (x > y ? x : y)

inline//必须和函数定义在一起。
//如果仅仅与声明放在一起，因为互联函数是在编译阶段处理，无法和外部模块链接
int Maxval(int x, int y)
{
    return x > y ? x : y;
}
void test1()
{
    int x = 3, y = 4;
    std::cout << "MAXVAL(x, y) = " << MAXVAL(x, y) << std::endl;
    std::cout << "Maxval(x, y) = " << Maxval(x, y) << std::endl;
}
int main()
{
    test1();
    return 0;
}