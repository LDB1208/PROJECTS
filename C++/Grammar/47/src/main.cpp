#include <iostream>
#include <chrono> //计时库
#include <thread>

/*
* 本程序演示计时
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
        float ms = duration.count() * 1000.0f; //毫秒
        std::cout << "Timer took " << ms << "ms\n";
    }
};

void function() {
    Timer timer;

    for (int i = 0; i < 100; ++i)
        std::cout << "Hello\n";
} //timer被销毁,运行析构函数

int main() {
    auto start = std::chrono::high_resolution_clock::now(); //开始计时
    //std::chrono::high_resolution_clock::now()表示当前时间

    using namespace std::literals::chrono_literals; //有这个才能用下一行的's'
    std::this_thread::sleep_for(1s); //当前线程暂停1s

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start; //高精度计时
    std::cout << duration.count() << "s\n";

    std::cout << "====================\n";

    function();

    return 0;
}
