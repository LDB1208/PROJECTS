#include <iostream>
#include <array>

using namespace std;

/*
* ��������ʾ����
*/

class Entity {
public:
    int* ex3 = new int[5];

    Entity() {
        for (int i = 0; i < 5; i++) {
            ex3[i] = 2;
        }
    }
};

int main() {
    int ex1[5] = { 0, 0, 0, 0, 0 }; //һ����5������������(��ջ�ϴ����ģ�����������Χ�ͻᱻ����)
    ex1[0] = 1; //���������ָ��λ�õ�ֵ��[]��������±꣬��0��ʼ
    ex1[4] = 5;
    int a = ex1[0]; //������ex1�ĵ�һ��Ԫ�ظ�ֵ��a
    //ex1[-1] = 3;
    //ex1[5] = 4;
    //�ڴ����Υ�棬�ⳬ��������ı߽�

    cout << ex1[0] << endl; //�������ĵ�һ��Ԫ��
    cout << ex1 << endl; //�������ĵ�ַ

    cout << "====================" << endl;

    for (int i = 0; i < 5; i++) { //ʹ��forѭ�����б���
        ex1[i] = 2;
        cout << ex1[i];
    }

    cout << endl << "====================" << endl;

    int* ptr = ex1; //ʵ������ָ������
    *(ptr + 2) = 6; //�൱��ex1[2] = 6;
    //ƫ����=2*4=8�ֽڣ�Ҳ���ǵ�9~12�ֽھ���ex1�ĵ�����Ԫ�ص�λ��
    cout << ex1[2] << endl; //6

    *reinterpret_cast<int*>((reinterpret_cast<char*>(ptr) + 12)) = 7;//�൱��ex1[3] = 7;
    //�Ȱ�ptrת����char*���ͣ��ټ���12*1=12�ֽڵ�ƫ������������ĸ�Ԫ�����ڵ�λ�ã����Ű�����ָ��ת��Ϊint*���ͣ������������
    cout << ex1[3] << endl; //7

    cout << "====================" << endl;

    //ʹ��new
    int* ex2 = new int[5]; //һ����5������������(���ϴ�����,ֻ���������ֶ�����,�����������ô���)
    for (int i = 0; i < 5; i++) {
        ex2[i] = 2;
        cout << ex2[i];
    }
    delete[] ex2;

    cout << endl << "====================" << endl;

    Entity e;
    cout << e.ex3 << endl; //�ڴ���Ѱַ�������ֽ�������ex3�ĵ�ַ

    cout << "====================" << endl;

    int b[5];
    //���Ҫʹ�������ַ���,��������ջ�Ϸ��������
    //���Ǿ�����Ҫ��
    int size = sizeof(b); //����b���ֽ���
    int count = sizeof(b) / sizeof(int); //����b��Ԫ������
    cout << size << endl << count << endl;

    cout << "====================" << endl;

    array<int, 5> another; //����ʹ��C++11��array��array<����, Ԫ������> ������;
    for (int i = 0; i < another.size(); i++) { //array����ʹ������.size()����ȡ����Ĵ�С
        another[i] = 2;
        cout << another[i];
    }
    return 0;
}
