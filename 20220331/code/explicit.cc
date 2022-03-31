#include <iostream>

class Point
{
    public:
    explicit
    Point(int x = 0, int y = 0)
    :_x(x)
    ,_y(y)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }
    private:
    int _x;
    int _y;

};

void test1()
{
    Point p = 1;//很不符合规范
}

int main()
{
    test1();
    return 0;
}