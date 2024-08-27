#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    for (int i = 0; i < 20; i++) {
        cout << i + 1 << '.';
        int mode = rand() % 24;
        switch (mode) {
        case 0:
        {
            int add1 = rand() % 1000 + 1;
            int add2 = rand() % 1000 + 1;
            cout << add1 << " + " << add2;
        }
        break;
        case 1:
        {
        here1:
            int sub1 = rand() % 1000 + 1;
            int sub2 = rand() % 1000 + 1;
            if (sub1 < sub2) goto here1;
            cout << sub1 << " + " << sub2;
        }
        break;
        case 2:
        {
            bool n = rand() % 2;
            int mul1 = 0, mul2 = 0;
            if (n) {
                mul1 = rand() % 90 + 10;
                mul2 = rand() % 90 + 10;
            }
            else {
                mul1 = rand() % 900 + 100;
                mul2 = rand() % 10 + 1;
            }
            cout << mul1 << " × " << mul2;
        }
        break;
        case 3:
        {
            int div1 = 0, div2 = 0;
            for (;;) {
                div1 = rand() % 1000 + 1;
                div2 = rand() % 10 + 1;
                if (div1 % div2 == 0) {
                    cout << div1 << " ÷ " << div2;
                    break;
                }
            }
        }
        break;
        case 4:
        {
            int add1 = rand() % 1000 + 1;
            int add2 = rand() % 1000 + 1;
            int mul1 = 0;
            if (add2 > 99) mul1 = rand() % 10 + 1;
            else mul1 = rand() % 90 + 10;
            cout << add1 << " + " << add2 << " × " << mul1;
        }
        break;
        case 5:
        {
        here2:
            int sub1 = rand() % 1000 + 1;
            int sub2 = rand() % 1000 + 1;
            int mul1 = 0;
            if (sub2 > 99) mul1 = rand() % 10 + 1;
            else mul1 = rand() % 90 + 10;
            if (sub1 < sub2 * mul1) goto here2;
            cout << sub1 << " - " << sub2 << " × " << mul1;
        }
        break;
        case 6:
        {
            int add1 = rand() % 1000 + 1;
            int add2 = rand() % 1000 + 1;
            int div1 = 0;
            for (;;) {
                div1 = rand() % 10 + 1;
                if (add2 % div1 == 0) {
                    cout << add1 << " + " << add2 << " ÷ " << div1;
                    break;
                }
            }
        }
        break;
        case 7:
        {
            int sub1 = rand() % 1000 + 1;
            int sub2 = rand() % 1000 + 1;
            int div1 = 0;
            for (;;) {
                div1 = rand() % 10 + 1;
                if (sub2 % div1 == 0 && sub1 >= sub2 / div1) {
                    cout << sub1 << " + " << sub2 << " ÷ " << div1;
                    break;
                }
            }
        }
        break;
        case 8:
        {
            bool n = rand() % 2;
            int mul1 = 0, mul2 = 0;
            if (n) {
                mul1 = rand() % 90 + 10;
                mul2 = rand() % 90 + 10;
            }
            else {
                mul1 = rand() % 900 + 100;
                mul2 = rand() % 10 + 1;
            }
            int div1 = 0;
            for (;;) {
                div1 = rand() % 10 + 1;
                if (mul2 % div1 == 0 && mul1 >= mul2 / div1) {
                    cout << mul1 << " × " << mul2 << " ÷ " << div1;
                    break;
                }
            }
        }
        break;
        case 9:
        {
            bool n = rand() % 2;
            int mul1 = 0, mul2 = 0;
            if (n) {
                mul1 = rand() % 90 + 10;
                mul2 = rand() % 90 + 10;
            }
            else {
                mul1 = rand() % 900 + 100;
                mul2 = rand() % 10 + 1;
            }
            int add1 = rand() % 1000 + 1;
            cout << mul1 << " × " << mul2 << " + " << add1;
        }
        break;
        case 23:
            break;
        default: ;
        }
        cout << '\n';
    }

    //cin.get();
    return 0;
}