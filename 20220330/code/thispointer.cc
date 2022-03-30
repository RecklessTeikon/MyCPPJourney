#include <iostream>

class Point
{
    public:

    Point(int x = 0, int y = 0)
    :_x(x)
    ,_y(y)
    {
        std::cout << "构造函数已调用" << std::endl;
    }
    void print()
    {
        std::cout << "this: " << this << std::endl;
        std::cout << "P(" << this->_x << ", " << this->_y << ")" << std::endl;
    }
    private:
    int _x;
    int _y;
};
void test1()
{
    Point p(5,6);
    p.print();
    std::cout << "&p: " << &p << std::endl;
    //Point::print(&p)
}
int main()
{
    test1();
    return 0;
}