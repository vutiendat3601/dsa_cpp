#include <iostream>

int a[101];
int n;
int stop = 0;

void printResult()
{
    for (int i = 1; i <= n; i++)
    {
        std::cout << a[i];
    }
    std::cout << std::endl;
}

void backtrack(int iTh)
{

    for (int i = 0; i <= 1; i++)
    {
        if (stop)
        {
            return;
        }
        a[iTh] = i;
        if (iTh == n)
        {
            printResult();
            stop = 1;
        }
        else
        {
            backtrack(iTh + 1);
        }
    }
}

int main()
{
    n = 3;
    backtrack(1);
}