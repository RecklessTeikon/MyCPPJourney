#include <iostream>
#include <string.h>
class Student 
{
    public:

    Student(const char *name = "", int id = 0)
    :_name(new char[strlen(name) + 1])
    ,_id(id)
    {
        strcpy(_name, name);
        std::cout << "构造函数已被调用" << std::endl;
    }
    Student(const Student &s)
    :_name(new char[strlen(s._name + 1)])
    ,_id(s._id)
    {
        strcpy(_name, s._name);
        std::cout << "拷贝构造函数已被调用" << std::endl;
    }
    ~Student()
    {
        delete [] _name;
        std::cout << "析构函数已被调用" << std::endl;
    }
    void *operator new(size_t size)
    {
        void *ret = malloc(size);
        std::cout << "new 已被调用" << std::endl;
        return ret;
    }

    void operator delete(void *p)
    {
        std::cout << "delete 已被调用" << std::endl;
        free(p);
    }
    void print()
    {
        std::cout << "姓名：" << _name << std::endl << "id：" << _id << std::endl;
    }
    private:
    
    char *_name;
    int _id;
};
void test1()
{
    Student s1("张三", 1);
    Student *ps2 = new Student("李四", 2);
    s1.print();
    ps2->print();
    delete ps2;
    std::cout << "s2已被释放" << std::endl;
}
int main()
{
    test1();
    return 0;
}