#include <iostream>

using namespace std;

/*
* ��������ʾ����
*/

void Increment(int value) {
    value++;
}

void increment_one(int& value) { //����
    value++;
}

int main() {
    int a = 5;
    int& ref = a; //����&�������͵�һ���֣�������
    //���ñ����ʼ��
    //ʵ����ref�����ڣ�ֻ��a�ġ�����������ռ���ڴ�
    ref = 2;
    //�൱��a = 2;
    cout << a << endl;

    cout << "====================" << endl;

    int b = 5;
    Increment(b);
    cout << b << endl; //û�����ã��޷�����6������5

    increment_one(b);
    cout << b << endl; //����6

    cout << "====================" << endl;

    int A = 5;
    int B = 8;

    int& Ref = A; //����ʱ�����һ��ֵ
    Ref = B; //�㲻�������ı����������õı���,����ζ�����B��ֵ������A

    //A = 8, B = 8
    cout << "A = " << A << endl << "B = " << B << endl;

    int* REF = &A; //�����ı����������õı���
    *REF = 8;
    REF = &B;
    *REF = 5;

    //A = 8, B = 5
    cout << "A = " << A << endl << "B = " << B << endl;
    return 0;
}
