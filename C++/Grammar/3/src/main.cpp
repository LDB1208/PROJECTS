#include <iostream> //预处理语句以#开头
#include "../include/header.h" //引入头文件(..代表上一目录)
//C++标准库的头文件用<>,自己写的头文件用""

using namespace std; //使用std命名空间

/*
* 本程序演示函数,宏和头文件
*/
int Add(int a, int b); //函数声明

int main() {
    cout << Multiply(5, 8) << endl;
    cout << Add(5, 8) << endl;
    return 0;
#include "../include/close_brace.h" //复制EndBrace.h里的内容
