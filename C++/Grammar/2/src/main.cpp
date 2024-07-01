#include <iostream>

using namespace std;

/*
* 本程序演示变量与常量,数据类型的大小和数据溢出
*/

int main() {
    //变量与常量
    //合法变量（或常量）名
    int _num = 3;
    int num = 4;
    int Num = 5;
    int n_m = 6;
    int n7m = 7;

    const int constant = 0; //这是常量，无法修改

    //注意赋值时的字母后缀
    int ex1 = 1;
    unsigned int ex2 = 3u;
    long int ex3 = 9l;
    long long int ex4 = 99ll;
    float ex5 = 3.1f;
    double ex6 = 3.14159;
    long double ex7 = 3.14159L;
    cout << ex1 << " " << ex2 << " " << ex3 << " " << ex4 << " " << ex5 << " " << ex6 << " " << ex7 << endl;
    //C++11
    int e1{ 10 };
    int e2 = { 9 };
    int e3 = (8);
    cout << e1 << " " << e2 << " " << e3 << endl;

    cout << "====================" << endl;

    int bin = 0b1011; //二进制:以0b或0B开头
    int oct = 013; //八进制:以0开头
    int dec = 11; //十进制
    int hex = 0xB; //十六进制:以0x或0X开头
    cout << bin << " " << oct << " " << dec << " " << hex << endl;

    typedef int score; //typedef定义变量类型的别名
    score me = 10; //这是整型变量
    float other = static_cast<float>(me); //用static_cast转换变量类型

    cout << "====================" << endl;

    //隐式类型转换
    char a = 'a'; //a的ASCII值为97
    int b = 1;
    cout << a + b << endl; //a隐式转换为97

    unsigned int u1 = 10;
    int u2 = -42;
    cout << u1 + u2 << endl; //结果隐式转换为unsigned int

    cout << "====================" << endl;

    //交换
    int c = 9, d = 10;
    cout << "c:" << c << endl << "d:" << d << endl;
    swap(c, d);
    cout << "After swaping:" << endl;
    cout << "c:" << c << endl << "d:" << d << endl;

    cout << "====================" << endl;

    //数据类型的大小
    //sizeof()返回数据类型的字节数
    cout << "Size of char: " << sizeof(char) << endl
        << "Size of int: " << sizeof(int) << endl
        << "Size of short int: " << sizeof(short int) << endl
        << "Size of long int: " << sizeof(long int) << endl
        << "Size of long long int: " << sizeof(long long int) << endl
        << "Size of float: " << sizeof(float) << endl
        << "Size of double: " << sizeof(double) << endl
        << "Size of long double: " << sizeof(long double) << endl
        << "Size of wchar_t: " << sizeof(wchar_t) << endl
        << "Size of char16_t: " << sizeof(char16_t) << endl
        << "Size of char32_t: " << sizeof(char32_t) << endl;

    cout << "====================" << endl;

    //数据溢出
    int intmin = -2147483648; //下限
    int intmax = 2147483647; //上限
    //溢出
    int intMin = -2147483649; //下溢
    int intMax = 2147483648; //上溢
    cout << "int下溢值:" << intMin << endl << "int上溢值:" << intMax << endl;
    return 0;
}
