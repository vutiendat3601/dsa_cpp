#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>

int coinChange(std::vector<int> &coins, int amount)
{
    int dp[amount + 1];
    for (int i = 1; i <= amount; i++)
    {
        dp[i] = amount + 1;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0)
            {
                dp[i] = std::min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount] != amount + 1 ? dp[amount] : -1;
}
int main()
{
    std::vector<int> coins{186, 419, 83, 408};
    int amount = 6249;
    int res = coinChange(coins, amount);
    std::cout << res << std::endl;
}