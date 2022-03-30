#include <iostream>

class Rectangle
{
    public:

    Rectangle(int length, int width)
    {
        std::cout << "构造函数已调用" << std::endl;
        _length = length;
        _width = width;
    }
    void printResult()
    {
        std::cout << "此长方形的面积为：" << _length * _width << std::endl
        << "此长方形的周长为：" << 2 * (_length + _width) << std::endl;
    }
    private:
    
    int _length;
    int _width;
};
void test1()
{
    Rectangle a(3,4);
    Rectangle b(5,6);
    a.printResult();
    b.printResult();
}
int main()
{
    test1();
    return 0;
}