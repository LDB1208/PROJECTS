#include <iostream>

using namespace std;

/*
* 本程序演示箭头操作符
*/

class Entity {
public:
    int x = 0;

    void Print1() { cout << "Hello!" << endl; }

    void Print2() const { cout << "Hello!" << endl; }
};

class ScopedPtr {
private:
    Entity* m_obj;
public:
    ScopedPtr(Entity* entity) : m_obj(entity) {}

    ~ScopedPtr() { delete m_obj; }

    Entity* operator->() { return m_obj; }

    const Entity* operator->() const { return m_obj; }

};

struct Vector3 {
    float x, y, z;
};

int main() {
    Entity e;
    e.Print1();

    //第一种(不推荐)
    Entity* ptr1 = &e;
    (*ptr1).Print1(); //逆向引用

    //第二种
    Entity* ptr2 = &e;
    //ptr.Print(); 会报错
    ptr2->Print1(); //箭头操作符
    ptr2->x = 2;
    cout << ptr2->x << endl;

    cout << "====================" << endl;

    //运算符重载
    ScopedPtr entity1 = new Entity();
    entity1->Print1();

    const ScopedPtr entity2 = new Entity();
    entity2->Print2();

    cout << "====================" << endl;

    //获取内存中某个成员变量的偏移量
    int offset1 = (int)(size_t) & ((Vector3*) nullptr)->x;
    //1.把nullptr转换成Vector3*
    //2.得到内存布局
    //3.&取x的内存地址
    //4.转换为int
    int offset2 = (int)(size_t) & ((Vector3*) nullptr)->y;
    int offset3 = (int)(size_t) & ((Vector3*) nullptr)->z;
    cout << offset1 << endl << offset2 << endl << offset3 << endl;
    return 0;
}
