#include <iostream>
#include <chrono>
#include <memory>
#include <array>

/*
* 本程序演示基准测试(实际测量代码性能)
*/

class Timer {
public:
    Timer() {
        m_start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto end_point = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.01;

        std::cout << duration << "us(" << ms << "ms)\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};

int main() {
    int value = 0;
    {
        Timer timer;
        for (int i = 0; i < 1000000; ++i)
            value += 2;
    }
    std::cout << value << std::endl;

    std::cout << "====================\n";

    //比较shared_ptr和unique_ptr性能
    struct Vec2 { float x, y; };
    std::cout << "Make Shared\n";
    {
        std::array<std::shared_ptr<Vec2>, 1000> shared_ptrs;
        Timer timer;
        for (int i = 0; i < shared_ptrs.size(); ++i)
            shared_ptrs[i] = std::make_shared<Vec2>();
    }
    std::cout << "New Shared\n";
    {
        std::array<std::shared_ptr<Vec2>, 1000> shared_ptrs;
        Timer timer;
        for (int i = 0; i < shared_ptrs.size(); ++i)
            shared_ptrs[i] = std::shared_ptr<Vec2>(new Vec2());
    }
    std::cout << "Make Unique\n";
    {
        std::array<std::unique_ptr<Vec2>, 1000> shared_ptrs;
        Timer timer;
        for (int i = 0; i < shared_ptrs.size(); ++i)
            shared_ptrs[i] = std::make_unique<Vec2>();
    }


}