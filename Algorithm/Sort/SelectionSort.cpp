#include <cstddef>
#include <algorithm>

namespace alg
{
template <typename T, typename COMP>
void select_sort(T *array, size_t size, COMP comp)
{
    for (size_t i = 0; i < size; ++i)
    {
        size_t best = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (comp(array[j], array[best]))
                best = j;
        }
        if (i != best)
            std::swap(array[i], array[best]);
    }
}
} // namespace alg

#include <iostream>
#include <vector>

namespace
{
template <typename T>
void print_array(const T *array, size_t size)
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
        print_array(array, size);
        alg::select_sort(array, size, comp);
        std::cout << " -> ";
        print_array(array, size);
        std::cout << std::endl;
    }
    else
    {
        alg::select_sort(array, size, comp);
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
