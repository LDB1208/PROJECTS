#include <iostream>

using namespace std;

/*
 * 本程序演示宏
 */

#define WAIT cin.get()
#define OPEN_CURLY {
#define DEBUG 1

 //#ifdef DEBUG //如果DEBUG宏被定义
#if DEBUG == 1
#define LOG(x) cout << x << endl //传入参数
#elif defined(RELEASE) //如果RELESE被定义
#define LOG(x)
#else //如果未被定义
#define LOG(x)
#endif //结束语句

#define OnePlusOne 1+1; //定义宏

int main() OPEN_CURLY
    WAIT; //在预处理阶段把WAIT替换成它原来的语句

    cout << "====================" << endl;

    LOG("Hello World!");

    cout << "====================" << endl;

    int result1 = OnePlusOne; //等同于int result1 = 1+1;
    int result2 = 3 * OnePlusOne; //等同于int result2 = 3 * 1+1;(按照运算顺序)
    cout << result1 << endl << result2 << endl;
    #undef OnePlusOne //取消定义宏
    return 0;
}
