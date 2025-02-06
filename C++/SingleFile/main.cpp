#include <iostream>

using namespace std;

extern const int arg;
int *p1, p2;

int main()
{
    int dval = arg;
    int *pd = &dval;
    return 0;
}
