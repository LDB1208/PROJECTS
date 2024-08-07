#include <iostream>

using namespace std;

/*
* ��������ʾconst�ؼ���
*/

class Entity {
private:
    int x1 = 0, y1 = 0;
    int* x2;
    mutable int var; //mutable�������ǳ�������,�������޸ı���
public:
    //���һ������û��(����)�޸���,�����Ϊconst
    int get_x() const { //�����޸����Ա����,ֻ��������Ч
        //x1 = 2, y1 = 2�ᱨ��
        var = 2; //ʹ��mutable�ؼ���
        return x1;
    }

    int get_x() {
        return x1;
    }

    const int* const GetX() const { //�˷�������һ�����ܱ��޸ĵ�ָ��
        return x2;
    }
};

//���ﳣ�����ò����޸�Entity
void PrintEntity(const Entity& e) { //PrintEntity()��ʹ����const��get_x()�汾
    cout << e.get_x() << endl;
}

int main() {
    //��һ���÷�:����
    const int a = 5;

    //�ڶ����÷�:ָ��(��const��*ǰ���Ǻ�)
    const int* ptr1 = new int; //��ͬ��int const* ptr1 = new int;
    //�����޸�ָ��ָ�������(��������)
    ptr1 = (int*)&a;
    cout << *ptr1 << endl;

    int* const ptr2 = new int;
    //������ָ��ָ����������
    *ptr2 = 0;
    cout << *ptr2 << endl;

    const int* const ptr3 = new int;
    //�����޸�ָ��ָ�������(��������),Ҳ������ָ��ָ����������

    //�������÷�:���뷽���е�const
    Entity e;
    PrintEntity(e);
    return 0;
}
