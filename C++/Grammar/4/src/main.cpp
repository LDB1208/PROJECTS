#include <iostream>

using namespace std;

/*
* 本程序演示条件判断语句
*/

int main() {

    //if语句
    int a = 5; //声明变量
    if (a == 6) {
        //如果a=6,执行此行代码
        cout << "a = 6" << endl; //终端输出
    }
    else if (a < 4) {
        //如果a不等于6,且a<4,执行此行代码
        cout << "a < 4" << endl;
    }
    else //如果只有一行,可以不加大括号
        //如果a不等于6,且a>=4,执行此行代码
        cout << a << endl;

    cout << "====================" << endl;
    //Tips:做逻辑运算搞不清楚顺序的时候就加括号改变顺序
    bool ex1 = !((!(1 < 0) || (4 > (6 < 9))) < (4 == 1 && 3 != 0));
    /*
     * 1.判断1<0(false)
     * 2.判断6<9(true)
     * 3.判断4>true(1)(true)
     * 4.判断!(false)(true)
     * 5.判断true||true(true)
     * 6.判断4==1(false)
     * 7.判断3!=0(true)
     * 8.判断false&&true(false)
     * 9.判断true(1)<false(0)(false)
     * 10.对false做逻辑非运算(true(1))
     */
    cout << "ex1:" << ex1 << endl; //1(true)

    cout << "====================" << endl;

    //switch语句
    int b = 0;
    switch (b) {
    case 0: //等同于if (b == 0)
        cout << "b是0!" << endl; //发生贯穿
        //如果没有break，一个case的代码执行完毕后会继续执行紧接在case后的代码
    case 2:
    case 4:
    case 6:
    case 8:
        cout << "b是偶数!" << endl;
        break; //跳出switch语句
    case 1: //贯穿的合理应用
    case 3:
    case 5:
    case 7:
    case 9:
        cout << "b是奇数!" << endl;
        break;
    default: //当所有case都不满足时运行
        cout << "b不再0-9范围内!" << endl;
        break;
    }
    return 0;
}
