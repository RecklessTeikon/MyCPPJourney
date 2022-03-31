#include <iostream>
#include <string>

class Computer1
{
    public:

    Computer1(std::string brand = "default", int price = 0)
    :_brand(brand)
    ,_price(price)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }

    Computer1 &operator=(const Computer1 &c)
    {
        _brand = c._brand;
        _price = c._price;
        std::cout << "赋值运算符函数已被调用" << std::endl;

        return *this;
    }
    void print()
    {
        std::cout << "品牌：" << _brand << std::endl << "价格：" << _price << std::endl;
    }
    private:
    std::string _brand;
    int _price;
};
class Computer2
{
    public:

    Computer2(std::string brand = "default", int price = 0)
    :_brand(new std::string(brand))
    ,_price(price)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }

    ~Computer2()
    {
        delete _brand;
        std::cout << "析构函数已被调用" << std::endl;
    }
    #if 0
    Computer2 &operator=(const Computer2 &c)//默认会double free
    {
        _brand = c._brand;
        _price = c._price;
        std::cout << "赋值运算符函数已被调用" << std::endl;

        return *this;
    }
    #endif
    Computer2 &operator=(const Computer2 &c)
    {
        delete _brand;
        _brand = new std::string(*c._brand);
        _price = c._price;

        return *this;
    }
    void print()
    {
        std::cout << "品牌：" << *_brand << std::endl << "价格：" << _price << std::endl;
    }
    private:
    std::string *_brand;
    int _price;
};

void test1()
{
    Computer1 c1("HUAWEI", 7777), c2("XIAOMI", 8888);
    c1.print();
    c2.print();
    c1 = c2;
    //c1.operator=(c2);//等价于上个语句
    c1.print();
    c2.print();
}
void test2()
{
    Computer2 c1("HUAWEI", 7777), c2("XIAOMI", 8888);
    c1.print();
    c2.print();
    c1 = c2;
    c1.print();
    c2.print();

}
int main()
{
    //test1();
    test2();
    return 0;
}