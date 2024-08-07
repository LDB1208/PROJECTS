#include <iostream>

using namespace std;

/*
* ��������ʾ��ͷ������
*/

class Entity {
public:
    int x = 0;

    void Print1() { cout << "Hello!" << endl; }

    void Print2() const { cout << "Hello!" << endl; }
};

class ScopedPtr {
private:
    Entity* m_obj;
public:
    ScopedPtr(Entity* entity) : m_obj(entity) {}

    ~ScopedPtr() { delete m_obj; }

    Entity* operator->() { return m_obj; }

    const Entity* operator->() const { return m_obj; }

};

struct Vector3 {
    float x, y, z;
};

int main() {
    Entity e;
    e.Print1();

    //��һ��(���Ƽ�)
    Entity* ptr1 = &e;
    (*ptr1).Print1(); //��������

    //�ڶ���
    Entity* ptr2 = &e;
    //ptr.Print(); �ᱨ��
    ptr2->Print1(); //��ͷ������
    ptr2->x = 2;
    cout << ptr2->x << endl;

    cout << "====================" << endl;

    //���������
    ScopedPtr entity1 = new Entity();
    entity1->Print1();

    const ScopedPtr entity2 = new Entity();
    entity2->Print2();

    cout << "====================" << endl;

    //��ȡ�ڴ���ĳ����Ա������ƫ����
    int offset1 = (int)(size_t) & ((Vector3*) nullptr)->x;
    //1.��nullptrת����Vector3*
    //2.�õ��ڴ沼��
    //3.&ȡx���ڴ��ַ
    //4.ת��Ϊint
    int offset2 = (int)(size_t) & ((Vector3*) nullptr)->y;
    int offset3 = (int)(size_t) & ((Vector3*) nullptr)->z;
    cout << offset1 << endl << offset2 << endl << offset3 << endl;
    return 0;
}
