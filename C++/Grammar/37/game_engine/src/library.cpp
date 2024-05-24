#include "../include/library.h"
#include <iostream>

//创建库
//库的位置:cmake-build-*/*.a

namespace engine {
    void print_message() {
        std::cout << "Hello World!" << std::endl;
    }
}
