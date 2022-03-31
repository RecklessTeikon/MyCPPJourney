#include <iostream>

class Singleton
{
    public:
    static Singleton *getinstance()
    {
        if(_ptr == nullptr)
        {
            _ptr = new Singleton();//此处调用构造函数
        }
        return _ptr;
    }
    static void destoryinstance()
    {
        if(_ptr != nullptr)
        {
            delete _ptr;
            _ptr == nullptr;
        }
    }
    void print()
    {
        std::cout << "data: " << _data << std::endl;
    }
    private:
    Singleton()
    :_data(1)
    {
        std::cout << "单例构造函数已被调用" << std::endl;
    }
    ~Singleton()
    {
        std::cout << "单例析构函数已被调用" << std::endl;
    }
    static Singleton *_ptr;
    int _data;
};
Singleton *Singleton::_ptr = nullptr;

void test()
{
    std::cout << "addr: " << Singleton::getinstance() << std::endl;//
    std::cout << "addr: " << Singleton::getinstance() << std::endl;
    Singleton::getinstance()->print();
    Singleton::destoryinstance();
}
int main()
{
    test();
    return 0;
}