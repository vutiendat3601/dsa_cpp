#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex)
{
    std::vector<int> res(rowIndex + 1);
    res[0] = res[rowIndex] = 1;
    int left = 1;
    int right = rowIndex - 1;
    long long temp = 1;
    int numerator = rowIndex; // numerator -> tuSo
    int denominator = 1;      // denominator -> mauSo
    while (left <= right)
    {
        temp *= numerator;
        temp /= denominator;
        res[left] = res[right] = temp;
        numerator--;
        denominator++;
        left++;
        right--;
    }
    return res;
}

int main()
{
    // std::cout << factorial(5) << std::endl;
    int rowIndex = 33;
    std::vector<int> res = getRow(rowIndex);
    for (std::vector<int>::iterator i = res.begin(); i != res.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}