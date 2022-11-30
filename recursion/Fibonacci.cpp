#include <iostream>

const int MAX_N = 100;

int dp[MAX_N + 1];

long long fibo(int n)
{
    if (n == 0)
    {
        return dp[n] = 0;
    }
    if (n == 1 || n == 2)
    {
        return dp[n] = 1;
    }
    return dp[n] == 0 ? dp[n] = fibo(n - 2) + fibo(n - 1) : dp[n];
}

int main()
{
    long long res = fibo(10);
    std::cout << res << std::endl;
}