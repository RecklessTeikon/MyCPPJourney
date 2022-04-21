#include <iostream>

class Singleton
{
    public:
    static Singleton *getinstance()
    {
        static Singleton s;
        return &s;
    }
    void print()
    {
        std::cout << _data << std::endl;
    }
    private:
    Singleton(int data = 1000)
    :_data(data)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }
    ~Singleton()
    {
        std::cout << "析构函数已被调用" << std::endl;
    }

    int _data;
};
Singleton *only = Singleton::getinstance();

void test()
{
    std::cout << only->getinstance() << std::endl;
    std::cout << only->getinstance() << std::endl;

    only->print();   
}

int main()
{
    test();
    return 0;
}