#include <iostream>
#include <string>

class Computer
{
    public:
    //公共数据成员和成员函数

    //构造函数
    #if 0
    Computer()
    {
        std::cout << "无参构造函数调用" << std::endl;
        setbrand("NULL");
        setprice(0);
    }

    Computer(const std::string brand, int price)
    {
        std::cout << "有参构造函数调用" << std::endl;
        setbrand(brand);
        setprice(price);
    }
    #endif
    Computer():_brand("hp"),_price(9999)//初始化构造函数 初始化顺序只和类内声明顺序相对应
    {

    }
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
void test2()
{
    Computer c2;//#if 0 被自定义构造
    //Computer c3("HUAWEI", 8888);
    c2.print();//#if 0 打印未定义值
    //c3.print();
    //默认参数 彳亍！
}
int main()
{
    //test1();
    test2();//构造函数自动调用
    return 0;
}