#include <iostream>

class Point
{
    public:
    #if 1
    Point(int x = 0, int y = 0)
    :_x(x)
    ,_y(y)
    {
        //_x = x;
        //_y = y;//只能在初始化表达式中初始化
        std::cout << "拷贝构造函数已被调用" << std::endl;
    }
    #endif
    #if 0 //C++11的方法
    Point() = default;
    #endif
    void print()
    {
        std::cout << "P(" << _x << ", " << _y << ")" << std::endl; 
    }
    private:
    #if 1
    const int _x;
    const int _y;
    #endif

    #if 0//C++11的方法
    const int _x = 10;
    const int _y = 10;
    #endif
    
};
void test1()
{
    //Point p;
    //p.print();
}
void test2()
{
    Point p(4, 5);
    p.print();
}
int main()
{
    //test1();
    test2();
    return 0;
}