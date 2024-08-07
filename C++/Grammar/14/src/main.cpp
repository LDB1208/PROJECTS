#include <iostream>

using namespace std;

/*
 * ��������ʾ�̳�
 */

class Entity {
public:
    float x, y;

    void Move(float xa, float ya) {
        x += xa;
        y += ya;
        cout << x << ", " << y << endl;
    }
};

class Player1 : public Entity { //Player�̳�Entity,����������������
public:
    const char* name = "LDB";

    void Print() {
        cout << name << endl;
    }
};

int main() {
    Player1 ex1;
    ex1.x = 1.2f;
    ex1.Move(1.1, 0.3); //ex1ʵ�����Ե���Entity���Player��ĺ���
    ex1.Print();

    cout << "====================" << endl;

    cout << sizeof(Entity) << endl; //����float(4�ֽ�),���8
    cout << sizeof(Player1) << endl; //����float(4�ֽ�)��һ��char*(8�ֽ�),���16
    return 0;
}
