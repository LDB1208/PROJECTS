#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾnew�ؼ���
*/

class Entity {
public:
    Entity() {
        cout << "Constructor has been called!" << endl;
    }

    ~Entity() {
        cout << "Destructor has been called!" << endl;
    }
};

int main() {
    //new�ڶ��Ϸ����ڴ�
    //new����ָ���������ڴ��ָ��
    int* a = new int;
    int* arr = new int[5]; //����
    double* b = new double;

    //��
    Entity* e1 = new Entity(); //���ù��캯��
    Entity* e2 = new Entity; //���ù��캯��
    Entity* e3 = (Entity*)malloc(sizeof(Entity)); //���������ڴ�(������Ҫ��)
    Entity* e4 = new(b) Entity; //ֻ���ù��캯��,����һ���ض����ڴ��ַ�г�ʼ��Entity

    //��Ҫ����,new���󲻻��ͷ��ڴ�,��Щ�����Ƿ�������ж�����Ҫ�ֶ�delete
    //ͬ����,delete�������������
    delete a;
    delete[] arr; //���newʱ��[],��deleteʱҲҪ��[]
    delete e1;
    delete e2;
    free(e3); //�����ͷ��ڴ�
    return 0;
}
