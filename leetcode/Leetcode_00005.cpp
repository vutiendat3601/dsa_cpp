#include <iostream>
#include <string>
#include <cstring>

std::string longestPalindrome(std::string s)
{
    int n = s.size();
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 1;
        }
    }
    std::string res;
    int left = 0;
    int right = 0;
    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i + j < n; i++)
        {
            dp[i][i + j] = 0;
            if (s[i] == s[i + j])
            {
                dp[i][i + j] = dp[i + 1][i + j - 1] != 0;
                if (dp[i][i + j] && right - left < j)
                {
                    left = i;
                    right = i + j;
                }
            }
        }
    }
    return s.substr(left, right - left + 1);
}

int main()
{
    std::string s = "1234555655541";
    s = longestPalindrome(s);
    std::cout << s << std::endl;
}