#include <iostream>
#include <vector>

int rob(std::vector<int> &nums)
{
    int oldRes = 0;
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int temp = res;
        res = oldRes + nums[i] > res ? oldRes + nums[i] : res;
        oldRes = temp;
    }
    return res;
}

int main()
{
    std::vector<int> nums{2, 7, 9, 3, 1};
    int res = rob(nums);
    std::cout << res << std::endl;
}