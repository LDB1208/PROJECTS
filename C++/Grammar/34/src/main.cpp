#include <iostream>
#include <vector>

using namespace std;

/*
* ��������ʾvector���Ż�
*/

struct Vertex {
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {
        cout << "Copied!" << endl;
    }
};


int main() {
    vector<Vertex> vertices;
    vertices.push_back(Vertex(1, 2, 3)); //����1��
    //��һ��,������main�����ĵ�ǰջ������
    //��Ҫ��main�������ֵ���Ƶ�vertices
    vertices.push_back(Vertex(4, 5, 6)); //����2��
    //�ڶ���,��main������ֵ���Ƶ�vertices(��һ�θ���)
    //vertices�������Լ��Ĵ�С(�ڶ��θ���)
    vertices.push_back(Vertex(7, 8, 9)); //����3��(һ��6��)
    //������,ͬ��һ���θ���ֵ
    //vertices��һ�ε������Լ��Ĵ�С(�����θ���)

    cout << "====================" << endl;

    //�Ż�1:����һ��ʼ�������С
    vector<Vertex> vertices2;
    vertices2.reserve(3); //������洢3��Vertex���ڴ�
    vertices2.push_back(Vertex(1, 2, 3));
    vertices2.push_back(Vertex(4, 5, 6));
    vertices2.push_back(Vertex(7, 8, 9)); //һ������3��

    cout << "====================" << endl;

    //�Ż�2:��������Vertex��λ��
    vector<Vertex> vertices3;
    vertices3.reserve(3);
    vertices3.emplace_back(1, 2, 3); //�����ݹ��캯���Ĳ����б�
    vertices3.emplace_back(4, 5, 6);
    vertices3.emplace_back(7, 8, 9); //������
    return 0;
}
