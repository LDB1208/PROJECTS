#include <iostream>

using namespace std;

/*
* ��������ʾѭ�����
*/

int main() {
    for (int i = 0; i < 5; i++) {
        /*
        * int i = 0 ��������
        * i < 5 ѭ������
        * i++ i�Լ�1
        * ����������;����
        */
        cout << "Hello World!" << endl; //���5��"Hello World!"
    }

    cout << "====================" << endl;

    int i = 0; //��������
    while (i < 5) {
        //i < 5 ѭ������
        cout << "Hello World!" << endl;
        i++;
    }

    cout << "====================" << endl;

    do { //��ִ��һ��,Ȼ�����while�������ж��Ƿ����ѭ��
        cout << "Hello World!" << endl;
    } while (false);
    //�������ѭ���ܻᱻִ��һ��
    return 0;
}
