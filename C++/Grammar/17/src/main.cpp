#include <iostream>
#include <string>

using namespace std;

/*
 * ��������ʾ���麯��
 */

 //���麯�����������ڻ����ж���һ��û��ʵ�ֵĺ�����Ȼ��ǿ������ȥʵ�ָú���
class Printable {
public:
    virtual string GetClassName() = 0;
};

class Entity1 : public Printable {
public:
    virtual string GetName() = 0; //���麯������������һ��������ʵ��

    string GetClassName() override {
        return "Entity1";
    }
};

class Entity2 : public Printable {
public:
    virtual string GetName() {
        return "Entity2";
    }

    string GetClassName() override {
        return "Entity2";
    }
};

class Player : public Entity1 {
private:
    string MyName;
public:
    Player(const string& name) : MyName(name) {}

    string GetName() override { //ֻ��������ʵ�������д��麯���󣬲��ܽ���ʵ����
        return MyName;
    }

    string GetClassName() override {
        return "Player";
    }
};

void Print(Printable* obj) {
    cout << obj->GetClassName() << endl; //��ӡ����
}

int main() {
    Entity1* e1 = new Player("LDB"); //���ǲ���ʵ�����д��麯������
    Entity2* e2 = new Entity2();
    Player* p = new Player("LDB");

    Print(e1);
    Print(e2);
    Print(p);
    return 0;
}
