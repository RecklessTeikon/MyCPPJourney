#include <iostream>
#include <string.h>

class Computer
{
    public:
    Computer(const char *brand, int price)
    :_brand(new char[strlen(brand) + 1])
    ,_price(price)
    {
        strcpy(_brand,brand);
        std::cout << "构造函数已被调用" << std::endl;
        _totalprice += _price;
        std::cout << "总价：" << _totalprice << std::endl;
    }
    ~Computer()
    {
        delete _brand;
        std::cout << "析构函数已被调用" << std::endl;
    }
    static void gettotalprice()
    {
        std::cout << "总价：" << _totalprice << std::endl;
        //std::cout << "价格：" << _price << std::endl;//静态成员函数只能访问静态成员数据
    }
    void print()
    {
        std::cout << "品牌：" << _brand << std::endl << "价格：" << _price << std::endl
        << "总价：" << _totalprice << std::endl;
    }
    private:
    char *_brand;
    int _price;
    static int _totalprice;
};
int Computer::_totalprice = 0;
