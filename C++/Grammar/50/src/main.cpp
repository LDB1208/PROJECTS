#include <iostream>

/*
* ��������ʾ����˫��
*/

struct Entity {
    int x, y;

    int* get_pos() {
        return &x; //Entity��ͷ
    }
};

int main() {
    int a = 50;
    double value1 = a; //��ʽת��
    double value2 = *(double*)&a; //����a���ڴ浽value2����ת��
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
