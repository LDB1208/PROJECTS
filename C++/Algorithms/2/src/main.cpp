#include <iostream>
#include <vector>

/*
 * 本程序演示插入排序
 */

template <typename T>
void insertion_sort_asc(std::vector<T> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
        for (int j = i; j > 0 && (arr[j] < arr[j - 1]); --j)
            std::swap(arr[j], arr[j - 1]);
}

template <typename T>
void insertion_sort_desc(std::vector<T> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
        for (int j = i; j > 0 && (arr[j] > arr[j - 1]); --j)
            std::swap(arr[j], arr[j - 1]);
}

int main()
{
    std::vector<int> a = {1, 3, 4, 0, 9, -1};
    insertion_sort_asc(a);
    for (int i : a)
        std::cout << i << ' ';
    insertion_sort_desc(a);
    for (int i : a)
        std::cout << i << ' ';

    std::cout << '\n';

    std::vector<char> b = {'a', 't', 'q', 'f', 'p'};
    insertion_sort_asc(b);
    for (char i : b)
        std::cout << i << ' ';
    insertion_sort_desc(b);
    for (char i : b)
        std::cout << i << ' ';
    std::cin.get();
    return 0;
}