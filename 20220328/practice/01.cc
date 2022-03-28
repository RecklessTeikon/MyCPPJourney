#include <iostream>

void test1()
{
    static int hot = 200;
    int &ref = hot;
    hot = hot + 100;
    std::cout << ref << std::endl;
}
int main()
{
    test1();
    return 0;
}