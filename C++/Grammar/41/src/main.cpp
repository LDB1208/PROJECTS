#include <iostream>

using namespace std;

/*
 * ��������ʾ��
 */

#define WAIT cin.get()
#define OPEN_CURLY {
#define DEBUG 1

 //#ifdef DEBUG //���DEBUG�걻����
#if DEBUG == 1
#define LOG(x) cout << x << endl //�������
#elif defined(RELEASE) //���RELESE������
#define LOG(x)
#else //���δ������
#define LOG(x)
#endif //�������

#define OnePlusOne 1+1; //�����

int main() OPEN_CURLY
    WAIT; //��Ԥ����׶ΰ�WAIT�滻����ԭ�������

    cout << "====================" << endl;

    LOG("Hello World!");

    cout << "====================" << endl;

    int result1 = OnePlusOne; //��ͬ��int result1 = 1+1;
    int result2 = 3 * OnePlusOne; //��ͬ��int result2 = 3 * 1+1;(��������˳��)
    cout << result1 << endl << result2 << endl;
    #undef OnePlusOne //ȡ�������
    return 0;
}
