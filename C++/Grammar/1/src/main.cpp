//引入头文件
#include <iostream> //C++
#include <cstdio> //C

using namespace std; //使用std命名空间(C++)

/*
 * 本程序演示输入和输出
 */

int main() {
    //C++输出(iostream)
    std::cout << "Hello World!" << std::endl; //输出Hello World
    cout << "Hello World!" << endl; //使用std命名空间后可以省略std::

    cout << "====================" << endl;

    //C输出(cstdio)
    printf("%d\n", 100);                    //%d代表整数,\n表示换行
    printf("%5d\n", 1000);                  //默认右对齐,左边补空格
    printf("%-5d\n", 1000);                 //左对齐,右边补空格
    printf("%+d %+d\n", 1000, -1000);       //输出正负号
    printf("% d % d\n", 1000, -1000);       //正号用空格替代，负号输出
    printf("%x %#x\n", 1000, 1000);         //输出0x(十六进制)
    printf("%e\n", 3.01);                   //科学计数法(浮点数)
    printf("%.0f %#.0f\n", 1000.0, 1000.0); //当小数点后不输出值时依然输出小数点
    printf("%g %#g\n", 1000.0, 1000.0);     //保留小数点后后的0, %g代表(双精度)浮点数(float,或double)
    printf("%05d\n", 1000);                 //前面补0

    cout << "====================" << endl;

    printf("%.8d\n", 1000);          //不足指定宽度补前导0，效果等同于%06d
    printf("%.8f\n", 1000.123456789);//超过精度,截断
    printf("%.8f\n", 1000.123456);   //不足精度,补后置0
    printf("%.8g\n", 1000.123456);   //最大有效数字为8位
    printf("%.8s\n", "abcdefghij");  //超过指定长度截断, %s代表char*(字符串)

    cout << "====================" << endl;


    //输入
    int a = 0;
    cout << "a:";
    cin >> a; //将输入赋值给a
    cout << "a: " << a << endl;

    int b = 0;
    cout << "请输入a和b:";
    cin >> a >> b; //a和b之间需要有空格或换行
    printf("a: %d\nb: %d\n", a, b);
    return 0; //返回值(main函数的返回值可以省略, 默认返回0)
}
