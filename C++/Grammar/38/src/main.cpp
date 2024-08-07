#include <iostream>
#include <string>
#include <vector>
#include <tuple> //tuple

using std::cout, std::endl, std::string; //C++17

/*
 * 本程序演示函数多返回值
 */

string str1 = "Hello";
string str2 = "World";
string str3 = "Hello";
string str4 = "World";

void return_strings1(string& r1, string& r2) {
    r1 = "LDB";
    r2 = "LAQ";
}

void return_strings2(string* p1, string* p2) {
    if (p1) //判断是否为nullptr
        *p1 = "LDB";
    if (p2)
        *p2 = "LAQ";
}

std::tuple<string, string> return_strings4(string s1, string s2) {
    //std::tuple<返回类型>
    return std::make_pair(s1, s2); //make_pair返回
}

std::pair<string, string> return_strings5(string s1, string s2) {
    return std::make_pair(s1, s2);
}

struct rstr {
    string ststring1 = str1;
    string ststring2 = str2;
};

rstr return_string6() {
    return { str3, str4 };
}

int main() {
    //第一种:传引用
    return_strings1(str1, str2); //r1, r2分别是str1, str2的引用
    cout << str1 << " " << str2 << endl;

    cout << "====================\n";

    //第二种:传指针
    return_strings2(&str1, &str2); //p1, p2分别是str1, str2的指针, 因此需取地址(&)
    cout << str1 << " " << str2 << endl;
    return_strings2(nullptr, nullptr);
    cout << str3 << " " << str4 << endl;

    cout << "====================\n";

    //第三种:tuple
    std::tuple<string, string> sources1 = return_strings4(str3, str4);
    string tstring1 = std::get<0>(sources1); //get下标
    string tstring2 = std::get<1>(sources1);
    cout << tstring1 << " " << tstring2 << endl;

    cout << "====================\n";

    //第四种:pair
    std::pair<string, string> pstring = return_strings5(str3, str4);
    string tstring3 = pstring.first; //get下标
    string tstring4 = pstring.second;
    cout << tstring3 << " " << tstring4 << endl;

    cout << "====================\n";

    //第六种:struct
    rstr struct_string = return_string6();
    cout << struct_string.ststring1 << " " << struct_string.ststring2 << endl;
    return 0;
}
