#include <iostream>
#include "../include/header.h"

using namespace std;

int main()
{
    int n;
    char get;
    double a, b, c, d, e, f, g, h, i, j, k, l;
    cout << "此程序可以计算出二元或三元一次方程组的解" << endl;
    cin.get();

    while (true)
    {
        cout << "二元还是三元:";
        cin >> n;

        switch (n)
        {
        case 2:
            cout << "请依次输入未知数项的系数和右值,共6个(暂不支持分数)" << endl;
            cin >> a >> b >> c >> d >> e >> f; // 接收输入
            calc_2(a, b, c, d, e, f);          // 计算

            while (true)
            {
                cout << "是否退出?(y/n)";
                cin >> get;
                if (get == 'y' || get == 'Y')      // 判断get是否为y或Y
                    return 0;                      // 结束程序
                else if (get == 'n' || get == 'N') // 判断get是否为n或N
                    break;                         // 跳出while循环
                else
                {
                    cout << "输入错误!请重新输入" << endl;
                    continue; // 继续while循环
                }
            }
            break; // 跳出switch语句

        case 3:
            cout << "请依次输入未知数项的系数和右值,共12个(暂不支持分数)" << endl;
            cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l; // 接收输入
            calc_3(a, b, c, d, e, f, g, h, i, j, k, l);                      // 计算

            while (true)
            {
                cout << "是否退出?(y/n)";
                cin >> get;
                if (get == 'y' || get == 'Y')      // 判断get是否为y或Y
                    return 0;                      // 结束程序
                else if (get == 'n' || get == 'N') // 判断get是否为n或N
                    break;                         // 跳出while循环
                else
                {
                    cout << "输入错误!请重新输入" << endl;
                    continue; // 继续while循环
                }
            }
            break; // 跳出switch语句

        default:
            cout << "输入错误!请重新输入" << endl;
        }
    }
    return 0;
}
