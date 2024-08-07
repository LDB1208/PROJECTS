#include <iostream>

using namespace std;

/*
* 本程序演示引用
*/

void Increment(int value) {
    value++;
}

void increment_one(int& value) { //引用
    value++;
}

int main() {
    int a = 5;
    int& ref = a; //这里&属于类型的一部分，是引用
    //引用必须初始化
    //实际上ref不存在，只是a的“别名”，不占用内存
    ref = 2;
    //相当于a = 2;
    cout << a << endl;

    cout << "====================" << endl;

    int b = 5;
    Increment(b);
    cout << b << endl; //没有引用，无法返回6，还是5

    increment_one(b);
    cout << b << endl; //返回6

    cout << "====================" << endl;

    int A = 5;
    int B = 8;

    int& Ref = A; //引用时必须给一个值
    Ref = B; //你不能这样改变引用所引用的变量,这意味着你把B的值赋给了A

    //A = 8, B = 8
    cout << "A = " << A << endl << "B = " << B << endl;

    int* REF = &A; //这样改变引用所引用的变量
    *REF = 8;
    REF = &B;
    *REF = 5;

    //A = 8, B = 5
    cout << "A = " << A << endl << "B = " << B << endl;
    return 0;
}
