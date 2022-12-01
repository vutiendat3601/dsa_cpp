#include <iostream>

int getMaximumGenerated(int n)
{
    if (n < 2)
    {
        return n;
    }
    int max = 0;
    int nums[n + 1];
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2) // odd
        {
            nums[i] = nums[i / 2] + nums[i / 2 + 1];
        }
        else // even
        {
            nums[i] = nums[i / 2];
        }
        max = max > nums[i] ? max : nums[i];
    }
    return max;
}

int main()
{
    int n = 15;
    int res = getMaximumGenerated(n);
    std::cout << res << std::endl;
}