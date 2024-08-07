#include <iostream>
#include <vector>

using namespace std;

/*
* 本程序演示动态数组(vector)
*/

struct Vertex {
    float x, y, z;
};

ostream& operator<<(ostream& stream, const Vertex& vertex) {
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void Function(const vector<Vertex>& vertices) {} //加上引用,防止复制而消耗内存(根据情况加const)

int main() {
    Vertex vertices1[5]; //此数组限定了元素数目的上限

    vector<Vertex> vertices2;
    vertices2.push_back({ 1, 2, 3 }); //添加元素
    vertices2.push_back({ 4, 5, 6 });

    for (int i = 0; i < vertices2.size(); ++i) //循环输出
        cout << vertices2[i] << endl;

    for (Vertex& v : vertices2) { //基于范围的循环(更好的方式)
        //添加引用,防止复制而消耗内存
        cout << v << endl;
    }

    cout << "====================" << endl;

    vertices2.erase(vertices2.begin() + 1); //删除数组第2个元素
    for (Vertex& v : vertices2)
        cout << v << endl;

    vertices2.clear(); //清空数组(此时数组大小为0)
    return 0;
}
