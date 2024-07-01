#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示成员初始化列表
*/

//这是我们在构造函数中初始化类成员(变量)的一种方式
class Entity {
private:
    string m_name;
    int m_score;
public:
    Entity() : m_name("Unknown"), m_score(0) {} //相当于在构造函数内初始化(要按照定义变量时的顺序)
    //如果把初始化放在构造函数内,则会构建2次对象(一个是默认构造函数,另一个是自己写的构造函数)
    Entity(const string& name) : m_name(name) {}

    const string& GetName() const {
        return m_name;
    }
};

int main() {
    Entity e1;
    cout << e1.GetName() << endl;
    Entity e2("LDB"); //指定参数
    cout << e2.GetName() << endl;
    return 0;
}
