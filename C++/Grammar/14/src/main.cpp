#include <iostream>

using namespace std;

/*
 * 本程序演示继承
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

class Player1 : public Entity { //Player继承Entity,现在它有两种类型
public:
    const char* name = "LDB";

    void Print() {
        cout << name << endl;
    }
};

int main() {
    Player1 ex1;
    ex1.x = 1.2f;
    ex1.Move(1.1, 0.3); //ex1实例可以调用Entity类和Player类的函数
    ex1.Print();

    cout << "====================" << endl;

    cout << sizeof(Entity) << endl; //两个float(4字节),输出8
    cout << sizeof(Player1) << endl; //两个float(4字节)和一个char*(8字节),输出16
    return 0;
}
