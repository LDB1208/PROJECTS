#include <iostream>

/*
* 本程序演示联合体(union)
*/

struct vec2 {
    float x, y;
};

struct vec4 {
    union {
        struct {
            float x, y, z, w;
        };
        //a与x, y指向内存相同; b与z, w指向内存相同
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
            float a; //a, b指向相同内存
            int b;
        };
    };
    Union u;
    u.a = 2.0f;
    std::cout << u.a << ' ' << u.b << '\n'; //通常用于类型双关

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
