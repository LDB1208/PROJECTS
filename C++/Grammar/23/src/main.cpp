#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾ��Ԫ������
*/

static int level = 1;
static int speed = 2;

int main() {
    speed = level > 5 ? 10 : 5; //��Ԫ������:���� ? ����Ϊ������ : ����Ϊ�ٵ����
    /*
     * �������д����൱��
     * if (s_level > 5)
     *     s_speed = 10;
     * else
     *     s_speed = 5;
     */
    cout << speed << endl;

    cout << "====================" << endl;

    string rank = level > 10 ? "Master" : "Beginner"; //ʹ����Ԫ���������ô�������
    cout << rank << endl;

    cout << "====================" << endl;

    //��Ԫ��������Ƕ��
    speed = level > 5 ? level > 10 ? 15 : 10 : 5;
    /*
     * 1.�ж�level>10
     * 2.���level>10,ֵΪ15,����ֵΪ10
     * 3.�ж�level>5
     * 4.���level>5,ֵΪ15��10(ȡ������һ�ε��ж�),����ֵΪ5
     */

    level = 15;
    speed = level > 5 ? level > 10 ? 15 : 10 : 5; //15
    cout << speed << " ";

    level = 8;
    speed = level > 5 ? level > 10 ? 15 : 10 : 5; //10
    cout << speed << " ";

    level = 4;
    speed = level > 5 ? level > 10 ? 15 : 10 : 5; //5
    cout << speed;
    return 0;
}
