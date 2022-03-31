#include <iostream>

class Stackonly
{
    public:
    explicit
    Stackonly(int data = 0)
    :_data(data)
    {
        std::cout << "构造函数已被调用" << std::endl;
    }
    ~Stackonly()
    {
        std::cout << "析构函数已被调用" << std::endl;
    }
    void print()
    {
        std::cout << "data:" << _data << std::endl;
    }
    private:
    void *operator new(size_t size)
    {
        void *ptr = malloc(size);
        std::cout << "new 已被调用" << std::endl;
        return ptr;
    }

    void operator delete(void *p)
    {
        free(p);
        std::cout << "delete 已被调用" << std::endl;
    }
    int _data;
};

void test1()
{
    Stackonly test(777);
    //Stackonly *testp = new Stackonly(888);
    test.print();
}

int main()
{
    test1();
    return 0;
}