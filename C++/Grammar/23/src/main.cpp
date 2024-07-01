#include <iostream>
#include <string>

using namespace std;

/*
* 本程序演示三元操作符
*/

static int level = 1;
static int speed = 2;

int main() {
    speed = level > 5 ? 10 : 5; //三元操作符:条件 ? 条件为真的情况 : 条件为假的情况
    /*
     * 上面这行代码相当于
     * if (s_level > 5)
     *     s_speed = 10;
     * else
     *     s_speed = 5;
     */
    cout << speed << endl;

    cout << "====================" << endl;

    string rank = level > 10 ? "Master" : "Beginner"; //使用三元操作符能让代码更简洁
    cout << rank << endl;

    cout << "====================" << endl;

    //三元操作符的嵌套
    speed = level > 5 ? level > 10 ? 15 : 10 : 5;
    /*
     * 1.判断level>10
     * 2.如果level>10,值为15,否则值为10
     * 3.判断level>5
     * 4.如果level>5,值为15或10(取决于上一次的判断),否则值为5
     */

    level = 15;
    speed = level > 5 ? level > 10 ? 15 : 10 : 5; //15
    cout << speed << " ";

    level = 8;
    speed = level > 5 ? level > 10 ? 15 : 10 : 5; //10
    cout << speed << " ";

    level = 4;
    speed = level > 5 ? level > 10 ? 15 : 10 : 5; //5
    cout << speed;
    return 0;
}
