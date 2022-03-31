#include <iostream>
#include <string.h>

class Heaponly
{
    public:
    Heaponly(const char *data = "")
    :_data(new char[strlen(data) + 1])
    {
        strcpy(_data, data);
        std::cout << "构造函数已被调用" << std::endl;
    }
    void *operator new(size_t size)
    {
        std::cout << "new 已被调用" << std::endl;
        void *ret = malloc(size);
        return ret;
    }
    void operator delete(void *p)
    {
        free(p);
        std::cout << "delete 已被调用" << std::endl;
    }
    void destory()
    {
        delete this;
    }
    void print()
    {
        std::cout << "data: " << _data << std::endl;
    }
    private:
    ~Heaponly()
    {
        delete [] _data;
        std::cout << "析构函数已被调用" << std::endl;
    }

    char *_data;
};

void test1()
{
    Heaponly *p = new Heaponly("Hello World");
    p->print();

    p->destory();
}
int main()
{
    test1();
    return 0;
}