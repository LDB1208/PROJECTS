#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

/*
* ��������ʾ�����뿽�����캯��
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
        m_Buffer = new char[m_Size + 1]; //+1����Ϊ�ַ�������һ������ֹ��
        memcpy(m_Buffer, string, m_Size + 1); //��Դsource�п���n���ֽڵ�Ŀ��destin��
    }

    friend ostream& operator<<(ostream& stream, const String& string); //����Ϊ��Ԫ(��ʹ��������Ҳ���Է���private������)
};

ostream& operator<<(ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

int main() {
    Vector2 a = { 2 };
    Vector2 b = a; //����ֵ(ռ��������ͬ���ڴ��ַ)
    b.x = 5;
    printf("a.x:%d\nb.x:%d\n", a.x, b.x);

    cout << "====================" << endl;

    Vector2* e1 = new Vector2();
    Vector2* e2 = e1; //����ָ��
    e2->x = 5; //ͬʱӰ��e1��e2(ָ��ͬһ��ַ)
    //e2++;ֻӰ��e2
    printf("e1.x:%d\ne2.x:%d\n", e1->x, e2->x);

    cout << "====================" << endl;

    String string = "LDB";
    cout << string << endl;
    return 0;
}
