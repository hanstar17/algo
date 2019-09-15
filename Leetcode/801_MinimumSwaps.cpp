// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/

#include <vector>

int MinSwap(const std::vector<int> &as, const std::vector<int> &bs)
{
    // answer when i = 0
    int minSwap = 1;
    int minNoswap = 0;

    const int size = as.size();
    for (int i = 1; i < size; ++i)
    {
        const int a = as[i], pa = as[i-1];
        const int b = bs[i], pb = bs[i-1];

        int swap = -1;
        int noswap = -1;
        if (pa < a && pb < b) {
            if (minSwap >= 0)
                swap = minSwap + 1;
            if (minNoswap >= 0)
                noswap = minNoswap;
        }
        
        if (pb < a && pa < b) {
            if (minSwap >= 0)
                noswap = noswap < 0 ? minSwap : std::min(noswap, minSwap);
            if (minNoswap >= 0)
                swap = swap < 0 ? minNoswap + 1 : std::min(swap, minNoswap + 1);
        }
        minNoswap = noswap;
        minSwap = swap;
    }
    if (minNoswap < 0)
        return minSwap;
    if (minSwap < 0)
        return minNoswap;
    return std::min(minNoswap, minSwap);
}

#include <iostream>
int main()
{
    int a = MinSwap({0,3,5,8,9}, {2,1,4,6,9});
    std::cout << a << std::endl;
    return 0;
}