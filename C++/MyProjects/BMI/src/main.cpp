#include <iostream>

using namespace std;

int main() {
    cout << "������������������BMI(��������ָ��)" << endl;
    cin.get();

    double w, h;
    cout << "��������(kg):"; cin >> w;
    cout << "�������(m):"; cin >> h;

    double BMI = w / h / h;
    cout << "����BMIֵΪ:" << BMI << endl;
    if (18.5 <= BMI && BMI <= 24.9)
        cout << "����!" << endl;
    else if (BMI < 18.5)
        cout << "ƫ��!" << endl;
    else
        cout << "ƫ��!" << endl;
    cin.get();
    cin.get();
    return 0;
}
