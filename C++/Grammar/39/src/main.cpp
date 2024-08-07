#include <iostream>
#include <string>

using namespace std;

/*
 * ��������ʾģ��(templates)
 */

template<typename T>
//����ģ��(ÿһ��ʹ��ģ��ĺ���ǰ����Ҫ���ϴ˶���)
void Print(T value) { //ֻ���ڵ��ô˺���ʱ, ���Żᱻ����
    cout << value << endl;
}

template<typename T, int N> //ָ��NΪ����, TΪ����
class Array {
private:
    T m_array[N];
public:
    int get_size() const {
        return N;
    }
};

int main() {
    //ʹ��ģ����Ա�����ຯ������
    Print(5);
    Print("Hello");
    Print(5.5);
    Print<int>(9.9); //��ʽָ���������������T

    cout << "====================" << endl;

    Array<int, 5> array1{};
    cout << array1.get_size() << endl;

    Array<string, 5> array2;
    cout << array2.get_size() << endl;
    return 0;
}
