#include <iostream>
#include <vector>
#include <algorithm> //std::sort
#include <functional> //std::greater<int>()

/*
* ��������ʾ����(std::sort)
*/

int main() {
    std::vector<int> values = { 3, 5, 1, 4, 2 };

    std::sort(values.begin(), values.end()); //����
    //values.begin()��end()���ǵ�����
    for (int i : values)
        std::cout << i << ' ';

    std::cout << '\n';

    std::sort(values.begin(), values.end(), std::greater<int>()); //����
    for (int i : values)
        std::cout << i << ' ';

    std::cout << '\n';

    std::sort(values.begin(), values.end(), [](int a, int b) {
        return a < b; //����(��a < b, ��a����bǰ)
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
