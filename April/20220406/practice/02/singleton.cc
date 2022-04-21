#include <iostream>

class Singleton
{
    public:
    static Singleton *getinstance(int data = 100)
    {
        if(!only)
        {
            only = new Singleton(data);
        }
        return only;
    }
    void print()
    {
        std::cout << _data << std::endl;
    }
    private:
    class AutoRelease
    {
        public:
        AutoRelease()
        {
            std::cout << "AutoRelease()" << std::endl;
        }
        ~AutoRelease()
        {
            if(only)
            {
                delete only;
                only = nullptr;
            }
            std::cout << "~AutoRelease()" << std::endl;
        }
    };
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
    static AutoRelease AR;
};
Singleton *Singleton::only = nullptr;
Singleton::AutoRelease Singleton::AR;
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