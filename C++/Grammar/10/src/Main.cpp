#include <iostream>

using namespace std;

/*
* 本程序演示静态
*/

extern int var1; //到外部翻译单元寻找var1
int var2 = 1;

void Function() { //不会链接到Static.cpp中的Function()函数
    cout << var1 << endl;
}

struct Entity1 {
    int x, y;

    void Print() {
        cout << x << ", " << y << endl;
    }
};

struct Entity2 {
    static int x, y;

    void Print() {
        cout << x << ", " << y << endl;
    }
};

struct Entity3 {
    static int x, y;

    static void Print() {
        cout << x << ", " << y << endl;
    }
};

struct Entity4 {
    int x, y;
    /*这样不合法:静态不能访问非静态,静态方法没有类实例
     *static void Print(){
     *    cout << x << ", " << y << endl;
     *}
     */
};

//合法
static void Print(Entity4 e6) {
    cout << e6.x << ", " << endl;
}

int Entity2::x; //我们需要在某些地方定义静态变量
int Entity2::y; //作用域::变量名
int Entity3::x;
int Entity3::y;

void static FunctionEx1() {
    int i = 0; //调用此函数时,i被初始化为0
    i++;
    cout << i << " ";
}

void static FunctionEx2() {
    static int i = 0; //相当于在此函数外部定义了变量i
    i++;
    cout << i << " ";
}

int main() {
    //在类或结构体外的静态
    //输出0 1
    cout << var1 << " " << var2 << endl;

    cout << "====================" << endl;

    //在类或结构体里的静态
    Entity1 e1;
    e1.x = 2;
    e1.y = 3;
    Entity1 e2 = { 5, 8 }; //另一种初始化的方法

    /*
     * 输出:
     * 2, 3
     * 5, 8
     */
    e1.Print();
    e2.Print();

    cout << "====================" << endl;

    Entity2 e3, e4;
    e3.x = 2;
    e3.y = 3;
    //Entity2 e4 = {5, 8}; 这样会失败,因为x和y不再是类成员
    e4.x = 5;
    e4.y = 8;

    /*
     * 输出:
     * 5, 8
     * 5, 8
     */
    e3.Print(); //因为e3和e4的x和y都指向同一个内存
    e4.Print(); //所以修改了e4的x和y就相当于修改了e3的x和y

    cout << "====================" << endl;

    //上面的引用是无意义的,正确的写法是这样:
    Entity2::x = 6;
    Entity2::y = 9;
    e3.Print();
    e4.Print();

    cout << "====================" << endl;

    Entity3 e5;
    Entity3::x = 0;
    Entity3::y = 1;
    Entity3::Print(); //因为Print()方法是静态的,可以这样访问

    cout << "====================" << endl;

    //局部静态
    for (int i = 0; i <= 4; ++i) {
        FunctionEx1(); //输出1 1 1 1 1
    }
    cout << endl;
    for (int i = 0; i <= 4; ++i) {
        FunctionEx2(); //输出1 2 3 4 5
    }
    return 0;
}
