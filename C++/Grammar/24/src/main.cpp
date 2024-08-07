#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾ��δ�������
*/

class Entity {
private:
    string m_name;
public:
    Entity() : m_name("Unknown") {}

    Entity(const string& name) : m_name(name) {}

    const string& GetName() const {
        return m_name;
    }
};

int main() {
    //��һ��:��ջ�ϴ���:һ������������,�Զ��ͷ��ڴ�
    { //����������
        Entity ex1 = Entity("LDB"); //ָ����������һ����ʽ
        cout << ex1.GetName() << endl;
    }
    //cout << ex1.GetName() << endl;
    cout << "====================" << endl;

    //�ڶ���:�ڶ��ϴ���:��Ҫ�ֶ��ͷ��ڴ�
    Entity* e;
    {
        Entity* ex2 = new Entity("LDB");
        e = ex2;
        cout << ex2->GetName() << endl;
    }
    cout << e->GetName() << endl;
    delete e; //��Ҫ�ֶ�delete
    return 0;
}
