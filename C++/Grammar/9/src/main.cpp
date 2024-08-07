#include <iostream>

using namespace std;

/*
* ��������ʾ��ͽṹ��
*/

class Player1 {
public: //���ÿɼ���Ϊ���У�Ĭ������¶���˽�е�
    int x = 0, y = 0;
    int speed = 1;

    void Move(int xa, int ya) { //���еĺ�����Ϊ����
        x += xa * speed;
        y += ya * speed;
    }

    void Upgrade(int a) {
        speed += a;
        if (speed <= 0) {
            speed = 1;
        }
    }

private:
    int z = 0; //�ɼ���Ϊ˽�У��޷�������ʹ��
}; //��Ľ�β�зֺ�

struct PLayer2 { //�ṹ��Ψһ���಻ͬ�ĵ���:struct��Ĭ�Ͽɼ���Ϊ����
    int x = 0, y = 0;
    int speed = 1;

    void Move(int xa, int ya) { //���еĺ�����Ϊ����
        x += xa * speed;
        y += ya * speed;
    }

    void Upgrade(int a) {
        speed += a;
        if (speed <= 0) {
            speed = 1;
        }
    }

private:
    int z = 0;
};

int main() {
    int x1 = 0, y1 = 0, speed1 = 2; //�������������������£��ɶ��Բά������
    int x2 = 3, y2 = 4, speed2 = 5;

    //ʹ�������������򣬿ɶ���ǿ������ά��
    Player1 e1; //�������͹��ɵı�����Ϊ�����µĶ��������Ϊʵ��
    PLayer2 e2;
    e1.x = 0, e1.y = 0, e1.speed = 2;
    e2.x = 3, e2.y = 4, e2.speed = 5;
    cout << "e1.x:" << e1.x << endl << "e1.y:" << e1.y << endl <<
        "e1.speed:" << e1.speed << endl;
    cout << "e2.x:" << e2.x << endl << "e2.y:" << e2.y << endl <<
        "e2.speed:" << e2.speed << endl;

    cout << "====================" << endl;

    //ʹ�÷���
    cout << "After moving:" << endl;

    e1.Upgrade(3);
    e1.Move(3, -1);
    cout << "e1.x:" << e1.x << endl << "e1.y:" << e1.y << endl <<
        "e1.speed:" << e1.speed << endl;

    e2.Upgrade(-3);
    e2.Move(5, 4);
    cout << "e2.x:" << e2.x << endl << "e2.y:" << e2.y << endl <<
        "e2.speed:" << e2.speed << endl;
    return 0;
}
