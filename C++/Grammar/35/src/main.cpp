#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

/*
* 本程序演示链接外部静态库
*/

int main() {
    int a = glfwInit();
    cout << a << endl; //1
    return 0;
}