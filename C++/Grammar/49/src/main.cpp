#include <iostream>
#include <vector>
#include <algorithm> //std::sort
#include <functional> //std::greater<int>()

/*
* 本程序演示排序(std::sort)
*/

int main() {
    std::vector<int> values = { 3, 5, 1, 4, 2 };

    std::sort(values.begin(), values.end()); //升序
    //values.begin()和end()都是迭代器
    for (int i : values)
        std::cout << i << ' ';

    std::cout << '\n';

    std::sort(values.begin(), values.end(), std::greater<int>()); //降序
    for (int i : values)
        std::cout << i << ' ';

    std::cout << '\n';

    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a < b; //升序(若a < b, 则a排在b前)
    });
    for (int i : values)
        std::cout << i << ' ';

    std::cout << '\n';

    std::sort(values.begin(), values.end(), [](int a, int b) {
        if (a == 1)
            return false;
        else if (b == 1)
            return true;
        return a < b;
    });
    for (int i : values)
        std::cout << i << ' ';

    return 0;
}
