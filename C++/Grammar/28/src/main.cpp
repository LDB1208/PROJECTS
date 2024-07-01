#include <cstdio>

/*
* 本程序演示this关键字
*/

//this可以访问成员函数,它是一个指向当前对象实例的指针
class Entity1; //类声明
class Entity2;

void PrintEntity1(Entity1* e); //只有用类声明才能让PrintEntity1和PrintEntity2函数知道有类Entity1
void PrintEntity2(const Entity1& e);

void PrintEntity3(const Entity2& e); //同理

class Entity1 {
public:
    int x, y;

    Entity1(int x, int y) {
        Entity1* e = this; //默认const,不能修改
        e->x = x; //Entity()中的x被赋值为构造函数外的x(不用this就只能用成员初始化列表)

        this->y = y; //或者直接这样写

        PrintEntity1(this);
        PrintEntity2(*this); //逆向引用(const)

    }

    int GetX() const {
        const Entity1* e1 = this; //如果函数后有const,则这一行代码必须有const
        //e->x = 0;
        const Entity1& e2 = *this; //同理
    }
};

class Entity2 {
public:
    Entity2(int x, int y) {
        delete this; //内存释放(不推荐)
    }//执行delete this;后就不能访问这个类的成员数据
};

void PrintEntity1(Entity1* e) {}

void PrintEntity2(const Entity1& e) {}

void PrintEntity3(const Entity2& e) {}

void PrintXY(Entity1 e) {
    printf("x: %d\ny: %d", e.x, e.y);
}

int main() {
    Entity1 e(1, 5);
    PrintXY(e);
    return 0;
}
