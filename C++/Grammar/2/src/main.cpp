#include <iostream>

using namespace std;

/*
* ��������ʾ�����볣��,�������͵Ĵ�С���������
*/

int main() {
    //�����볣��
    //�Ϸ���������������
    int _num = 3;
    int num = 4;
    int Num = 5;
    int n_m = 6;
    int n7m = 7;

    const int constant = 0; //���ǳ������޷��޸�

    //ע�⸳ֵʱ����ĸ��׺
    int ex1 = 1;
    unsigned int ex2 = 3u;
    long int ex3 = 9l;
    long long int ex4 = 99ll;
    float ex5 = 3.1f;
    double ex6 = 3.14159;
    long double ex7 = 3.14159L;
    cout << ex1 << " " << ex2 << " " << ex3 << " " << ex4 << " " << ex5 << " " << ex6 << " " << ex7 << endl;
    //C++11
    int e1{ 10 };
    int e2 = { 9 };
    int e3 = (8);
    cout << e1 << " " << e2 << " " << e3 << endl;

    cout << "====================" << endl;

    int bin = 0b1011; //������:��0b��0B��ͷ
    int oct = 013; //�˽���:��0��ͷ
    int dec = 11; //ʮ����
    int hex = 0xB; //ʮ������:��0x��0X��ͷ
    cout << bin << " " << oct << " " << dec << " " << hex << endl;

    typedef int score; //typedef����������͵ı���
    score me = 10; //�������ͱ���
    float other = static_cast<float>(me); //��static_castת����������

    cout << "====================" << endl;

    //��ʽ����ת��
    char a = 'a'; //a��ASCIIֵΪ97
    int b = 1;
    cout << a + b << endl; //a��ʽת��Ϊ97

    unsigned int u1 = 10;
    int u2 = -42;
    cout << u1 + u2 << endl; //�����ʽת��Ϊunsigned int

    cout << "====================" << endl;

    //����
    int c = 9, d = 10;
    cout << "c:" << c << endl << "d:" << d << endl;
    swap(c, d);
    cout << "After swaping:" << endl;
    cout << "c:" << c << endl << "d:" << d << endl;

    cout << "====================" << endl;

    //�������͵Ĵ�С
    //sizeof()�����������͵��ֽ���
    cout << "Size of char: " << sizeof(char) << endl
        << "Size of int: " << sizeof(int) << endl
        << "Size of short int: " << sizeof(short int) << endl
        << "Size of long int: " << sizeof(long int) << endl
        << "Size of long long int: " << sizeof(long long int) << endl
        << "Size of float: " << sizeof(float) << endl
        << "Size of double: " << sizeof(double) << endl
        << "Size of long double: " << sizeof(long double) << endl
        << "Size of wchar_t: " << sizeof(wchar_t) << endl
        << "Size of char16_t: " << sizeof(char16_t) << endl
        << "Size of char32_t: " << sizeof(char32_t) << endl;

    cout << "====================" << endl;

    //�������
    int intmin = -2147483648; //����
    int intmax = 2147483647; //����
    //���
    int intMin = -2147483649; //����
    int intMax = 2147483648; //����
    cout << "int����ֵ:" << intMin << endl << "int����ֵ:" << intMax << endl;
    return 0;
}
