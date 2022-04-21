#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Mystring
{
    public:
    Mystring()
    :_ptr(new char[1 + 4])
    ,_charproxy(this, 0)
    {
        _ptr += 4;
        getRefCount() = 1;
        *_ptr = '\0';
    }
    Mystring(const char *str)
    :_ptr(new char[strlen(str + 1) + 4])
    ,_charproxy(this, 0)
    {
        _ptr += 4;
        getRefCount() = 1;
        strcpy(_ptr, str);
    }
    Mystring(const Mystring &str)
    :_ptr(str._ptr)
    ,_charproxy(this, 0)
    {
        ++getRefCount();
    }
    Mystring &operator=(const Mystring &str)
    {
        release();
        _ptr = str._ptr;
        ++getRefCount();
        return *this;
    }
    void release()
    {
        --getRefCount();
        if(!getRefCount())
        {
            delete [] (_ptr - 4);
        }
        _ptr = nullptr;
    }
    ~Mystring()
    {
        release();
    }
    int &getRefCount()
    {
        return *(reinterpret_cast<int*>(_ptr - 4));
    }
    char *&getstr()
    {
        return _ptr;
    }
    class CharProxy
    {
        public:
        CharProxy(Mystring *str, unsigned idx)
        :_str(str)
        ,_idx(idx)
        {}
        unsigned &getidx()
        {
            return _idx;
        }
        CharProxy &operator=(const char x)
        {
            if(_str->getstr()[_idx] != x)
            {
                char *temp = new char[strlen(_str->getstr() + 1 + 4)];
                strcpy(temp + 4, _str->getstr());
                *(temp + 4 + _idx) = x;
                _str->release();
                _str->getstr() = temp + 4;
                _str->getRefCount() = 1;
            }
            return *this;
        }
        friend std::ostream &operator<<(std::ostream &os, const Mystring::CharProxy &charproxy);
        private:
        Mystring *_str;
        unsigned _idx;
    };
    CharProxy &operator[](unsigned idx)
    {
        _charproxy.getidx() = idx;
        return _charproxy;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mystring &str);
    private:
    char *_ptr;
    CharProxy _charproxy;
};
std::ostream &operator<<(std::ostream &os, const Mystring &str)
{
    os << str._ptr;
    return os;
}
std::ostream &operator<<(std::ostream &os, const Mystring::CharProxy &charproxy)
{
    os << (charproxy._str->getstr())[charproxy._idx];
    return os;
}
void test()
{
    Mystring s1("hello");
    Mystring s2;
    Mystring s3("world");
    Mystring s4("hello world");
    s2 = s1;
    s1[1] = 'o';
    //cout << s1 << endl;
    cout << s1.getRefCount() << endl;
    cout << s2.getRefCount() << endl;

}
int main()
{
    test();
    return 0;
}