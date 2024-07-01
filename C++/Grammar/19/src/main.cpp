#include <iostream>
#include <string> //string初始化字符串的声明
#include <cstring> //strlen()等函数的声明

using namespace std;
using namespace string_literals;

/*
* 本程序演示字符串
*/

void PrintThings1(string a) { //这个字符串是副本
    a += "1";
    cout << a << endl;
}

void PrintThings2(const string& a) { //这个字符串不是副本,这是一个引用
    cout << a << endl;
}

int main() {

    //第一种(不推荐)
    const char* name1 = "LDB"; //const不是必须的
    char name2[4] = { 'L', 'D', 'B', 0 };
    char name3[4] = { 'L', 'D', 'B', '\0' }; //0和'\0'都是空终止字符，告诉编译器字符串到这里结束
    const char* hello1 = "你好";

    cout << name1 << endl << name2 << endl << name3 << endl << hello1 << endl;

    cout << "====================" << endl;

    //第二种(推荐)
    string name4 = "LDB";
    cout << name4 << endl << name4.size() << endl;//size()获取字符串的大小

    cout << "====================" << endl;

    //追加字符串
    name4 += " Hello!";
    cout << name4 << endl;
    string e = string("AB") + "CD";
    cout << e << endl;

    string name5 = "AB"s + "CD";
    cout << name5 << endl;

    cout << "====================" << endl;

    //改变字符串
    char string[] = "string"; //必须使用数组
    string[0] = 'c';
    cout << string << endl;

    cout << "====================" << endl;

    //寻找文本
    bool contain = e.find("C") != string::npos; //string::npos代表一个不存在的位置,!=是不等于
    cout << contain << endl;

    cout << "====================" << endl;

    //把字符串传递到一个函数
    PrintThings1(e);
    cout << e << endl;
    PrintThings2(e);

    cout << "====================" << endl;

    //字符串字面量(在“”之间的字符),存储在内存的只读部分
    const char ex1[4] = "LDB";
    cout << strlen(ex1) << endl; //字符串的长度:3

    cout << "====================" << endl;

    //其它字符串类型
    const wchar_t* ex2 = L"LDB"; //wstring
    const char16_t* ex3 = u"LDB"; //u16string
    const char32_t* ex4 = U"LDB"; //u32string
    wcout << ex2 << endl; //wchar_t用wcout输出

    const char* ex5 = R"(Line1
Line2
Line3)";
    const char* ex6 = "Line1\n"
        "Line2\n"
        "Line3\n";
    cout << ex5 << endl << ex6 << endl;
    return 0;
}
