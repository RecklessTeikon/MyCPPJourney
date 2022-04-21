#ifndef __PIMPL__
#define __PIMPL__
class Line
{
    public:
    Line(int, int, int, int);
    ~Line();
    void printLine() const;
    class LineIMPL;
    private:
    LineIMPL *_pimpl;
};
#endif