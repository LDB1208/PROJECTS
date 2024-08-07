#include <iostream>
#include <vector>

using namespace std;

/*
* ��������ʾ��̬����(vector)
*/

struct Vertex {
    float x, y, z;
};

ostream& operator<<(ostream& stream, const Vertex& vertex) {
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void Function(const vector<Vertex>& vertices) {} //��������,��ֹ���ƶ������ڴ�(���������const)

int main() {
    Vertex vertices1[5]; //�������޶���Ԫ����Ŀ������

    vector<Vertex> vertices2;
    vertices2.push_back({ 1, 2, 3 }); //���Ԫ��
    vertices2.push_back({ 4, 5, 6 });

    for (int i = 0; i < vertices2.size(); ++i) //ѭ�����
        cout << vertices2[i] << endl;

    for (Vertex& v : vertices2) { //���ڷ�Χ��ѭ��(���õķ�ʽ)
        //�������,��ֹ���ƶ������ڴ�
        cout << v << endl;
    }

    cout << "====================" << endl;

    vertices2.erase(vertices2.begin() + 1); //ɾ�������2��Ԫ��
    for (Vertex& v : vertices2)
        cout << v << endl;

    vertices2.clear(); //�������(��ʱ�����СΪ0)
    return 0;
}
