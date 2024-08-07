#include <iostream>
#include <vector>
#include <functional> //std::function
#include <algorithm> //std::find_if

/*
 * 本程序演示lambda(匿名函数)
 */

void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values) {
        func(value);
    }
}

void Print(const std::function<void()>& func) {
    func();
}

int main() {
    std::vector<int> values = { 1, 5, 4, 2, 3 };
    ForEach(values, [](int value) { std::cout << "Value:" << value << "\n"; });

    std::cout << "====================\n";
    //先用[]来捕获值(如何传入变量)
    int a = 5;
    //1.拷贝变量传入
    auto lambda1 = [=]() { std::cout << "Value:" << a << std::endl; };
    //2.通过引用传入
    auto lambda2 = [&]() { std::cout << "Value:" << a << std::endl; };
    //3.只拷贝a并传入
    auto lambda3 = [a]() { std::cout << "Value:" << a << std::endl; };
    Print(lambda1);
    Print(lambda2);
    Print(lambda3);

    //设置mutable来在内部改变参数
    auto lambda4 = [a]() mutable {
        a = 9;
        std::cout << "Value:" << a << std::endl;
        };
    Print(lambda4);

    std::cout << "====================\n";

    //实际运用
    auto it = std::find_if(values.begin(), values.end(),
        [](int value) { return value > 3; });
    //在values中找到比3大的整数并返回第一个满足条件的元素
    std::cout << *it;
    return 0;
}
