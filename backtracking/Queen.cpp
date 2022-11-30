#include <iostream>

int queens[20];

int n;

void put(int row)
{
    for (int col = 0; col < n; col++)
    {
        int possible = 1;
        for (int i = 0; i < row; i++)
        {
            if (queens[i] == col || abs(col - queens[i]) == row - i)
            {
                possible = 0;
                break;
            }
        }
        if (possible)
        {
            queens[row] = col;
            if (row == n - 1)
            {
                for (int i = 0; i < n; i++)
                {
                    std::cout << queens[i] << " ";
                }
                std::cout << std::endl;
            }
            else
            {
                put(row + 1);
            }
        }
    }
}

int main()
{
    n = 4;
    put(0);
}