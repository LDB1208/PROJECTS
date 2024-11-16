#include <iostream>

#include "library.h"

namespace Hazel {
    __declspec(dllexport) void hello() {
        std::cout << "Hello, World!" << std::endl;
    }
}
