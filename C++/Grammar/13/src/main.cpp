#include <iostream>

using namespace std;

/*
* 本程序演示析构函数
*/

//析构函数在销毁一个对象时会调用，它通常是卸载变量，清理内存
class Entity {
public:
    float x, y;

    Entity() { //构造函数
        x = 0.0f, y = 0.0f;
        cout << "Constructed Entity!" << endl;
    }

    ~Entity() { //析构函数
        cout << "Destroyed Entity!" << endl;
    }

    void Print() const {
        cout << x << ", " << y << endl;
    }
};

void Function() {
    Entity e;
    e.Print(); //在此时构造函数被调用
} //因为此对象是在栈上创建的，当超出作用域时，他会被自动销毁,此时析构函数被调用

int main() {
    Function();
    return 0;
}
