#include <iostream>

using namespace std;

void calc_2(double a, double b, double c, double d, double e, double f) { //��Ԫһ�η������ͨ��
    double x, y;
    if (a * e - b * d == 0) {
        if (c * e - b * f == 0 || a * f - c * d == 0)
            cout << "������" << endl;
        else
            cout << "�޽�" << endl;
    }
    else {
        x = (c * e - b * f) / (a * e - b * d);
        y = (a * f - c * d) / (a * e - b * d);
        cout << "x��ֵΪ:" << x << endl << "y��ֵΪ:" << y << endl;
    }
}

void calc_3(double a, double b, double c, double d, double e, double f,
    double g, double h, double i, double j, double k, double l) { //��Ԫһ�η������ͨ��
    double x, y, z;
    if (a * (f * k - g * j) + b * (g * i - e * k) + c * (e * j - f * i) == 0) {
        if (b * (g * l - h * k) + c * (h * j - f * l) + d * (f * k - g * j) == 0 ||
            a * (h * k - g * l) + c * (e * l - h * i) + d * (g * i - e * k) == 0 ||
            a * (f * l - h * j) + b * (h * i - e * l) + d * (e * j - f * i) == 0)
            cout << "������" << endl;
        else
            cout << "�޽�" << endl;
    }
    else {
        x = (b * (g * l - h * k) + c * (h * j - f * l) + d * (f * k - g * j)) /
            (a * (f * k - g * j) + b * (g * i - e * k) + c * (e * j - f * i));

        y = (a * (h * k - g * l) + c * (e * l - h * i) + d * (g * i - e * k)) /
            (a * (f * k - g * j) + b * (g * i - e * k) + c * (e * j - f * i));

        z = (a * (f * l - h * j) + b * (h * i - e * l) + d * (e * j - f * i)) /
            (a * (f * k - g * j) + b * (g * i - e * k) + c * (e * j - f * i));
        cout << "x��ֵΪ:" << x << endl << "y��ֵΪ:" << y << endl << "z��ֵΪ:" << z << endl;
    }
}
