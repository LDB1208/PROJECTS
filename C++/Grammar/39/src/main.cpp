#include <iostream>
#include <string>

using namespace std;

/*
 * 本程序演示模板(templates)
 */

template<typename T>
//定义模板(每一个使用模板的函数前都需要加上此定义)
void Print(T value) { //只有在调用此函数时, 它才会被创建
    cout << value << endl;
}

template<typename T, int N> //指定N为整数, T为类型
class Array {
private:
    T m_array[N];
public:
    int get_size() const {
        return N;
    }
};

int main() {
    //使用模板可以避免过多函数重载
    Print(5);
    Print("Hello");
    Print(5.5);
    Print<int>(9.9); //显式指定传入参数的类型T

    cout << "====================" << endl;

    Array<int, 5> array1{};
    cout << array1.get_size() << endl;

    Array<string, 5> array2;
    cout << array2.get_size() << endl;
    return 0;
}
