#include <iostream>

using namespace std;

/*
* ��������ʾ��������
*/

//��������������һ������ʱ����ã���ͨ����ж�ر����������ڴ�
class Entity {
public:
    float x, y;

    Entity() { //���캯��
        x = 0.0f, y = 0.0f;
        cout << "Constructed Entity!" << endl;
    }

    ~Entity() { //��������
        cout << "Destroyed Entity!" << endl;
    }

    void Print() const {
        cout << x << ", " << y << endl;
    }
};

void Function() {
    Entity e;
    e.Print(); //�ڴ�ʱ���캯��������
} //��Ϊ�˶�������ջ�ϴ����ģ�������������ʱ�����ᱻ�Զ�����,��ʱ��������������

int main() {
    Function();
    return 0;
}
