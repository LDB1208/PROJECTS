#include <iostream>
#include <string> //string��ʼ���ַ���������
#include <cstring> //strlen()�Ⱥ���������

using namespace std;
using namespace string_literals;

/*
* ��������ʾ�ַ���
*/

void PrintThings1(string a) { //����ַ����Ǹ���
    a += "1";
    cout << a << endl;
}

void PrintThings2(const string& a) { //����ַ������Ǹ���,����һ������
    cout << a << endl;
}

int main() {

    //��һ��(���Ƽ�)
    const char* name1 = "LDB"; //const���Ǳ����
    char name2[4] = { 'L', 'D', 'B', 0 };
    char name3[4] = { 'L', 'D', 'B', '\0' }; //0��'\0'���ǿ���ֹ�ַ������߱������ַ������������
    const char* hello1 = "���";

    cout << name1 << endl << name2 << endl << name3 << endl << hello1 << endl;

    cout << "====================" << endl;

    //�ڶ���(�Ƽ�)
    string name4 = "LDB";
    cout << name4 << endl << name4.size() << endl;//size()��ȡ�ַ����Ĵ�С

    cout << "====================" << endl;

    //׷���ַ���
    name4 += " Hello!";
    cout << name4 << endl;
    string e = string("AB") + "CD";
    cout << e << endl;

    string name5 = "AB"s + "CD";
    cout << name5 << endl;

    cout << "====================" << endl;

    //�ı��ַ���
    char string[] = "string"; //����ʹ������
    string[0] = 'c';
    cout << string << endl;

    cout << "====================" << endl;

    //Ѱ���ı�
    bool contain = e.find("C") != string::npos; //string::npos����һ�������ڵ�λ��,!=�ǲ�����
    cout << contain << endl;

    cout << "====================" << endl;

    //���ַ������ݵ�һ������
    PrintThings1(e);
    cout << e << endl;
    PrintThings2(e);

    cout << "====================" << endl;

    //�ַ���������(�ڡ���֮����ַ�),�洢���ڴ��ֻ������
    const char ex1[4] = "LDB";
    cout << strlen(ex1) << endl; //�ַ����ĳ���:3

    cout << "====================" << endl;

    //�����ַ�������
    const wchar_t* ex2 = L"LDB"; //wstring
    const char16_t* ex3 = u"LDB"; //u16string
    const char32_t* ex4 = U"LDB"; //u32string
    wcout << ex2 << endl; //wchar_t��wcout���

    const char* ex5 = R"(Line1
Line2
Line3)";
    const char* ex6 = "Line1\n"
        "Line2\n"
        "Line3\n";
    cout << ex5 << endl << ex6 << endl;
    return 0;
}
