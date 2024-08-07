#include <iostream>
#include <vector>

using std::cout;

/*
 * ��������ʾ����ָ��(C���)
 */

void HelloWorld1() {
    cout << "Hello World!\n";
}

void HelloWorld2(int a) {
    cout << "Hello World!Value:" << a << "\n";
}

void PrintValue(int value) {
    cout << "value:" << value << "\n";
}

void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values) {
        func(value);
    }
}

int main() {
    auto function1 = HelloWorld1; //��ȡ����ָ��
    function1();

    typedef void(*HW_Function1)(); //��������
    HW_Function1 function2 = HelloWorld1;
    function2();

    typedef void(*HW_Function2)(int); //ָ������
    HW_Function2 function3 = HelloWorld2;
    function3(2);

    cout << "====================\n";

    std::vector<int> values = { 1, 5, 4, 2, 3 };
    ForEach(values, PrintValue);
    return 0;
}
