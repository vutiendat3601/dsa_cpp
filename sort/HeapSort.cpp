#include <iostream>

void printArray(int[], int);

void swap(int nums[], int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void heapify(int nums[], int n, int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && nums[l] > nums[largest])
    {
        largest = l;
    }
    if (r < n && nums[r] > nums[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(nums, i, largest);
        heapify(nums, n, largest);
    }
}

void heapSort(int nums[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(nums, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums, 0, i);
        heapify(nums, i, 0);
    }
}

int main()
{
    int nums[]{9, 8, 1, 2, 3, 7, 6, 5, 4, 10};
    int n = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, n);
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
