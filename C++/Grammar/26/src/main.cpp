#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾ��ʽ���캯���Լ�explicit�ؼ���
*/

class Entity {
private:
    string m_name;
    int m_age;
public:
    Entity(const string& name) : m_name(name), m_age(-1) {
        cout << "Name constructor called!" << endl;
    }

    Entity(int age) : m_name("Unknown"), m_age(age) {
        cout << "Age constructor called!" << endl;
    }

    explicit Entity(double speed) {
        cout << "Speed constructor called!" << endl;
    }
};

void PrintEntity(const Entity& entity) {}

int main() {
    Entity a = 13; //ָ����������һ����ʽ
    Entity b = string("LDB");
    PrintEntity(22); //��ʽ���캯��
    PrintEntity(string("LDB"));
    PrintEntity(Entity("LDB")); //���ù��캯��

    //explicit�ؼ���:һ�����캯��ʹ��explicit�ؼ���ʱ,û����ʽת��
    Entity c(1.0);
    Entity d = Entity(2.0);
    //Entity e = 1.0;�ᱨ��
    return 0;
}
