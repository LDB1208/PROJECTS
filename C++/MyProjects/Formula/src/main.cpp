#include <iostream>
#include "../include/header.h"

using namespace std;

int main() {
    int n;
    char get;
    double a, b, c, d, e, f, g, h, i, j, k, l;
    cout << "�˳�����Լ������Ԫ����Ԫһ�η�����Ľ�" << endl;
    cin.get();

    while (true) {
        cout << "��Ԫ������Ԫ:";
        cin >> n;

        switch (n) {
        case 2:
            cout << "����������δ֪�����ϵ������ֵ,��6��(�ݲ�֧�ַ���)" << endl;
            cin >> a >> b >> c >> d >> e >> f; //��������
            calc_2(a, b, c, d, e, f); //����

            while (true) {
                cout << "�Ƿ��˳�?(y/n)";
                cin >> get;
                if (get == 'y' || get == 'Y') //�ж�get�Ƿ�Ϊy��Y
                    return 0; //��������
                else if (get == 'n' || get == 'N') //�ж�get�Ƿ�Ϊn��N
                    break; //����whileѭ��
                else {
                    cout << "�������!����������" << endl;
                    continue; //����whileѭ��
                }
            }
            break; //����switch���

        case 3:
            cout << "����������δ֪�����ϵ������ֵ,��12��(�ݲ�֧�ַ���)" << endl;
            cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l; //��������
            calc_3(a, b, c, d, e, f, g, h, i, j, k, l); //����

            while (true) {
                cout << "�Ƿ��˳�?(y/n)";
                cin >> get;
                if (get == 'y' || get == 'Y') //�ж�get�Ƿ�Ϊy��Y
                    return 0; //��������
                else if (get == 'n' || get == 'N') //�ж�get�Ƿ�Ϊn��N
                    break; //����whileѭ��
                else {
                    cout << "�������!����������" << endl;
                    continue; //����whileѭ��
                }
            }
            break; //����switch���

        default:
            cout << "�������!����������" << endl;
        }
    }
    return 0;
}
