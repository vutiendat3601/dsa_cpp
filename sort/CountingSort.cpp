#include <iostream>

void sort(int nums[], int n)
{
    int cnts[101] = {0};
    // for (int i =0;i<)
    for (int i = 0; i < n; i++)
    {
        cnts[nums[i]]++;
    }
    for (int i = 1; i <= 100; i++)
    {
        cnts[i] += cnts[i - 1];
    }
    int output[n];
    for (int i = 0; i < n; i++)
    {
        output[cnts[nums[i]] - 1] = nums[i];
        cnts[nums[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        nums[i]=output[i];
    }
}

int main()
{
    int nums[] = {2, 1, 4, 6, 5, 8, 9, 10};
    int n = 8;
    sort(nums, n);
    std::cout << "END PROGRAM." << std::endl;
}