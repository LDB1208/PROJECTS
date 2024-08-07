#include <iostream>

using namespace std;

/*
* 本程序演示循环语句
*/

int main() {
    for (int i = 0; i < 5; i++) {
        /*
        * int i = 0 声明变量
        * i < 5 循环条件
        * i++ i自加1
        * 三个条件以;连接
        */
        cout << "Hello World!" << endl; //输出5次"Hello World!"
    }

    cout << "====================" << endl;

    int i = 0; //声明变量
    while (i < 5) {
        //i < 5 循环条件
        cout << "Hello World!" << endl;
        i++;
    }

    cout << "====================" << endl;

    do { //先执行一次,然后根据while的条件判断是否继续循环
        cout << "Hello World!" << endl;
    } while (false);
    //无论如何循环总会被执行一次
    return 0;
}
