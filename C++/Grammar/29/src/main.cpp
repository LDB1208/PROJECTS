#include <iostream>

using namespace std;

/*
* ��������ʾ����������(ջ������������)
*/

class Entity {
public:
    Entity() { cout << "Created Entity!" << endl; }

    ~Entity() { cout << "Destroyed Entity!" << endl; }
};

class ScopedPtr {
private:
    Entity* m_ptr;
public:
    ScopedPtr(Entity* ptr) : m_ptr(ptr) {}

    ~ScopedPtr() { delete m_ptr; }
};

int* CreateArray1() {
    int array1[50]; //array�뿪�����������ͻᱻ����
    for (int i = 0; i < 50; ++i)
        array1[i] = 0;
    cout << array1 << endl;
    return array1;
}

int* CreateArray2() {
    int* array2 = new int[50];
    for (int i = 0; i < 50; ++i)
        array2[i] = 0;
    cout << array2 << endl;
    return array2;
}

void CreateArray3(int* array3) {
    for (int i = 0; i < 50; ++i)
        array3[i] = 0;
    cout << array3 << endl;
}

int main() {
    {
        Entity e1; //Created Entity!
    }
    //Destroyed Entity!(e��ջ�ϵĶ���,�����������ڴ�ͻᱻ�ͷ�)
    cout << "====================" << endl;
    {
        Entity* e2 = new Entity(); //Created Entity!
    }
    //��Ϊ���Ƕ��ϵĶ���,���Բ����Զ��ͷ��ڴ�

    cout << "====================" << endl;

    int array[50];
    CreateArray1();
    CreateArray2();
    CreateArray3(array);

    cout << "====================" << endl;

    {
        ScopedPtr e3(new Entity()); //ջ��������;:�Զ�����,�Զ�����
    } //e3������

    return 0;
} //������ֹʱ,����ϵͳ���ͷ�e2�ڴ�
