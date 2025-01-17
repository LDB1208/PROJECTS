#include <cstdio>

int main(){
    int a[2]{1, 1}, *ptr = a;
    printf("%d", *reinterpret_cast<int *>(reinterpret_cast<char *>(ptr)) +
                 *reinterpret_cast<int *>(reinterpret_cast<char *>(ptr) + sizeof(int)));
    return 0;
}
