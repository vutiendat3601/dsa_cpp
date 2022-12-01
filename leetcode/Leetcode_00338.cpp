#include <iostream>
#include <vector>

std::vector<int> countBits(int n)
{
    std::vector<int> res(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        res[i] = res[i>>1] + (i & 1);
    }
    return res;
}

int main()
{
    int n = 5;
    std::vector<int> res = countBits(n);
    for (std::vector<int>::iterator i = res.begin(); i < res.end(); i++)
    {
        std::cout << *i << " ";
    }
}