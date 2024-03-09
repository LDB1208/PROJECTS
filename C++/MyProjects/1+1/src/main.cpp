#include <cstdio>

int main() {
    int a[2], * ptr = a;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0) = 1;
    *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 4) = a[0];
    printf("%d", a[0] + a[1]);
    return 0;
}
