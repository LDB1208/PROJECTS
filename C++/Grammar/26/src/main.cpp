#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示隐式构造函数以及explicit关键字
*/

class Entity {
private:
    string m_name;
    int m_age;
public:
    Entity(const string& name) : m_name(name), m_age(-1) {
        cout << "Name constructor called!" << endl;
    }

    Entity(int age) : m_name("Unknown"), m_age(age) {
        cout << "Age constructor called!" << endl;
    }

    explicit Entity(double speed) {
        cout << "Speed constructor called!" << endl;
    }
};

void PrintEntity(const Entity& entity) {}

int main() {
    Entity a = 13; //指定参数的另一种形式
    Entity b = string("LDB");
    PrintEntity(22); //隐式构造函数
    PrintEntity(string("LDB"));
    PrintEntity(Entity("LDB")); //调用构造函数

    //explicit关键字:一个构造函数使用explicit关键字时,没有隐式转换
    Entity c(1.0);
    Entity d = Entity(2.0);
    //Entity e = 1.0;会报错
    return 0;
}
