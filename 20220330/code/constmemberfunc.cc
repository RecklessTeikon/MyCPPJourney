#include <iostream>

class Point
{
public:
    Point(int x = 0, int y = 0)
        : _x(x), _y(y)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }
    #if 0
    void print() const
    {
        //_x = 10;
        std::cout << "P(" << _x << ", " << _y << ")" << std::endl;
    }
    #endif
    void doubleprint() const
    {
        print();
        print();
    }
    void print()
    {
        std::cout << "P(" << _x << ", " << _y << ")" << std::endl;
    }
private:
    int _x;
    int _y;
};
void test1()
{
    Point a(1, 2);
    a.print();
    a.doubleprint();
}
int main()
{
    test1();
    return 0;
}