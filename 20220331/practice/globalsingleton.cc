#include <iostream>

class Globalsingleton
{
    public:
    
    static Globalsingleton *getinstance()
    {
        if(_ptr == nullptr)
        {
            static Globalsingleton only;
            _ptr = &only;
        }
        return _ptr;
    }
    void print()
    {
        std::cout << "data:" << _data << std::endl;
    }
    ~Globalsingleton()
    {
        std::cout << "析构函数已被调用" << std::endl;
    }
    private:

    Globalsingleton()
    :_data(100)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }

    Globalsingleton(const Globalsingleton&);

    int _data;
    static Globalsingleton *_ptr;
};
Globalsingleton *Globalsingleton::_ptr = nullptr;

void test()
{
    Globalsingleton *p = Globalsingleton::getinstance();
    p->print();
    Globalsingleton *p2 = Globalsingleton::getinstance();

    std::cout << "p = " << p << std::endl;
    std::cout << "p2 = " << p2 << std::endl;
}
int main()
{
    test();
    return 0;
}