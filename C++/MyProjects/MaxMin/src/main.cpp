#include <iostream>

int min(int a, int b, int c) { return (a < b && a < c) ? a : (b < c ? b : c); }

int max(int a, int b, int c) { return (a > b && a > c) ? a : (b > c ? b : c); }

int main() {
    int a, b, c;

    std::cout << "a:"; std::cin >> a;
    std::cout << "b:"; std::cin >> b;
    std::cout << "c:"; std::cin >> c;

    std::cout << "max:" << max(a, b, c) << std::endl;
    std::cout << "min:" << min(a, b, c) << std::endl;
    return 0;
}
