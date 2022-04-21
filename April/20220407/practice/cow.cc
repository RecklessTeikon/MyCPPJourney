#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Mystring
{
    class Mychar;
    public:
    Mystring()
    :_ptr(new Mychar[1 + 4]())
    {
        _ptr += 4;
        initRefcnt();
    }
    Mystring(const char *str)
    :_ptr(new Mychar[strlen(str) + 1 + 4])
    {
        _ptr += 4;
        initRefcnt();
        strcpy(reinterpret_cast<char*>(_ptr), str);
    }
    Mystring(const Mystring &str)
    :_ptr(str._ptr)
    {
        increaseRefcnt();
    }
    Mystring &operator=(const Mystring &str)
    {
        if(this != &str)
        {
            release();
            _ptr = str._ptr;
            increaseRefcnt();
        }
        return *this;
    }
    Mystring &operator=(const char *str)
    {
        release();
        _ptr = new Mychar[strlen(str) + 1 + 4];
        _ptr += 4;
        initRefcnt();
        strcpy(reinterpret_cast<char*>(_ptr), str);
        return *this;
    }
    Mychar &operator[](int idx)
    {
        Mychar *temp = new Mychar[strlen(reinterpret_cast<char*>(_ptr)) + 1 + 4];
        temp += 4;
        strcpy(reinterpret_cast<char*>(temp), reinterpret_cast<char*>(_ptr));
        *(reinterpret_cast<int*>(temp - 4)) = 1;
        release();
        _ptr = temp;
        return *(_ptr + idx);
    }
    Mychar &operator[](int idx) const
    {
        return *(_ptr + idx);
    }
    void initRefcnt()
    {
        *(reinterpret_cast<int*>(_ptr - 4)) = 1;
    }
    int &getRefcnt()
    {
        return *(reinterpret_cast<int*>(_ptr - 4));
    }
    void increaseRefcnt()
    {
        ++*(reinterpret_cast<int*>(_ptr - 4));
    }
    void decreaseRefcnt()
    {
        --*(reinterpret_cast<int*>(_ptr - 4));
    }
    void release()
    {
        decreaseRefcnt();
        if(getRefcnt() == 0)
        {
            delete [] (_ptr - 4);
            _ptr = nullptr;
            cout << ">>> delete" << endl;
        }
    }
    ~Mystring()
    {
        release();
    }
    friend std::ostream &operator<<(std::ostream &os, const Mystring &str);
    friend std::ostream &operator<<(std::ostream &os, const Mystring::Mychar &achar);
    private:
    class Mychar
    {
        public:
        Mychar()
        :_elem('\0')
        {}
        Mychar(char elem)
        :_elem(elem)
        {}
        Mychar(const Mychar &mychar)
        :_elem(mychar._elem)
        {}
        Mychar &operator=(const char elem)
        {
            _elem = elem;
            return *this;
        }
        Mychar &operator=(const Mychar elem)
        {
            _elem = elem._elem;
            return *this;
        }
        ~Mychar()
        {}
        friend std::ostream &operator<<(std::ostream &os, const Mystring::Mychar &achar);
        private:
        char _elem;
    };
    Mychar *_ptr;
};
std::ostream &operator<<(std::ostream &os, const Mystring &str)
{
    for(int i = 0; *(reinterpret_cast<char*>(str._ptr + i)) != '\0'; ++i)
    {
        os << *(reinterpret_cast<char*>(str._ptr + i));
    }
    return os;
}
std::ostream &operator<<(std::ostream &os, const Mystring::Mychar &achar)
{
    os << achar._elem;
    return os;
}
void test()
{
    Mystring str2("hello world");
    Mystring str1(str2);
    cout << str1 << " " << str2 << endl;
    cout << "str1.refcnt: " << str1.getRefcnt() << endl;
    cout << "str2.refcnt: " << str2.getRefcnt() << endl;

    str1[1] = 'X';
    cout << str1 << " " << str2 << endl;
    cout << "str1.refcnt: " << str1.getRefcnt() << endl;
    cout << "str2.refcnt: " << str2.getRefcnt() << endl;
    cout << str1[1] << endl; 
    cout << (str2[2] = 'X') << endl;
    cout << str1 << " " << str2 << endl;
    cout << "str1.refcnt: " << str1.getRefcnt() << endl;
    cout << "str2.refcnt: " << str2.getRefcnt() << endl;
}
int main()
{
    test();
    return 0;
}