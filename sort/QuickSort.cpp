#include <iostream>
#include "QuickSort.h"

void printArray(int[], int);

int main()
{
    int nums[]{9, 1, 3, 2, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    sort(nums, n);
    printArray(nums, n);
}

void printArray(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

void quickSort(int nums[], int l, int r)
{
    if (l < r)
    {
        int i = l - 1;
        for (int j = l; j < r; j++)
        {
            if (nums[j] < nums[r])
            {
                i++;
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
        i++;
        int temp = nums[r];
        nums[r] = nums[i];
        nums[i] = temp;
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
}

void sort(int nums[], int n)
{
    quickSort(nums, 0, n - 1);
}
