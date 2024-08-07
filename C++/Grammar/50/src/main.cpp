#include <iostream>

/*
* 本程序演示类型双关
*/

struct Entity {
    int x, y;

    int* get_pos() {
        return &x; //Entity开头
    }
};

int main() {
    int a = 50;
    double value1 = a; //隐式转换
    double value2 = *(double*)&a; //复制a的内存到value2不做转换
    std::cout << value1 << ", " << value2 << '\n';

    Entity e = { 5, 8 };
    int* pos = (int*)&e;
    std::cout << pos[0] << ", " << pos[1] << '\n';

    int y_val = *(int*)((char*)&e + 4);
    std::cout << y_val << '\n';

    int* position = e.get_pos();
    std::cout << position[0] << ", " << position[1] << '\n';

    return 0;
}
