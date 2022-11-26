#include "MergeSort.h"

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

void merge(int nums[], int l, int m, int r)
{
    int nums1Len = m - l + 1;
    int nums2Len = r - m;
    int *nums1 = new int[nums1Len];
    int *nums2 = new int[nums2Len];
    for (int i = 0; i < nums1Len; i++)
    {
        nums1[i] = nums[l + i];
    }
    for (int i = 0; i < nums2Len; i++)
    {
        nums2[i] = nums[m + 1 + i];
    }

    int index, nums1Index, nums2Index;
    index = l;
    nums1Index = nums2Index = 0;
    while (nums1Index < nums1Len && nums2Index < nums2Len)
    {
        if (nums1[nums1Index] < nums2[nums2Index])
        {
            nums[index] = nums1[nums1Index++];
        }
        else
        {
            nums[index] = nums2[nums2Index++];
        }
        index++;
    }
    while (nums1Index < nums1Len)
    {
        nums[index++] = nums1[nums1Index++];
    }
    while (nums2Index < nums2Len)
    {
        nums[index++] = nums2[nums2Index++];
    }
}

void mergeSort(int nums[], int l, int r)
{
    if (l < r)
    {
        int m = l + ((r - l) / 2);
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
}

void sort(int nums[], int n)
{
    mergeSort(nums, 0, n - 1);
}