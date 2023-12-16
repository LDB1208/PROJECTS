#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int Primes[25] = {2, 3, 5, 7, 11,
                  13, 17, 19, 23, 29,
                  31, 37, 41, 43, 47,
                  53, 59, 61, 67, 71,
                  73, 79, 83, 89, 97};

bool PrimeResult(int n) {
    if (n <= 1)
        return false;
    for (int Prime : Primes) {
        if (n == Prime)
            return true;
        else if (n % Prime == 0)
            return false;
    }
    for (int i = 101; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int min, max;
    unsigned flag = 0;
    clock_t start, end; //计时器
    double dur;

    cout << "这个程序实现孪生素数的枚举\n";
    cin.get();

    cout << "下限:";
    cin >> min;
    cout << "上限:";
    cin >> max;

    cout << "此区间的孪生素数有:" << endl;
    start = clock(); //开始
    for (int i = min; i <= max - 2; ++i) {
        if (PrimeResult(i)) {
            int j = i + 2;
            if (PrimeResult(j) && j <= max) {
                cout << i << " " << j << "\n";
                ++flag;
            }
        }
    }

    end = clock(); //结束
    if (flag == 0)
        cout << "此区间没有孪生素数!" << endl;
    else
        cout << "枚举完毕!\n此区间共有" << flag << "对孪生素数\n";

    dur = (double) (end - start); //计算相差多少CLOCKS_PER_SEC
    cout << "花费时间:" << (dur / CLOCKS_PER_SEC) << "s\n";
    cin.get(); //读取换行符(\n)
    cin.get();
    return 0;
}
