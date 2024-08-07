#include <iostream>
#include <memory> //��������ָ��ͷ�ļ�

using namespace std;

/*
* ��������ʾ����ָ��(std::unique_ptr, std::shared_ptr, std::weak_ptr)
*/

class Entity {
public:
    Entity() { cout << "Created Entity!" << endl; }

    ~Entity() { cout << "Destroyed Entity!" << endl; }

    void Print() { cout << "Print function called!" << endl; }
};

//����ָ������Զ��ͷ��ڴ�(�󲿷�������������Զ������ڴ�)
int main() {
    //��һ��:unique_ptr, ������������ʱ�ͷ��ڴ�
    {
        unique_ptr<Entity> entity1(new Entity()); //Created Entity!
        //unique_ptr<Entity> entity = new Entity();�ᱨ��
        entity1->Print();

        //���õ�����(exception�쳣��ȫ)
        unique_ptr<Entity> entity2 = make_unique<Entity>(); //Created Entity!

        entity2->Print();
        //unique_ptr<Entity> e0 = entity1;�㲻�ܸ���һ��unique_ptr
    } //Destroyed Entity!

    cout << "====================" << endl;

    //�ڶ���:shared_ptr, ���ü���(�������ָ���ж�������), ���ü����ﵽ0ʱ�ͷ��ڴ�
    {
        shared_ptr<Entity> e0;
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>(); //Created Entity!
            weak_ptr<Entity> weakEntity = sharedEntity; //���������ü���
            e0 = sharedEntity;
        } //sharedEntity���ͷ�
        e0->Print();
    } //Destroyed Entity!

    cout << "====================" << endl;

    //������:weak_ptr, ���Ժ�shared_ptrһ��ʹ��
    {
        weak_ptr<Entity> e0;
        {
            shared_ptr<Entity> sharedEntity = make_shared<Entity>(); //Created Entity!
            e0 = sharedEntity;
        } //Destroyed Entity!
        //e0->Print();
    }
    return 0;
}
