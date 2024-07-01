#include <iostream>

using namespace std;

/*
* 本程序演示类和结构体
*/

class Player1 {
public: //设置可见性为公有，默认情况下都是私有的
    int x = 0, y = 0;
    int speed = 1;

    void Move(int xa, int ya) { //类中的函数称为方法
        x += xa * speed;
        y += ya * speed;
    }

    void Upgrade(int a) {
        speed += a;
        if (speed <= 0) {
            speed = 1;
        }
    }

private:
    int z = 0; //可见性为私有，无法在类外使用
}; //类的结尾有分号

struct PLayer2 { //结构体唯一和类不同的点是:struct的默认可见性为公有
    int x = 0, y = 0;
    int speed = 1;

    void Move(int xa, int ya) { //类中的函数称为方法
        x += xa * speed;
        y += ya * speed;
    }

    void Upgrade(int a) {
        speed += a;
        if (speed <= 0) {
            speed = 1;
        }
    }

private:
    int z = 0;
};

int main() {
    int x1 = 0, y1 = 0, speed1 = 2; //不用类的情况：杂乱无章，可读性差，维护困难
    int x2 = 3, y2 = 4, speed2 = 5;

    //使用类的情况：有序，可读性强，容易维护
    Player1 e1; //由类类型构成的变量称为对象，新的对象变量称为实例
    PLayer2 e2;
    e1.x = 0, e1.y = 0, e1.speed = 2;
    e2.x = 3, e2.y = 4, e2.speed = 5;
    cout << "e1.x:" << e1.x << endl << "e1.y:" << e1.y << endl <<
        "e1.speed:" << e1.speed << endl;
    cout << "e2.x:" << e2.x << endl << "e2.y:" << e2.y << endl <<
        "e2.speed:" << e2.speed << endl;

    cout << "====================" << endl;

    //使用方法
    cout << "After moving:" << endl;

    e1.Upgrade(3);
    e1.Move(3, -1);
    cout << "e1.x:" << e1.x << endl << "e1.y:" << e1.y << endl <<
        "e1.speed:" << e1.speed << endl;

    e2.Upgrade(-3);
    e2.Move(5, 4);
    cout << "e2.x:" << e2.x << endl << "e2.y:" << e2.y << endl <<
        "e2.speed:" << e2.speed << endl;
    return 0;
}
