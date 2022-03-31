#include <iostream>

class Point
{
    public:

    Point(int x = 0, int y = 0)
    :_x(x)
    ,_y(y)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }
    #if 0
    Point(const Point &p)//不加const会报错
    {
        _x = p._x;
        _y = p._y;
        std::cout << "拷贝构造函数已被调用" << std::endl;
    }
    #endif
    #if 1
    Point(Point p)//没有 & 直接报错
    {
        _x = p._x;
        _y = p._y;
        std::cout << "拷贝构造函数已被调用" << std::endl;
    }
    #endif
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
    Point p1(1, 2);
    p1.print();
    Point p2 = Point(3, 4);//匿名对象，声明周期只有一个语句
    p2.print();
}

int main()
{
    //test1();
    return 0;
}