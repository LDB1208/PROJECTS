#include <iostream>
#include <vector>

/*
* ±¾³ÌÐòÑÝÊ¾Ï£¶ûÅÅÐò
*/

template<typename T>
void shell_sort_asc(std::vector<T>& arr) {
    int h = 1;
    while (h < arr.size() / 3) h = 3 * h + 1; //1, 4, 13, 40, 121, 364, 1093...
    while (h >= 1) {
        for (int i = h; i < arr.size(); ++i)
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
                std::swap(arr[j], arr[j - h]);
        h /= 3;
    }
}

template<typename T>
void shell_sort_desc(std::vector<T>& arr) {
    int h = 1;
    while (h < arr.size() / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (int i = h; i < arr.size(); ++i)
            for (int j = i; j >= h && arr[j] > arr[j - h]; j -= h)
                std::swap(arr[j], arr[j - h]);
        h /= 3;
    }
}

int main() {
    std::vector<int> a = { 1, 3, 4, 0, 9, -1 };
    shell_sort_asc(a);
    for (int i : a)
        std::cout << i << ' ';
    shell_sort_desc(a);
    for (int i : a)
        std::cout << i << ' ';

    std::cout << '\n';

    std::vector<char> b = { 'a', 't', 'q', 'f', 'p' };
    shell_sort_asc(b);
    for (char i : b)
        std::cout << i << ' ';
    shell_sort_desc(b);
    for (char i : b)
        std::cout << i << ' ';
    return 0;
}

