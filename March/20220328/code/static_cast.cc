#include <iostream>

void test1()
{
    double val = 3.14;
    int vali = static_cast<int>(val);//用法类似于c语言中的圆括号强转
    std::cout << "vali = " << vali << std::endl;
}
int main(int argc, char const *argv[])
{
    test1();
    return 0;
}
