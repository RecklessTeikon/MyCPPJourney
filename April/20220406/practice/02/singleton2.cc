#include <iostream>
#include <pthread.h>

class Singleton
{
    public:
    static Singleton *getinstance(int data = 100)
    {
        pthread_once(&_once, init);
        return only;
    }
    static void init()
    {
        atexit(destory);
        only = new Singleton();
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
    static pthread_once_t _once;
};
Singleton *Singleton::only = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

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