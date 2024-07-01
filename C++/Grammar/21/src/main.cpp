#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示mutable关键字
*/

class Entity {
private:
    string name;
    mutable int DebugCount = 0; //mutable允许函数是常量方法,但可以修改变量
public:
    const string& GetName() const {
        DebugCount++;
        return name;
    }
};

int main() {
    //第一种:在类方法中
    const Entity e;
    e.GetName();

    //第二种:在lambda中
    int x = 8;
    auto f = [&]()mutable { //在lambda里用mutable可以在函数内修改变量,反之不行
        /*中括号内可以填&x,x,=,&
         * &x:通过引用发送变量x
         * x:直接传值变量x(原来的值不变)
         * =:对所有的变量传值(原来的值不变)
         * &:对所有变量引用传值
         */
        x++;
        cout << x << endl;
        };
    f(); //9
    return 0;
}
