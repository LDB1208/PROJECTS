#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾ��Ա��ʼ���б�
*/

//���������ڹ��캯���г�ʼ�����Ա(����)��һ�ַ�ʽ
class Entity {
private:
    string m_name;
    int m_score;
public:
    Entity() : m_name("Unknown"), m_score(0) {} //�൱���ڹ��캯���ڳ�ʼ��(Ҫ���ն������ʱ��˳��)
    //����ѳ�ʼ�����ڹ��캯����,��ṹ��2�ζ���(һ����Ĭ�Ϲ��캯��,��һ�����Լ�д�Ĺ��캯��)
    Entity(const string& name) : m_name(name) {}

    const string& GetName() const {
        return m_name;
    }
};

int main() {
    Entity e1;
    cout << e1.GetName() << endl;
    Entity e2("LDB"); //ָ������
    cout << e2.GetName() << endl;
    return 0;
}
