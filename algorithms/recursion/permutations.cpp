/**
 * @file allPermutations.cpp
 * @author paraskhosla
 * @brief Permutations
 * @version 0.1
 * @date 2025-08-27
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <vector>

void allPermutations(std::vector<int>& a, std::vector<std::vector<int>>& perm, int idx)
{
    // a[0], a[1], a[2], ... , a[i], ..., a[n-1]
    if(idx == a.size())
    {
        perm.push_back(a);
        return ;
    }
    for(int i = idx; i < a.size(); i++)
    {
        std::swap(a[i], a[idx]);
        // a[0], a[1], a[2], ..., a[i-1], a[i+1], ..., a[n-1]
        allPermutations(a, perm, idx + 1);
        std::swap(a[i], a[idx]);
    }
}

int main()
{
    std::vector<int> a {3,1,2};
    std::vector<std::vector<int>> allPerms {};
    allPermutations(a, allPerms, 0);
    for(auto perm : allPerms)
    {
        for(auto ele : perm)
        {
            std::cout << ele << ",";
        }
        std::cout << '\n';
    }
    return 0;
}