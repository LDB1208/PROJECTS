#include <iostream>

using namespace std;

extern const int arg;
int *p1, p2;

int main()
{
    double dval = arg;
    double *pd = &dval;
    double *pd2 = pd; // 等价于double *pd2 = &dval;
    cout << pd << '\n'
         << *pd << '\n'
         << pd2 << '\n'
         << *pd2;
    return 0;
}
