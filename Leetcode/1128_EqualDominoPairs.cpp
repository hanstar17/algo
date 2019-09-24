// https://leetcode.com/problems/add-to-array-form-of-integer/

#include <vector>
#include <unordered_map>

int NumEqualDominoPairs(std::vector<std::vector<int>>& dominoes) {
    std::unordered_map<int, int> counter;
    for (auto &domino : dominoes) {
        if (domino[0] > domino[1])
            std::swap(domino[0], domino[1]);
        ++counter[domino[0] * 10 + domino[1]];
    }
    int num = 0;
    for (const auto &count : counter)
        num += (count.second * (count.second - 1)) / 2;
    
    return num;
}

#include <iostream>
int main() {
    std::vector<std::vector<int>> a = {{1,2},{2,1},{3,4},{5,6}};
    std::cout << NumEqualDominoPairs(a) << std::endl;
    return 0;
}