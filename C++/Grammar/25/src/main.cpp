#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示new关键字
*/

class Entity {
public:
    Entity() {
        cout << "Constructor has been called!" << endl;
    }

    ~Entity() {
        cout << "Destructor has been called!" << endl;
    }
};

int main() {
    //new在堆上分配内存
    //new返回指向你分配的内存的指针
    int* a = new int;
    int* arr = new int[5]; //数组
    double* b = new double;

    //类
    Entity* e1 = new Entity(); //调用构造函数
    Entity* e2 = new Entity; //调用构造函数
    Entity* e3 = (Entity*)malloc(sizeof(Entity)); //仅仅分配内存(尽量不要用)
    Entity* e4 = new(b) Entity; //只调用构造函数,并在一个特定的内存地址中初始化Entity

    //不要忘记,new过后不会释放内存,这些被我们分配的所有东西都要手动delete
    //同样的,delete会调用析构函数
    delete a;
    delete[] arr; //如果new时有[],则delete时也要有[]
    delete e1;
    delete e2;
    free(e3); //仅仅释放内存
    return 0;
}
