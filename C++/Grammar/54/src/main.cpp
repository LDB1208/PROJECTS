#include "../include/pch.h"

/*
* 本程序演示预编译头文件(precompiled headers)
*/

//目的:避免多次读取头文件编译而浪费时间
//注意:不要把频繁更改的头文件预编译

int main() {
    std::cout << "Hello World!\n";
    return 0;
}
