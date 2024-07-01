#include <iostream>

using namespace std;

/*
* 本程序演示枚举
*/

enum Ex1 {
    A, B, C //默认第一个是0,然后一个接着一个递增
};
enum Ex2 {
    a = 1, b = 3, c = 5 //可以给这些变量赋值
};
enum Ex3 {
    D = 5, E, F //D是5,一个接着一个递增(E是6,F是7)
};
enum Ex4 : unsigned char { //指定你想要给枚举赋值的类型
    d, e, f
};

int main() {
    Ex1 val1 = B;
    //Ex1 val1 = 1会报错,必须是Ex1中的其中一个
    if (val1 == 1) {
        cout << "val1 = 1" << endl;
    }
    Ex2 val2 = c;
    if (val2 == 5) {
        cout << "val2 = 5" << endl;
    }
    Ex3 val3 = F;
    if (val3 == 7) {
        cout << "val3 = 7" << endl;
    }
    return 0;
}
