#include <iostream>

using namespace std;

/*
* ��������ʾ��̬
*/

extern int var1; //���ⲿ���뵥ԪѰ��var1
int var2 = 1;

void Function() { //�������ӵ�Static.cpp�е�Function()����
    cout << var1 << endl;
}

struct Entity1 {
    int x, y;

    void Print() {
        cout << x << ", " << y << endl;
    }
};

struct Entity2 {
    static int x, y;

    void Print() {
        cout << x << ", " << y << endl;
    }
};

struct Entity3 {
    static int x, y;

    static void Print() {
        cout << x << ", " << y << endl;
    }
};

struct Entity4 {
    int x, y;
    /*�������Ϸ�:��̬���ܷ��ʷǾ�̬,��̬����û����ʵ��
     *static void Print(){
     *    cout << x << ", " << y << endl;
     *}
     */
};

//�Ϸ�
static void Print(Entity4 e6) {
    cout << e6.x << ", " << endl;
}

int Entity2::x; //������Ҫ��ĳЩ�ط����徲̬����
int Entity2::y; //������::������
int Entity3::x;
int Entity3::y;

void static FunctionEx1() {
    int i = 0; //���ô˺���ʱ,i����ʼ��Ϊ0
    i++;
    cout << i << " ";
}

void static FunctionEx2() {
    static int i = 0; //�൱���ڴ˺����ⲿ�����˱���i
    i++;
    cout << i << " ";
}

int main() {
    //�����ṹ����ľ�̬
    //���0 1
    cout << var1 << " " << var2 << endl;

    cout << "====================" << endl;

    //�����ṹ����ľ�̬
    Entity1 e1;
    e1.x = 2;
    e1.y = 3;
    Entity1 e2 = { 5, 8 }; //��һ�ֳ�ʼ���ķ���

    /*
     * ���:
     * 2, 3
     * 5, 8
     */
    e1.Print();
    e2.Print();

    cout << "====================" << endl;

    Entity2 e3, e4;
    e3.x = 2;
    e3.y = 3;
    //Entity2 e4 = {5, 8}; ������ʧ��,��Ϊx��y���������Ա
    e4.x = 5;
    e4.y = 8;

    /*
     * ���:
     * 5, 8
     * 5, 8
     */
    e3.Print(); //��Ϊe3��e4��x��y��ָ��ͬһ���ڴ�
    e4.Print(); //�����޸���e4��x��y���൱���޸���e3��x��y

    cout << "====================" << endl;

    //������������������,��ȷ��д��������:
    Entity2::x = 6;
    Entity2::y = 9;
    e3.Print();
    e4.Print();

    cout << "====================" << endl;

    Entity3 e5;
    Entity3::x = 0;
    Entity3::y = 1;
    Entity3::Print(); //��ΪPrint()�����Ǿ�̬��,������������

    cout << "====================" << endl;

    //�ֲ���̬
    for (int i = 0; i <= 4; ++i) {
        FunctionEx1(); //���1 1 1 1 1
    }
    cout << endl;
    for (int i = 0; i <= 4; ++i) {
        FunctionEx2(); //���1 2 3 4 5
    }
    return 0;
}
