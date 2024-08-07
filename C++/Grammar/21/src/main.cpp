#include <iostream>
#include <string>

using namespace std;

/*
* ��������ʾmutable�ؼ���
*/

class Entity {
private:
    string name;
    mutable int DebugCount = 0; //mutable�������ǳ�������,�������޸ı���
public:
    const string& GetName() const {
        DebugCount++;
        return name;
    }
};

int main() {
    //��һ��:���෽����
    const Entity e;
    e.GetName();

    //�ڶ���:��lambda��
    int x = 8;
    auto f = [&]()mutable { //��lambda����mutable�����ں������޸ı���,��֮����
        /*�������ڿ�����&x,x,=,&
         * &x:ͨ�����÷��ͱ���x
         * x:ֱ�Ӵ�ֵ����x(ԭ����ֵ����)
         * =:�����еı�����ֵ(ԭ����ֵ����)
         * &:�����б������ô�ֵ
         */
        x++;
        cout << x << endl;
        };
    f(); //9
    return 0;
}
