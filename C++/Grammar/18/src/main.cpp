#include <iostream>
#include <array>

using namespace std;

/*
* 本程序演示数组
*/

class Entity {
public:
    int* ex3 = new int[5];

    Entity() {
        for (int i = 0; i < 5; i++) {
            ex3[i] = 2;
        }
    }
};

int main() {
    int ex1[5] = { 0, 0, 0, 0, 0 }; //一个有5个整数的数组(在栈上创建的，跳出作用域范围就会被销毁)
    ex1[0] = 1; //设置数组的指定位置的值，[]里填的是下标，从0开始
    ex1[4] = 5;
    int a = ex1[0]; //把数组ex1的第一个元素赋值给a
    //ex1[-1] = 3;
    //ex1[5] = 4;
    //内存访问违规，这超出了数组的边界

    cout << ex1[0] << endl; //输出数组的第一个元素
    cout << ex1 << endl; //输出数组的地址

    cout << "====================" << endl;

    for (int i = 0; i < 5; i++) { //使用for循环进行遍历
        ex1[i] = 2;
        cout << ex1[i];
    }

    cout << endl << "====================" << endl;

    int* ptr = ex1; //实际上是指针类型
    *(ptr + 2) = 6; //相当于ex1[2] = 6;
    //偏移量=2*4=8字节，也就是第9~12字节就是ex1的第三个元素的位置
    cout << ex1[2] << endl; //6

    *reinterpret_cast<int*>((reinterpret_cast<char*>(ptr) + 12)) = 7;//相当于ex1[3] = 7;
    //先把ptr转换成char*类型，再加上12*1=12字节的偏移量，到达第四个元素所在的位置，接着把整个指针转换为int*类型，最后逆向引用
    cout << ex1[3] << endl; //7

    cout << "====================" << endl;

    //使用new
    int* ex2 = new int[5]; //一个有5个整数的数组(堆上创建的,只能由我们手动销毁,否则它会永久存在)
    for (int i = 0; i < 5; i++) {
        ex2[i] = 2;
        cout << ex2[i];
    }
    delete[] ex2;

    cout << endl << "====================" << endl;

    Entity e;
    cout << e.ex3 << endl; //内存间接寻址，第三字节是数组ex3的地址

    cout << "====================" << endl;

    int b[5];
    //如果要使用这两种方法,必须是在栈上分配的数组
    //但是尽量不要用
    int size = sizeof(b); //数组b的字节数
    int count = sizeof(b) / sizeof(int); //数组b的元素数量
    cout << size << endl << count << endl;

    cout << "====================" << endl;

    array<int, 5> another; //或者使用C++11的array：array<类型, 元素数量> 数组名;
    for (int i = 0; i < another.size(); i++) { //array可以使用数组.size()来获取数组的大小
        another[i] = 2;
        cout << another[i];
    }
    return 0;
}
