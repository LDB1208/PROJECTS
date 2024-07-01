#include <iostream>
#include <memory> //引用智能指针头文件

using namespace std;

/*
* 本程序演示智能指针(std::unique_ptr, std::shared_ptr, std::weak_ptr)
*/

class Entity {
public:
    Entity() { cout << "Created Entity!" << endl; }

    ~Entity() { cout << "Destroyed Entity!" << endl; }

    void Print() { cout << "Print function called!" << endl; }
};

//智能指针可以自动释放内存(大部分情况甚至可以自动申请内存)
int main() {
    //第一种:unique_ptr, 当超出作用域时释放内存
    {
        unique_ptr<Entity> entity1(new Entity()); //Created Entity!
        //unique_ptr<Entity> entity = new Entity();会报错
        entity1->Print();

        //更好的做法(exception异常安全)
        unique_ptr<Entity> entity2 = make_unique<Entity>(); //Created Entity!

        entity2->Print();
        //unique_ptr<Entity> e0 = entity1;你不能复制一个unique_ptr
    } //Destroyed Entity!

    cout << "====================" << endl;

    //第二种:shared_ptr, 引用计数(跟踪这个指针有多少引用), 引用计数达到0时释放内存
    {
        shared_ptr<Entity> e0;
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>(); //Created Entity!
            weak_ptr<Entity> weakEntity = sharedEntity; //不增加引用计数
            e0 = sharedEntity;
        } //sharedEntity被释放
        e0->Print();
    } //Destroyed Entity!

    cout << "====================" << endl;

    //第三种:weak_ptr, 可以和shared_ptr一起使用
    {
        weak_ptr<Entity> e0;
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>(); //Created Entity!
            e0 = sharedEntity;
        } //Destroyed Entity!
        //e0->Print();
    }
    return 0;
}
