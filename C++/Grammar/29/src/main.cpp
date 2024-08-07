#include <iostream>

using namespace std;

/*
* 本程序演示对象生存期(栈作用域生存期)
*/

class Entity {
public:
    Entity() { cout << "Created Entity!" << endl; }

    ~Entity() { cout << "Destroyed Entity!" << endl; }
};

class ScopedPtr {
private:
    Entity* m_ptr;
public:
    ScopedPtr(Entity* ptr) : m_ptr(ptr) {}

    ~ScopedPtr() { delete m_ptr; }
};

int* CreateArray1() {
    int array1[50]; //array离开函数作用域后就会被销毁
    for (int i = 0; i < 50; ++i)
        array1[i] = 0;
    cout << array1 << endl;
    return array1;
}

int* CreateArray2() {
    int* array2 = new int[50];
    for (int i = 0; i < 50; ++i)
        array2[i] = 0;
    cout << array2 << endl;
    return array2;
}

void CreateArray3(int* array3) {
    for (int i = 0; i < 50; ++i)
        array3[i] = 0;
    cout << array3 << endl;
}

int main() {
    {
        Entity e1; //Created Entity!
    }
    //Destroyed Entity!(e是栈上的对象,超出作用域内存就会被释放)
    cout << "====================" << endl;
    {
        Entity* e2 = new Entity(); //Created Entity!
    }
    //因为这是堆上的对象,所以不会自动释放内存

    cout << "====================" << endl;

    int array[50];
    CreateArray1();
    CreateArray2();
    CreateArray3(array);

    cout << "====================" << endl;

    {
        ScopedPtr e3(new Entity()); //栈变量的用途:自动构造,自动析构
    } //e3被销毁

    return 0;
} //程序终止时,操作系统会释放e2内存
