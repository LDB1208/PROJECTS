#include <iostream>

using namespace std;

/*
* 本程序演示const关键字
*/

class Entity {
private:
    int x1 = 0, y1 = 0;
    int* x2;
    mutable int var; //mutable允许函数是常量方法,但可以修改变量
public:
    //如果一个方法没有(或不想)修改类,标记它为const
    int get_x() const { //不能修改类成员变量,只在类中有效
        //x1 = 2, y1 = 2会报错
        var = 2; //使用mutable关键字
        return x1;
    }

    int get_x() {
        return x1;
    }

    const int* const GetX() const { //此方法返回一个不能被修改的指针
        return x2;
    }
};

//这里常量引用不能修改Entity
void PrintEntity(const Entity& e) { //PrintEntity()将使用有const的get_x()版本
    cout << e.get_x() << endl;
}

int main() {
    //第一种用法:常量
    const int a = 5;

    //第二种用法:指针(看const在*前还是后)
    const int* ptr1 = new int; //等同于int const* ptr1 = new int;
    //不能修改指针指向的数据(逆向引用)
    ptr1 = (int*)&a;
    cout << *ptr1 << endl;

    int* const ptr2 = new int;
    //不能让指针指向其它东西
    *ptr2 = 0;
    cout << *ptr2 << endl;

    const int* const ptr3 = new int;
    //不能修改指针指向的数据(逆向引用),也不能让指针指向其它东西

    //第三种用法:类与方法中的const
    Entity e;
    PrintEntity(e);
    return 0;
}
