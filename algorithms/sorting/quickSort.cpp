/**
 * @file quickSort.cpp
 * @author paraskhosla
 * @brief Quick Sort Algorithm
 * @version 0.1
 * @date 2025-08-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <vector>

size_t partition(std::vector<int>& a, size_t left, size_t right)
{
    int pivot = a[left]; // choose first element of the array in consideration as pivot
    int i = left + 1, j = right;
    while(i < j)
    {
        while(a[i] <= pivot && i <= right)
        {
            i++;
        }
        while(a[j] > pivot && j >= left)
        {
            j--;
        }
        if(i < j)
        {
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[left], a[i]);
    return i;
}

void quickSortHelper(std::vector<int>& a, size_t left, size_t right)
{
    if(left >= right)
    {
        return ;
    }
    size_t partitionIndex = partition(a, left, right);
    quickSortHelper(a, left, partitionIndex - 1);
    quickSortHelper(a, partitionIndex + 1, right);
}

void quickSort(std::vector<int>& a)
{
    size_t n = a.size();
    quickSortHelper(a, 0, n-1);
}

int main()
{
    std::vector a {6, 3, 1, 7, 3, 9};
    quickSort(a);
    for(const auto& i : a)
    {
        std::cout << i << " ";
    }
    std::cout << '\n';
    return 0;
}