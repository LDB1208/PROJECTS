#include <iostream>

using namespace std;

/*
* 本程序演示控制流语句
*/

int main() {
    //continue的例子
    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            //%是取余运算,==判断两个数(或布尔值)是否相等
            cout << i << endl;
            continue; //回到循环开头
        }
        cout << i << " ";
        cout << "Hello World!" << endl;
    }

    cout << "====================" << endl;

    //break的例子
    for (int i = 1; i < 5; i++) {
        if (i % 2 == 0) {
            cout << i << endl;
            break; //跳出循环
        }
        cout << i << " ";
        cout << "Hello World!" << endl;
    }

    cout << "====================" << endl;

    //goto的例子
    goto here;
    cout << "0" << endl;
here:
    cout << "1" << endl;

    cout << "====================" << endl;

    //return的例子
    for (int i = 0; i < 1; i++) {
        if (false) {
            return 0;
        }
        cout << "Hello World!" << endl;
    }

    return 0; //return不一定用在循环中
    cin.get(); //这一行永远不会被执行
}
