#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

/*
* 本程序演示复制与拷贝构造函数
*/

struct Vector2 {
    int x;
};

class String {
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1]; //+1是因为字符串后还有一个空终止符
        memcpy(m_Buffer, string, m_Size + 1); //从源source中拷贝n个字节到目标destin中
    }

    friend ostream& operator<<(ostream& stream, const String& string); //声明为友元(即使不是子类也可以访问private的内容)
};

ostream& operator<<(ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

int main() {
    Vector2 a = { 2 };
    Vector2 b = a; //复制值(占用两个不同的内存地址)
    b.x = 5;
    printf("a.x:%d\nb.x:%d\n", a.x, b.x);

    cout << "====================" << endl;

    Vector2* e1 = new Vector2();
    Vector2* e2 = e1; //复制指针
    e2->x = 5; //同时影响e1和e2(指向同一地址)
    //e2++;只影响e2
    printf("e1.x:%d\ne2.x:%d\n", e1->x, e2->x);

    cout << "====================" << endl;

    String string = "LDB";
    cout << string << endl;
    return 0;
}
