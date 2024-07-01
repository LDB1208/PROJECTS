#include <iostream>
#include <string>

using namespace std;

/*
 * 本程序演示纯虚函数
 */

 //纯虚函数允许我们在基类中定义一个没有实现的函数，然后强制子类去实现该函数
class Printable {
public:
    virtual string GetClassName() = 0;
};

class Entity1 : public Printable {
public:
    virtual string GetName() = 0; //纯虚函数，它必须在一个子类中实现

    string GetClassName() override {
        return "Entity1";
    }
};

class Entity2 : public Printable {
public:
    virtual string GetName() {
        return "Entity2";
    }

    string GetClassName() override {
        return "Entity2";
    }
};

class Player : public Entity1 {
private:
    string MyName;
public:
    Player(const string& name) : MyName(name) {}

    string GetName() override { //只有子类在实现了所有纯虚函数后，才能进行实例化
        return MyName;
    }

    string GetClassName() override {
        return "Player";
    }
};

void Print(Printable* obj) {
    cout << obj->GetClassName() << endl; //打印类名
}

int main() {
    Entity1* e1 = new Player("LDB"); //我们不能实例化有纯虚函数的类
    Entity2* e2 = new Entity2();
    Player* p = new Player("LDB");

    Print(e1);
    Print(e2);
    Print(p);
    return 0;
}
