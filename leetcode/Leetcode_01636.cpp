#include <iostream>
#include <vector>
#include <stack>
#include <queue>

struct cmp
{
    constexpr bool operator()(
        std::pair<int, int> const &a,
        std::pair<int, int> const &b)
        const noexcept
    {
        return a.first >= b.first;
    }
};

std::vector<int> frequencySort(std::vector<int> &nums)
{
    const int MAX_N = 100;
    int cnts[MAX_N * 2 + 1] = {0};
    for (int i : nums)
    {
        cnts[i + MAX_N]++;
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, ::cmp> pq;
    for (int i = -MAX_N; i <= MAX_N; i++)
    {
        if (cnts[i + MAX_N])
        {
            pq.push(std::make_pair(cnts[i + MAX_N], i));
        }
    }

    std::vector<int> res;
    while (!pq.empty())
    {
        std::pair<int, int> temp = pq.top();
        pq.pop();
        for (int i = 0; i < temp.first; i++)
        {
            res.push_back(temp.second);
        }
    }
    return res;
}

int main()
{
    std::vector<int> nums{2, 3, 1, 3, 2};
    nums = frequencySort(nums);
    for (int i : nums)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}