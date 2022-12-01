#include <iostream>
#include <vector>
#include <math.h>
int rob(std::vector<int> &nums, int left, int right)
{
    int oldRes = 0;
    int res = left < nums.size() ? nums[left] : oldRes;
    for (int i = left + 1; i <= right; i++)
    {
        int temp = res;
        res = res > oldRes + nums[i] ? res : oldRes + nums[i];
        oldRes = temp;
    }
    return res;
}

int rob(std::vector<int> &nums)
{
    int robFirst = rob(nums, 0, nums.size() - 2);
    int notRobFirst = rob(nums, 1, nums.size() - 1);
    return std::max(robFirst, notRobFirst);
}

int main()
{
    std::vector nums{1, 2, 3, 4, 5, 6};
    int res = rob(nums);
    std::cout << res << std::endl;
}