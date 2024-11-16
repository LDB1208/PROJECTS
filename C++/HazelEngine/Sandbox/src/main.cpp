
namespace Hazel {
    __declspec(dllimport) void hello();
}

int main() {
    Hazel::hello();
    return 0;
}
