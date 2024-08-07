#include <iostream>

using namespace std;

/*
 * ��������ʾ���캯��
 */

 //���캯���ڴ���һ������ʱ������ã���ͨ�������ñ������ʼ��(ÿ���඼��һ��Ĭ�Ϲ��캯��)
 //ֻʹ��һ�����еľ�̬����������������
class Entity {
public:
    float x, y;

    Entity() { //���캯��
        x = 0.0f, y = 0.0f;
    }

    //��������:����ͬ�ĺ��������в�ͬ�Ĳ���
    Entity(float X, float Y) { //�������Ĺ��캯��
        x = X;
        y = Y;
    }

    void Init() {
        x = 0.0f, y = 0.0f;
    }

    void Print() {
        cout << x << ", " << y << endl;
    }
};

class Log {
public:
    static void Write() {
        cout << "Hello world!" << endl;
    }

    Log() = delete; //ɾ��Ĭ�Ϲ��캯��
};

int main() {
    Entity e1;
    e1.Init(); //��ʼ������
    cout << e1.x << ", " << e1.y << endl;
    e1.Print(); //��������ַ�ʽ

    cout << "====================" << endl;

    Entity e2;
    e2.Print(); //���ڲ���Ҫ��ʼ��������

    cout << "====================" << endl;

    Entity e3(3.0f, 2.1f); //�������Ĺ��캯��
    e3.Print();

    cout << "====================" << endl;

    //Log l;�ᱨ����ΪĬ�Ϲ��캯��������
    Log::Write();
    return 0;
}
