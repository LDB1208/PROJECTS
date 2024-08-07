#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示虚函数
*/

class Entity {
public:
    virtual string GetName() { //父类定义虚函数,如果此函数被重写,它会指向Player类的函数
        return "Entity";
    }
};

class Player : public Entity {
private:
    string MyName;
public:
    Player(const string& name) : MyName(name) {}
    //带参数的构造函数，MyName(name)是初始化列表(MyName = name;),MyName是成员变量，name是参数

    string GetName() override { //子类覆写父类的虚函数，在此处使用override不是必须的,但能让代码更具有可读性
        return MyName;
    }
};

void PrintName(Entity* entity) {
    cout << entity->GetName() << endl; //->是箭头操作符，类似于e.GetName()，只不过它接受一个指针
}

int main() {
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("LDB");
    PrintName(p);
    return 0;
}
