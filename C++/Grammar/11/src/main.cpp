#include <iostream>

using namespace std;

/*
* ��������ʾö��
*/

enum Ex1 {
    A, B, C //Ĭ�ϵ�һ����0,Ȼ��һ������һ������
};
enum Ex2 {
    a = 1, b = 3, c = 5 //���Ը���Щ������ֵ
};
enum Ex3 {
    D = 5, E, F //D��5,һ������һ������(E��6,F��7)
};
enum Ex4 : unsigned char { //ָ������Ҫ��ö�ٸ�ֵ������
    d, e, f
};

int main() {
    Ex1 val1 = B;
    //Ex1 val1 = 1�ᱨ��,������Ex1�е�����һ��
    if (val1 == 1) {
        cout << "val1 = 1" << endl;
    }
    Ex2 val2 = c;
    if (val2 == 5) {
        cout << "val2 = 5" << endl;
    }
    Ex3 val3 = F;
    if (val3 == 7) {
        cout << "val3 = 7" << endl;
    }
    return 0;
}
