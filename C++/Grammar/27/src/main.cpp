#include <iostream>

using namespace std;

/*
* ��������ʾ���������
*/

struct vector {
    float x, y;

    vector(float x, float y) : x(x), y(y) {}

    vector add(const vector& other) const {
        return vector(x + other.x, y + other.y);
    }

    vector multiply(const vector& other) const {
        return vector(x * other.x, y * other.y);
    }

    vector operator+(const vector& other) const { //���������
        return add(other);
        /*
         * �������ַ�ʽ:
         * return *this + other;
         * return operator+(other);
         */

    }

    vector operator*(const vector& other) const { //���������
        return multiply(other);
        /*
         * �������ַ�ʽ:
         * return *this * other;
         * return operator*(other);
         */
    }

    bool operator==(const vector& other) const {
        return x == other.x && y == other.y;
    }
};

ostream& operator<<(ostream& stream, const vector& other) { //����<<�����
    stream << other.x << ", " << other.y;
    return stream;
}

int main() {
    //�����������ѧ����������������,��������Ǻ���
    int val = 1;
    int* p = &val; //*��&���������

    vector position(3.0f, 3.0f);
    vector speed(0.5f, 1.5f);
    vector powerup(1.1f, 1.1f);
    vector result1 = position.add(speed.multiply((powerup))); //���ò��������ص����
    cout << result1.x << " " << result1.y << endl;


    vector result2 = position + speed * powerup; //ʹ�ò��������ص����
    cout << result2.x << " " << result2.y << endl;

    cout << result2 << endl;

    if (result1 == result2) {
        cout << "true" << endl;
    }
    return 0;
}
