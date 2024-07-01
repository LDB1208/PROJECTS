#include <iostream>

using namespace std;

/*
* 本程序演示运算符重载
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

    vector operator+(const vector& other) const { //运算符重载
        return add(other);
        /*
         * 另外两种方式:
         * return *this + other;
         * return operator+(other);
         */

    }

    vector operator*(const vector& other) const { //运算符重载
        return multiply(other);
        /*
         * 另外两种方式:
         * return *this * other;
         * return operator*(other);
         */
    }

    bool operator==(const vector& other) const {
        return x == other.x && y == other.y;
    }
};

ostream& operator<<(ostream& stream, const vector& other) { //重载<<运算符
    stream << other.x << ", " << other.y;
    return stream;
}

int main() {
    //运算符包括数学运算符及其他运算符,运算符就是函数
    int val = 1;
    int* p = &val; //*和&都是运算符

    vector position(3.0f, 3.0f);
    vector speed(0.5f, 1.5f);
    vector powerup(1.1f, 1.1f);
    vector result1 = position.add(speed.multiply((powerup))); //不用操作符重载的情况
    cout << result1.x << " " << result1.y << endl;


    vector result2 = position + speed * powerup; //使用操作符重载的情况
    cout << result2.x << " " << result2.y << endl;

    cout << result2 << endl;

    if (result1 == result2) {
        cout << "true" << endl;
    }
    return 0;
}
