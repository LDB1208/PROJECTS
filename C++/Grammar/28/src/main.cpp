#include <cstdio>

/*
* ��������ʾthis�ؼ���
*/

//this���Է��ʳ�Ա����,����һ��ָ��ǰ����ʵ����ָ��
class Entity1; //������
class Entity2;

void PrintEntity1(Entity1* e); //ֻ����������������PrintEntity1��PrintEntity2����֪������Entity1
void PrintEntity2(const Entity1& e);

void PrintEntity3(const Entity2& e); //ͬ��

class Entity1 {
public:
    int x, y;

    Entity1(int x, int y) {
        Entity1* e = this; //Ĭ��const,�����޸�
        e->x = x; //Entity()�е�x����ֵΪ���캯�����x(����this��ֻ���ó�Ա��ʼ���б�)

        this->y = y; //����ֱ������д

        PrintEntity1(this);
        PrintEntity2(*this); //��������(const)

    }

    int GetX() const {
        const Entity1* e1 = this; //�����������const,����һ�д��������const
        //e->x = 0;
        const Entity1& e2 = *this; //ͬ��
    }
};

class Entity2 {
public:
    Entity2(int x, int y) {
        delete this; //�ڴ��ͷ�(���Ƽ�)
    }//ִ��delete this;��Ͳ��ܷ��������ĳ�Ա����
};

void PrintEntity1(Entity1* e) {}

void PrintEntity2(const Entity1& e) {}

void PrintEntity3(const Entity2& e) {}

void PrintXY(Entity1 e) {
    printf("x: %d\ny: %d", e.x, e.y);
}

int main() {
    Entity1 e(1, 5);
    PrintXY(e);
    return 0;
}
