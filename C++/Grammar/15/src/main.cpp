#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾ�麯��
*/

class Entity {
public:
    virtual string GetName() { //���ඨ���麯��,����˺�������д,����ָ��Player��ĺ���
        return "Entity";
    }
};

class Player : public Entity {
private:
    string MyName;
public:
    Player(const string& name) : MyName(name) {}
    //�������Ĺ��캯����MyName(name)�ǳ�ʼ���б�(MyName = name;),MyName�ǳ�Ա������name�ǲ���

    string GetName() override { //���าд������麯�����ڴ˴�ʹ��override���Ǳ����,�����ô�������пɶ���
        return MyName;
    }
};

void PrintName(Entity* entity) {
    cout << entity->GetName() << endl; //->�Ǽ�ͷ��������������e.GetName()��ֻ����������һ��ָ��
}

int main() {
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("LDB");
    PrintName(p);
    return 0;
}
