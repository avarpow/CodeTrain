#include <functional>
#include <iostream>
class tp
{
public:
    void
    operator()(int *a, int size)
    {
        return;
    }
};
class tp2
{
public:
    void operator()(int *a, int size)
    {
        return;
    }
};
using namespace std;
void test(int *arr, int size, function<void (*pf)(int *, int)>) { pf(arr, size); }
int main()
{
    int x = 1;
    int *px = &x;
    int size = 10;
    test(px, size, (tp));
    //test(px, size, (tp2::operator()));
    return 0;
}