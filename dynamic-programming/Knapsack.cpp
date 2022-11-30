#include <iostream>
#include <algorithm>

const int MAX_N = 101;

int dp[MAX_N][MAX_N] = {0};
int weights[MAX_N];
int values[MAX_N];

void input(int &n, int &s)
{
    std::freopen("./input/knapsack.txt", "r", stdin);
    std::cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> weights[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> values[i];
    }
}

int knapsack(int n, int s)
{
    for (int i = 1; i <= n; i++)
    { // iTh thing
        for (int j = 1; j <= s; j++)
        { // iTh bag
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i])
            {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    return dp[n][s];
}

int main()
{
    int n = 0;
    int s = 0;
    input(n, s);
    int res = knapsack(n, s);
    std::cout << res << std::endl;
}