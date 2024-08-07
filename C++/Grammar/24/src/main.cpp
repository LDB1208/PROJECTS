#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示如何创建对象
*/

class Entity {
private:
    string m_name;
public:
    Entity() : m_name("Unknown") {}

    Entity(const string& name) : m_name(name) {}

    const string& GetName() const {
        return m_name;
    }
};

int main() {
    //第一种:在栈上创建:一旦超出作用域,自动释放内存
    { //定义作用域
        Entity ex1 = Entity("LDB"); //指定参数的另一种形式
        cout << ex1.GetName() << endl;
    }
    //cout << ex1.GetName() << endl;
    cout << "====================" << endl;

    //第二种:在堆上创建:需要手动释放内存
    Entity* e;
    {
        Entity* ex2 = new Entity("LDB");
        e = ex2;
        cout << ex2->GetName() << endl;
    }
    cout << e->GetName() << endl;
    delete e; //需要手动delete
    return 0;
}
