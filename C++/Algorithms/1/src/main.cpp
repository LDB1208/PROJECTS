#include <iostream>
#include <vector>

/*
 * 本程序演示选择排序
 */

template<typename T>
void selection_sort_asc(std::vector<T>& array) {
    for (int i = 0; i < array.size(); ++i) {
        int min = i;
        for (int j = i + 1; j < array.size(); ++j)
            if (array[j] < array[min]) min = j;
        std::swap(array[i], array[min]);
    }
}

template<typename T>
void selection_sort_desc(std::vector<T>& array) {
    for (int i = 0; i < array.size(); ++i) {
        int max = i;
        for (int j = i + 1; j < array.size(); ++j)
            if (array[j] > array[max]) max = j;
        std::swap(array[i], array[max]);
    }
}

int main() {
    std::vector<char> a = { 'a', 'c', 'b', 'a', 'y', 'g' };
    selection_sort_asc(a);
    for (char i : a)
        std::cout << i << ' ';
    selection_sort_desc(a);
    for (char i : a)
        std::cout << i << ' ';

    std::cout << '\n';

    std::vector<int> b = { 35, 6, 23, 10, -3, 19 };
    selection_sort_asc(b);
    for (int i : b)
        std::cout << i << ' ';
    selection_sort_desc(b);
    for (int i : b)
        std::cout << i << ' ';
    return 0;
}
