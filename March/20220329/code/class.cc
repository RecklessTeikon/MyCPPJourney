#include <iostream>
#include <string>

class Computer
{
    public:
    //公共数据成员和成员函数

    void setbrand(const std::string brand)
    {
        _brand = brand;
    }

    void setprice(int price)
    {
        _price = price;
    }

    void print();
    /*
    {
        std::cout << "品牌：" << _brand << std::endl << "价格：" << _price <<std::endl;
    }
    */

    protected:
    //保护数据成员和成员函数

    private:
    //私有数据成员和成员函数

    std::string _brand;
    int _price;
};
void Computer::print()
{
    std::cout << "品牌：" << _brand << std::endl << "价格：" << _price <<std::endl;//成员函数可以在类外实现
}

void test1()
{
    Computer c1;
    c1.setbrand("xiaomi");
    c1.setprice(7777);
    c1.print();
    //c1._price = 8888; //private成员不能类外访问
}
int main()
{
    test1();
    return 0;
}