/**
 * @file 39_combination_sum.cpp
 * @author paraskhosla
 * @brief 39. Combination Sum
 * @version 0.1
 * @date 2025-08-12
 */

#include <iostream>
#include <vector>

/**
 * @cite https://leetcode.com/problems/combination-sum/description/

39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return
a list of all unique combinations of candidates where the chosen numbers sum to target.
You may return the combinations in any order. The same number may be chosen from candidates
an unlimited number of times. Two combinations are unique if the frequency of at least one 
of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up
to target is less than 150 combinations for the given input.

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40

*/

/*
candidates = [2,3,4,7]; target = 7
-> [ [7], [3,4], [2,2,3] ]
*/

void combinationSumHelper(const std::vector<int>& candidates, int32_t target, std::vector<std::vector<int>>& combinations, std::vector<int> collected)
{
    if(target == 0)
    {
        // if collected list isn't already there
        // only then add it to combinations list
        sort(collected.begin(), collected.end());
        for(auto collection : combinations)
        {
            if(collection == collected)
            {
                return ;
            }
        }
        combinations.push_back(collected);
        return ;
    }
    else if(target < 0)
    {
        return ;
    }
    for(auto element : candidates)
    {
        collected.push_back(element);
        combinationSumHelper(candidates, target - element, combinations, collected);
        collected.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, const int32_t& target)
{
    std::vector<std::vector<int>> combinations {};
    std::vector<int> collected {};
    combinationSumHelper(candidates, target, combinations, collected);
    return combinations;
}

int main()
{
    std::vector<int> candidates {2,3,4,7};
    const int32_t target = 7;
    std::vector<std::vector<int>> combinations = combinationSum(candidates, target);
    for(auto combination : combinations)
    {
        for(auto element : combination)
        {
            std::cout << element << " ";
        }
        std::cout << '\n';
    }
    return 0;
}