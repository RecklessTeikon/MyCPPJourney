#include <iostream>
#include <string>

static int idNum = 0;
class Student
{
    public:

    Student(int idNum = ++idNum, std::string name = "default", int age = 18)
    :_idNum(0)
    ,_name("Undefine Name")
    ,_age(0)
    {
        std::cout << "构造函数已调用" << std::endl;
        _idNum = idNum;
        _name = name;
        _age = age;
    }

    void outPut()
    {
        std::cout << "姓名: " << _name << std::endl
        << "学号: " << idNum << std::endl << "年龄: " << _age << std::endl;
    }
    private:

    int _idNum;
    std::string _name;
    int _age;
};

int main()
{
    Student test(idNum,"张三");
    test.outPut();
    return 0;
}