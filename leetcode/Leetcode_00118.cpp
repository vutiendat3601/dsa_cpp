#include <iostream>
#include <vector>

const int MAX_N = 30;

std::vector<std::vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> dp(numRows);
    for (int i = 0; i < numRows; i++)
    {
        std::vector<int> res(i + 1, 1);
        dp[i] = res;
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp;
}
int main()
{
    int n = 10;
    std::vector<std::vector<int>> res = generate(n);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}