#include <iostream>
#include <vector>
#include <stack>

int m, n; // m vertices n edges
int visited[1001];
std::vector<int> edges[1001];

void dfs(int i)
{
    std::stack<int> s;
    s.push(i);
    visited[i] = 1;
    while (!s.empty())
    {
        int x = s.top();
        std::cout << x << " ";
        s.pop();
        for (int k : edges[x])
        {
            if (!visited[k])
            {
                s.push(k);
                visited[k] = 1;
            }
        }
    }
}

int main()
{
    freopen("./input/edges.txt", "r", stdin);
    std::cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
        std::cout << i << ": ";
        for (int x : edges[i])
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    dfs(1);
}