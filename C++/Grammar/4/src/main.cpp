#include <iostream>

using namespace std;

/*
* ��������ʾ�����ж����
*/

int main() {

    //if���
    int a = 5; //��������
    if (a == 6) {
        //���a=6,ִ�д��д���
        cout << "a = 6" << endl; //�ն����
    }
    else if (a < 4) {
        //���a������6,��a<4,ִ�д��д���
        cout << "a < 4" << endl;
    }
    else //���ֻ��һ��,���Բ��Ӵ�����
        //���a������6,��a>=4,ִ�д��д���
        cout << a << endl;

    cout << "====================" << endl;
    //Tips:���߼�����㲻���˳���ʱ��ͼ����Ÿı�˳��
    bool ex1 = !((!(1 < 0) || (4 > (6 < 9))) < (4 == 1 && 3 != 0));
    /*
     * 1.�ж�1<0(false)
     * 2.�ж�6<9(true)
     * 3.�ж�4>true(1)(true)
     * 4.�ж�!(false)(true)
     * 5.�ж�true||true(true)
     * 6.�ж�4==1(false)
     * 7.�ж�3!=0(true)
     * 8.�ж�false&&true(false)
     * 9.�ж�true(1)<false(0)(false)
     * 10.��false���߼�������(true(1))
     */
    cout << "ex1:" << ex1 << endl; //1(true)

    cout << "====================" << endl;

    //switch���
    int b = 0;
    switch (b) {
    case 0: //��ͬ��if (b == 0)
        cout << "b��0!" << endl; //�����ᴩ
        //���û��break��һ��case�Ĵ���ִ����Ϻ�����ִ�н�����case��Ĵ���
    case 2:
    case 4:
    case 6:
    case 8:
        cout << "b��ż��!" << endl;
        break; //����switch���
    case 1: //�ᴩ�ĺ���Ӧ��
    case 3:
    case 5:
    case 7:
    case 9:
        cout << "b������!" << endl;
        break;
    default: //������case��������ʱ����
        cout << "b����0-9��Χ��!" << endl;
        break;
    }
    return 0;
}
