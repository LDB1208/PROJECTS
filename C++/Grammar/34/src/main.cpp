#include <iostream>
#include <vector>

using namespace std;

/*
* 本程序演示vector的优化
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
    vertices.push_back(Vertex(1, 2, 3)); //复制1次
    //第一次,我们在main函数的当前栈构造它
    //需要把main函数里的值复制到vertices
    vertices.push_back(Vertex(4, 5, 6)); //复制2次
    //第二次,把main函数的值复制到vertices(第一次复制)
    //vertices调整了自己的大小(第二次复制)
    vertices.push_back(Vertex(7, 8, 9)); //复制3次(一共6次)
    //第三次,同第一二次复制值
    //vertices再一次调整了自己的大小(第三次复制)

    cout << "====================" << endl;

    //优化1:调整一开始的数组大小
    vector<Vertex> vertices2;
    vertices2.reserve(3); //仅分配存储3个Vertex的内存
    vertices2.push_back(Vertex(1, 2, 3));
    vertices2.push_back(Vertex(4, 5, 6));
    vertices2.push_back(Vertex(7, 8, 9)); //一共复制3次

    cout << "====================" << endl;

    //优化2:调整构造Vertex的位置
    vector<Vertex> vertices3;
    vertices3.reserve(3);
    vertices3.emplace_back(1, 2, 3); //仅传递构造函数的参数列表
    vertices3.emplace_back(4, 5, 6);
    vertices3.emplace_back(7, 8, 9); //不复制
    return 0;
}
