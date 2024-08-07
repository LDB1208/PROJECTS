#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 本程序演示auto关键字
 */

string GetName() {
    return "LDB";
}

class Device {
};

class DeviceManager {
private:
    std::unordered_map<string, vector<Device*>> m_Devices;
public:
    const std::unordered_map<string, vector<Device*>>& GetDevices() const {
        return m_Devices;
    }
};

int main() {
    int a = 5;
    auto b = a;
    auto c = 5.5;
    auto d = "LDB";
    printf("%d %d %g %s\n", a, b, c, d);
    auto name = GetName();
    cout << name << endl << "====================\n";

    vector<string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");
    for (vector<string>::iterator it = strings.begin(); //用auto替代
        it != strings.end(); it++)
        cout << *it << endl;

    cout << "====================\n";
    using DeviceMap = std::unordered_map<string, vector<Device*>>;
    //typedef std::unordered_map<string, vector<Device *>> DevcieMap
    DeviceManager dm;
    const DeviceMap& devices = dm.GetDevices(); //用auto替代

    return 0;
}
