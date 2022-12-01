#include <iostream>
#include <vector>

int maxProfit(std::vector<int> &prices)
{
    int res = 0;
    int boughtDay = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[boughtDay])
        {
            res = res > prices[i] - prices[boughtDay] ? res : prices[i] - prices[boughtDay];
        }
        else
        {
            boughtDay = i;
        }
    }
    return res;
}

int main()
{
    std::vector<int> prices = {7, 6, 4, 3, 1};
    int res = maxProfit(prices);
    std::cout << res << std::endl;
}