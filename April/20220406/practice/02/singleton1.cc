#include <iostream>

class Singleton
{
    public:
    static Singleton *getinstance(int data = 100)
    {
        if(!only)
        {
            only = new Singleton(data);
            atexit(destory);
        }
        return only;
    }
    void print()
    {
        std::cout << _data << std::endl;
    }
    static void destory()
    {
        if(only)
        {
            delete only;
            only = nullptr;
        }
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
    static Singleton *only;
};
Singleton *Singleton::only = Singleton::getinstance();


void test()
{
    std::cout << Singleton::getinstance() << std::endl;
    std::cout << Singleton::getinstance() << std::endl;
    Singleton::getinstance()->print();
}

int main()
{
    test();
    return 0;
}