#include <iostream>
#include <vector>

void insertion_sort(std::vector<int>& array) {
    for (int i = 1; i < array.size(); i++)
        for (int j = i; j > 0 && (array[j] < array[j - 1]); j--)
            std::swap(array[j], array[j - 1]);
}

int main() {
    std::vector<int>array = {1, 3, 4, 0, 9, -1};
    insertion_sort(array);
    for (int i : array)
        std::cout << i;
    return 0;
}
