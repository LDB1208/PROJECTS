#include <iostream>

using namespace std;

int main() {
    cout << "本程序用来计算您的BMI(身体质量指数)" << endl;
    cin.get();

    double w, h;
    cout << "您的体重(kg):"; cin >> w;
    cout << "您的身高(m):"; cin >> h;

    double BMI = w / h / h;
    cout << "您的BMI值为:" << BMI << endl;
    if (18.5 <= BMI && BMI <= 24.9)
        cout << "正常!" << endl;
    else if (BMI < 18.5)
        cout << "偏瘦!" << endl;
    else
        cout << "偏胖!" << endl;
    cin.get();
    cin.get();
    return 0;
}
