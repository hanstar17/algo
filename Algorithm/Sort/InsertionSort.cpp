#include <algorithm>
#include <functional>
#include <iostream>
#include <stddef.h>
#include <vector>

namespace alg
{
template <typename T, typename COMP>
void insert_sort(T *array, size_t size, COMP comp)
{
    for (int i = 1; i < size; ++i)
    {
        T target = std::move(array[i]);
        int j = i - 1;
        while (j >= 0 && comp(target, array[j]))
        {
            array[j + 1] = std::move(array[j]);
            --j;
        }
        array[j + 1] = std::move(target);
    }
}
} // namespace alg

namespace
{
template <typename T>
void print_list(const T *array, size_t size)
{
    if (size > 0)
    {
        std::cout << array[0];
        for (size_t i = 1; i < size; ++i)
            std::cout << " " << array[i];
    }
}

template <typename T, typename COMP>
void sort(T *array, size_t size, COMP comp, bool print)
{
    if (print)
    {
        print_list(array, size);
        alg::insert_sort(array, size, comp);
        std::cout << " -> ";
        print_list(array, size);
        std::cout << std::endl;
    }
    else
    {
        alg::insert_sort(array, size, comp);
    }
}
} // namespace

int main()
{
    constexpr bool print = true;
    auto less = [](const auto &l, const auto &r) { return l < r; };

    std::vector<int> a = {2, 9, 3, 0, 6, 1, 5, 7, 4, 8};
    sort(a.data(), a.size(), less, print);

    return 0;
}
