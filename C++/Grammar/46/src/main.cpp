#include <iostream>
#include <thread>

/*
 * 本程序演示线程
 */

static bool s_finished = false;

void do_work() {
    using namespace std::literals::chrono_literals;

    while (!s_finished) {
        std::cout << "Working...\n"; //如果以最快速度，会导致此线程CPU占用100%
        std::this_thread::sleep_for(1s);
    }

}

int main() {
    std::thread worker(do_work); //新建线程并启动

    std::cin.get(); //再按ENTER之前它会阻碍这个线程
    s_finished = true;
    worker.join(); //等待一个线程完成它用join()
    std::cout << "Finished.\n";
    std::cin.get();
    return 0;
}
