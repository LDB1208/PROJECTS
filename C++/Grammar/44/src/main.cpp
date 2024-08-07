#include <iostream>
#include <vector>
#include <functional> //std::function
#include <algorithm> //std::find_if

/*
 * ��������ʾlambda(��������)
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
    //����[]������ֵ(��δ������)
    int a = 5;
    //1.������������
    auto lambda1 = [=]() { std::cout << "Value:" << a << std::endl; };
    //2.ͨ�����ô���
    auto lambda2 = [&]() { std::cout << "Value:" << a << std::endl; };
    //3.ֻ����a������
    auto lambda3 = [a]() { std::cout << "Value:" << a << std::endl; };
    Print(lambda1);
    Print(lambda2);
    Print(lambda3);

    //����mutable�����ڲ��ı����
    auto lambda4 = [a]() mutable {
        a = 9;
        std::cout << "Value:" << a << std::endl;
        };
    Print(lambda4);

    std::cout << "====================\n";

    //ʵ������
    auto it = std::find_if(values.begin(), values.end(),
        [](int value) { return value > 3; });
    //��values���ҵ���3������������ص�һ������������Ԫ��
    std::cout << *it;
    return 0;
}
