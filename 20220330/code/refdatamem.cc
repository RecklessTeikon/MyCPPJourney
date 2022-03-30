#include <iostream>

class Point
{
    public:

    Point(int x, int y, int &ref)
    :_x(0)
    ,_y(0)
    ,_ref(ref)
    {
        _x = x;
        _y = y;
        std::cout << "构造函数已被调用" << std::endl;
    }

    Point(const Point &p)
    :_ref(p._ref)
    {
        _x = p._x;
        _y = p._y;
        std::cout << "拷贝构造函数已被调用" << std::endl;
    }

    void print()
    {
        std::cout << "P(" << _x << ", " << _y << ")" << std::endl; 
    }

    private:

    int _x;
    int _y;
    int &_ref;
};