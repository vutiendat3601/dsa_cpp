#include <iostream>

long long fibo(int n)
{
    long long pre2 = 0;
    long long pre1 = 1;
    if (n == 0)
    {
        return pre2;
    }
    if (n == 1)
    {
        return pre1;
    }
    for (int i = 2; i <= n; i++)
    {
        int temp = pre2 + pre1;
        pre2 = pre1;
        pre1 = temp;
    }
    return pre1;
}

int main()
{
    long long res = fibo(16);
    std::cout << res <<std::endl;
}