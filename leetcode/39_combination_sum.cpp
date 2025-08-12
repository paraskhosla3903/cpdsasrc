/**
 * @file 39_combination_sum.cpp
 * @author paraskhosla
 * @brief 39. Combination Sum
 * @version 0.1
 * @date 2025-08-12
 */

#include <iostream>
#include <vector>

/*
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

void combinationSumHelper(const std::vector<int>& candidates, int32_t target, std::vector<std::vector<int>>& combinations, std::vector<int>& collected)
{
    if(target == 0)
    {
        // if collected list isn't already there
        // only then add it to combinations list
        // sort(collected.begin(), collected.end());
        /**
         * @note if collected is passed a reference, then we will run into problems of consistency
         * between the tracked target and the corresponding collection, here, we pass collected = [3,2]
         * on sorting, this becomes [2,3], since further additions of element = 2, would have made it work
         * for example [3,2,2], we check if it is already accounted for in combinations. We see that it is
         * and finally return from the sub-rountine call, and perform a pop_back() on sort([3,2,2]), which
         * happens to be pop_back([2,2,3]) = [2,2]. At this stage the expected state was [3,2]. So, pushing
         * element = 4 would have made it equal to target, but the state and target have inconsistencies now.
         * Therefore, the collected state must be passed as a value and not as a reference.
         */
// * thread #1, queue = 'com.apple.main-thread', stop reason = step over
// frame #0: 0x0000000100000680 a.out`combinationSumHelper(candidates=size=4, target=4, combinations=size=1, collected=size=2) at 39_combination_sum.cpp:60:30
// 57       for(auto element : candidates)
// 58       {
// 59           collected.push_back(element);
// -> 60           combinationSumHelper(candidates, target - element, combinations, collected);
// 61           collected.pop_back();
// 62       }
// 63   }
// Target 0: (a.out) stopped.
// (lldb) p collected
// (std::vector<int> &) size=2: {
// [0] = 3
// [1] = 2
// }
// (lldb) n
// Process 78821 stopped
// * thread #1, queue = 'com.apple.main-thread', stop reason = step over
// frame #0: 0x000000010000069c a.out`combinationSumHelper(candidates=size=4, target=4, combinations=size=1, collected=size=2) at 39_combination_sum.cpp:61:9
// 58       {
// 59           collected.push_back(element);
// 60           combinationSumHelper(candidates, target - element, combinations, collected);
// -> 61           collected.pop_back();
// 62       }
// 63   }
// 64  
// Target 0: (a.out) stopped.
// (lldb) 
// Process 78821 stopped
// * thread #1, queue = 'com.apple.main-thread', stop reason = step over
// frame #0: 0x00000001000006a4 a.out`combinationSumHelper(candidates=size=4, target=4, combinations=size=1, collected=size=1) at 39_combination_sum.cpp:57:5
// 54       {
// 55           return ;
// 56       }
// -> 57       for(auto element : candidates)
// 58       {
// 59           collected.push_back(element);
// 60           combinationSumHelper(candidates, target - element, combinations, collected);
// Target 0: (a.out) stopped.
// (lldb) p collected
// (std::vector<int> &) size=1: {
// [0] = 2
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