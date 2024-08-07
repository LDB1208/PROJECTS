#include <iostream>

/*
* ��������ʾ������(union)
*/

struct vec2 {
    float x, y;
};

struct vec4 {
    union {
        struct {
            float x, y, z, w;
        };
        //a��x, yָ���ڴ���ͬ; b��z, wָ���ڴ���ͬ
        struct {
            vec2 a, b;
        };
    };
};

void print_vec2(const vec2& vector) {
    std::cout << vector.x << ' ' << vector.y << '\n';
}

int main() {
    struct Union {
        union {
            float a; //a, bָ����ͬ�ڴ�
            int b;
        };
    };
    Union u;
    u.a = 2.0f;
    std::cout << u.a << ' ' << u.b << '\n'; //ͨ����������˫��

    std::cout << "====================\n";

    vec4 v4 = { 1.0f, 2.0f, 3.0f, 4.0f };
    print_vec2(v4.a);
    print_vec2(v4.b);
    v4.z = 5.0f;
    std::cout << "--------------------\n";
    print_vec2(v4.a);
    print_vec2(v4.b);
    return 0;
}
