#include <iostream>
#include <vector>

int dp[34][34];

std::vector<int> getRow(int rowIndex)
{
    dp[0][0] = 1;
    for (int i = 1; i <= rowIndex; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    std::vector<int> res;
    for (int i = 0; i <= rowIndex; i++)
    {
        res.push_back(dp[rowIndex][i]);
    }
    return res;
}

int main()
{
    int rowIndex = 4;
    std::vector<int> res = getRow(rowIndex);
    for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}