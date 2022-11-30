#include <iostream>

int climbStairs(int n)
{
    if (n < 3)
    {
        return n;
    }
    int pre2 = 1;
    int pre1 = 2;
    int i = 3;
    while (i++ <= n)
    {
        int temp = pre2 + pre1;
        pre2 = pre1;
        pre1 = temp;
    }
    return pre1;
}

int main()
{
    int n = 4;
    int res = climbStairs(n);
    std::cout << res << std::endl;
}