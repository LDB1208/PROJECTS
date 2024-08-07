#include <iostream>
#include <thread>

/*
 * ��������ʾ�߳�
 */

static bool s_finished = false;

void do_work() {
    using namespace std::literals::chrono_literals;

    while (!s_finished) {
        std::cout << "Working...\n"; //���������ٶȣ��ᵼ�´��߳�CPUռ��100%
        std::this_thread::sleep_for(1s);
    }

}

int main() {
    std::thread worker(do_work); //�½��̲߳�����

    std::cin.get(); //�ٰ�ENTER֮ǰ�����谭����߳�
    s_finished = true;
    worker.join(); //�ȴ�һ���߳��������join()
    std::cout << "Finished.\n";
    std::cin.get();
    return 0;
}
