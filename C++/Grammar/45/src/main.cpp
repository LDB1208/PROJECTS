#include <iostream>
#include <string>
#include <algorithm>

using std::string; //可以单独使用

/*
 * 本次程序演示namespace
 */

 //目的:避免命名冲突
namespace apple {
    void print(const string& text) {
        std::cout << text << std::endl;
    }
    void print_again(const string& text) {
        std::cout << text << std::endl;
    }
}

namespace orange {
    void print(const char* text) {
        string temp = text;
        std::reverse(temp.begin(), temp.end()); //倒序
        std::cout << temp << std::endl;
    }

    namespace functions {
        void print_again(const char* text) {
            string temp = text;
            std::reverse(temp.begin(), temp.end()); //倒序
            std::cout << temp << std::endl;
        }
    }
}
int main() {
    apple::print("Hello");
    orange::print("Hello");

    std::cout << "====================\n";

    using namespace apple;
    print("LDB");
    print_again("LDB");

    std::cout << "====================\n";

    namespace a = apple;
    a::print("Cherno");

    std::cout << "====================\n";

    using namespace orange::functions;
    print_again("Hello");
    print("Hello");
    return 0;
}
