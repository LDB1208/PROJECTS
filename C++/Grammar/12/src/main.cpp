#include <iostream>

using namespace std;

/*
 * 本程序演示构造函数
 */

 //构造函数在创建一个对象时都会调用，它通常是设置变量或初始化(每个类都有一个默认构造函数)
 //只使用一个类中的静态方法，它不会运行
class Entity {
public:
    float x, y;

    Entity() { //构造函数
        x = 0.0f, y = 0.0f;
    }

    //函数重载:有相同的函数名但有不同的参数
    Entity(float X, float Y) { //带参数的构造函数
        x = X;
        y = Y;
    }

    void Init() {
        x = 0.0f, y = 0.0f;
    }

    void Print() {
        cout << x << ", " << y << endl;
    }
};

class Log {
public:
    static void Write() {
        cout << "Hello world!" << endl;
    }

    Log() = delete; //删除默认构造函数
};

int main() {
    Entity e1;
    e1.Init(); //初始化方法
    cout << e1.x << ", " << e1.y << endl;
    e1.Print(); //输出的两种方式

    cout << "====================" << endl;

    Entity e2;
    e2.Print(); //现在不需要初始化方法了

    cout << "====================" << endl;

    Entity e3(3.0f, 2.1f); //带参数的构造函数
    e3.Print();

    cout << "====================" << endl;

    //Log l;会报错，因为默认构造函数不存在
    Log::Write();
    return 0;
}
