#include "PIMPL.hpp"
#include <iostream>

class Line::LineIMPL
{
    private:
    class Point
    {
        public:
        Point(int x = 0, int y = 0)
        :_x(x)
        ,_y(y)
        {

        }
        void printPoint() const
        {
            std::cout << "(" << _x << "," << _y << ")";
        }
        private:
        int _x;
        int _y;
    };
    Point _p1;
    Point _p2;

    public:
    LineIMPL(int x1, int y1, int x2, int y2)
    :_p1(x1, y1)
    ,_p2(x2, y2)
    {

    }
    void printPoint()
    {
        _p1.printPoint();
        std::cout << "------>";
        _p2.printPoint();
        std::cout << std::endl;
    }
};

Line::Line(int a, int b, int c, int d)
:_pimpl(new LineIMPL(a, b, c, d))
{
}

Line::~Line()
{
    if(_pimpl)
    {
        delete _pimpl;
        _pimpl = nullptr;
    }
}

void Line::printLine() const
{
    _pimpl->printPoint();
}