/**
 * @file allSubsequences.cpp
 * @author paraskhosla
 * @brief Subsequences / Subsets / Powerset
 * @version 0.1
 * @date 2025-08-27
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <iostream>
#include <vector>

void powersetHelper(const std::vector<int>& a, std::vector<std::vector<int>>& P, std::vector<int> S, int idx)
{
    if(idx == a.size())
    {
        P.push_back(S);
        return ;
    }
    // not pick
    powersetHelper(a, P, S, idx + 1);
    // pick
    S.push_back(a[idx]);
    powersetHelper(a, P, S, idx + 1);
    S.pop_back();
}

std::vector<std::vector<int>> powerset(const std::vector<int>& a)
{
    std::vector<std::vector<int>> P {};
    std::vector<int> s;
    powersetHelper(a, P, s, 0);
    return P;
}

int main()
{
    std::vector<int> a {3,1,2};
    auto P = powerset(a);
    for(auto S : P)
    {
        if(S.size() == 0)
        {
            std::cout << "{}\n";
            continue;
        }
        for(auto s : S)
        {
            std::cout << s << ',';
        }
        std::cout << '\n';
    }
    return 0;
}