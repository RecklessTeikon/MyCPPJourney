#include <iostream>
#include <string.h>

class Computer
{
    public:
    Computer(const char *brand, const int price)
    {
        printf("构造函数已被调用\n");
        _brand = new char[strlen(brand) + 1];
        strcpy(_brand, brand);
        _price = price;
    }
    Computer(const Computer &computer)
    {
        printf("拷贝构造函数已被调用\n");
        _brand = new char[strlen(computer._brand) + 1];//构造函数最好还是把这一行写进初始化里
        strcpy(_brand, computer._brand);
        _price = computer._price;
    }
    ~Computer()//系统默认的析构函数无法释放构造函数申请的堆空间，这就需要自写显式析构函数
    {
        printf("析构函数已被调用\n");
        delete[] _brand;
        _brand = NULL;
    }
    void print()
    {
        printf("品牌：%s\n", _brand);
        printf("价格：%d\n", _price);
    }
    private:
    char *_brand;
    int _price;
};
void test1()
{
    Computer c1("xiaomi", 7777);
    //Computer c2(c1);
    Computer c2 = c1;
    c1.print();
    c2.print();//会报double free
}
int main()
{
    test1();
    return 0;
}