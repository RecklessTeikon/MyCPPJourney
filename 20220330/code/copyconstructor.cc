#include <iostream>

class Point
{
    public:

    Point(int x = 0, int y = 0)
    :_x(0)
    ,_y(0)
    {
        _x = x;
        _y = y;
        std::cout << "构造函数已被调用" << std::endl;
    }

    Point(const Point &p)
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
};
void printPoint(Point p)
{
    p.print();
}
Point returnPoint()
{
    Point p1(7, 7);
    return p1;
}
void test1()
{
    Point p1(7, 7);
    Point p2(p1);
    p1.print();
    p2.print();
}
void test2()
{
    Point p1(7, 7);
    p1.print();
    printPoint(p1);
}
void test3()
{
    printPoint(returnPoint());
}
int main()
{
    //test1();//第一种调用拷贝构造函数情况
    //test2();//第二种，传参时将实际参数值传递拷贝
    //test3();//第三种，返回时将对象拷贝至主调函数 避免编译器优化使用g++ copyconstructor.cc -fno-elide-constructors 查看结果
    return 0;
}