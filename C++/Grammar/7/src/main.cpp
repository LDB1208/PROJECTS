#include <iostream>
#include <cstring>

using namespace std;

/*
* ��������ʾԭʼָ��
*/

int main() {
    //ָ���Ǳ����ڴ��ַ��ʮ�����Ƶ�����

    //��
    int* p1, p2; //p1��ָ��int��ָ�룬p2��int
    int* p3, * p4; //p3��p4����ָ��int��ָ��
    //��ָ��
    //�����޷�����Щָ���ж�ȡ��д������
    void* ptr1 = 0;
    void* ptr2 = NULL;
    void* ptr3 = nullptr;

    //ָ��Ļ�������
    int var = 8;

    //������ʽ
    int* Ptr1 = &var; //��&����ȡ����var���ڴ��ַ
    double* Ptr2 = reinterpret_cast<double*>(&var); //reinterpret_cast<double *>��var���ڴ��ַת����double����

    int* Ptr3 = &var;
    double* Ptr4 = (double*)Ptr3; //ǿ��ת��
    cout << "var:" << var << endl << "Ptr2:" << Ptr2 << endl << "Ptr4:" << Ptr4 << endl;
    //��Ҫʹ��void����Ϊ�޷�����void���͵�ָ��

    cout << "====================" << endl;

    //��������
    *Ptr1 = 10;
    cout << var << endl << "Ptr1:" << Ptr1 << endl << "Ptr2:" << Ptr2 << endl;

    cout << "====================" << endl;

    //�����ڴ�
    char* buffer = new char[8]; //����˸��ֽڵ��ڴ�
    memset(buffer, 0, 8); //memset������cstringͷ�ļ���
    /*
    * memset������ָ�����������һ���ڴ��
    * ��һ��������Ҫ��д��ָ��
    * �ڶ���������Ҫ��������
    * �������������ڴ��Ĵ�С
    */

    delete[] buffer; //ɾ��buffer

    cout << "====================" << endl;

    //˫ָ�뼰��ָ��
    char** buffer2 = &buffer; //ָ��buffer���ڴ��ַ
    char*** buffer3 = &buffer2;
    cout << buffer2 << endl << buffer3 << endl;
    return 0;
}
