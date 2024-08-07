#include <iostream>
#include <vector>

inline static std::vector<int> search_for_the_first(const char* string, char a) {
    std::vector<int> ans;
    for (int i = 0; *(string + i) != NULL; ++i)
        if (*(string + i) == a) ans.push_back(i);
    return ans;
}

int main() {
    const char* a = "LDUBUWI";
    std::vector<int> b = search_for_the_first(a, 'U');
    for (int i = 0; i < b.size(); i++)
        std::cout << b[i] << ' ';
    return 0;
}