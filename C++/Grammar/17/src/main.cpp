#include <iostream>

using namespace std;

/*
* 本程序演示可见性
*/

class Entity { //类(class)的默认可见性为private
public:
    int x1, y1;

    void Print1() {
        cout << "Function Print1 has been called!" << endl;
    }

    Entity() {
        x1 = 0, y1 = 0;
        x2 = 0, y2 = 0;
        x3 = 0, y3 = 0; //可以访问这个类的私有变量
        Print1();
        Print2();
        Print3(); //可以访问这个类的私有方法
    }

protected: //这个Entity类和它的所有子类都能访问
    int x2, y2;

    void Print2() {}

private: //只有这个Entity类可以访问这些变量(friend友元除外)
    int x3, y3;

    void Print3() {}
};

struct Player : public Entity { //结构体(struct)的默认可见性为public
    Player() {
        x1 = 0, y1 = 0;
        Print1();
        x2 = 0, y2 = 0;
        Print2();
        //x3 = 0, y3 = 0;会报错,因为变量x1和y1是私有的
        //Print3();会报错,因为Print()方法是私有的
    }
};

int main() {
    Entity e;
    e.x1 = 2;
    e.y1 = 3;
    e.Print1();
    //e.x2 = 0, e.y2 = 0; e.Print2();会报错,因为这些变量和方法在类之外，而且main()不是Entity的子类
    //e.x3 = 0, e.y3 = 0; e.Print3();会报错,因为变量x1,y1和Print1()方法是私有的
    return 0;
}