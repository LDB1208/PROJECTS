#include <iostream>
#include <chrono> //��ʱ��
#include <thread>

/*
* ��������ʾ��ʱ
*/

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f; //����
        std::cout << "Timer took " << ms << "ms\n";
    }
};

void function() {
    Timer timer;

    for (int i = 0; i < 100; ++i)
        std::cout << "Hello\n";
} //timer������,������������

int main() {
    auto start = std::chrono::high_resolution_clock::now(); //��ʼ��ʱ
    //std::chrono::high_resolution_clock::now()��ʾ��ǰʱ��

    using namespace std::literals::chrono_literals; //�������������һ�е�'s'
    std::this_thread::sleep_for(1s); //��ǰ�߳���ͣ1s

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start; //�߾��ȼ�ʱ
    std::cout << duration.count() << "s\n";

    std::cout << "====================\n";

    function();

    return 0;
}
