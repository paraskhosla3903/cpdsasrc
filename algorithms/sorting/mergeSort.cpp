/**
 * @file mergeSort.cpp
 * @author paraskhosla
 * @brief Merge Sort Algorithm
 * @version 0.1
 * @date 2025-08-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>

void merge(std::vector<int>& a, size_t start, size_t end)
{
    std::vector<int> x (end - start + 1);
    size_t mid = start + (end - start) / 2;
    // a[start] ... a[mid]
    // a[mid+1] ... a[end]
    int i = start, j = mid + 1, k = 0;
    while(i <= mid && j <= end)
    {
        if(a[i] < a[j]) x[k++] = a[i++];
        else x[k++] = a[j++];
    }
    while(i <= mid)
    {
        x[k++] = a[i++];
    }
    while(j <= end)
    {
        x[k++] = a[j++];
    }
    i = start;
    for(auto y : x)
    {
        a[i++] = y;
    }
}

void mergeSortHelper(std::vector<int>& a, size_t start, size_t end)
{
    if(start >= end)
    {
        return ;
    }
    size_t mid = start + (end - start) / 2;
    mergeSortHelper(a, start, mid);
    mergeSortHelper(a, mid + 1, end);
    merge(a, start, end);
}

void mergeSort(std::vector<int>& a)
{
    size_t n = a.size();
    mergeSortHelper(a, 0, n-1);
}

int main()
{
    std::vector a {1, 1, 4, 2, 6, 2, 1, 6, 7, 1};
    mergeSort(a);
    for(const auto& i : a)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
}