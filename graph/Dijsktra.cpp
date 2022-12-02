#include <iostream>
#include <queue>
#include <limits>

using ll = long long;

/**
 * index of g -> vertex
 * value of g -> { pair.first -> adjacent vertex, pair.second -> weight }
 */
std::vector<std::pair<int, ll>> g[1001];

/**
 * m -> number of vertices
 * n -> number of edges
 */
int m, n;

void input()
{
    freopen("./input/dijsktra.txt", "r", stdin);
    std::cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        std::cin >> x >> y >> w;
        g[x].push_back({y, w});
    }
}

const ll INF = LONG_LONG_MAX;
void dijsktra(int beginVertex)
{
    std::vector<ll> distances(m + 1, INF);
    distances[beginVertex] = 0;
    std::priority_queue<std::pair<ll, int>,
                        std::vector<std::pair<ll, int>>,
                        std::greater_equal<std::pair<ll, int>>>
        pq;
    pq.push({0, beginVertex});
    while (!pq.empty())
    {
        std::pair<ll, int> top = pq.top();
        pq.pop();
        ll d = top.first;
        int v = top.second;
        if (d <= distances[v])
        {
            for (std::pair<int, ll> x : g[v])
            {
                if (distances[x.first] > distances[v] + x.second)
                {
                    distances[x.first] = distances[v] + x.second;
                    pq.push({distances[x.first], x.first});
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        std::cout << distances[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    input();
    dijsktra(1);
    std::cout << "END PROGRAM." << std::endl;
}