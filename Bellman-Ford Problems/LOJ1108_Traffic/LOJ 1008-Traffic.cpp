#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
struct Edge
{
    int u, v, weight;
};
void solve(int caseNum, int n)
{
    vector<int> busyness(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> busyness[i];
    }
    int r;
    cin >> r;
    vector<Edge> edges;
    for (int i = 0; i < r; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (u >= 1 && u <= n && v >= 1 && v <= n)
        {
            int diff = busyness[v] - busyness[u];
            int weight = diff * diff * diff;
            edges.push_back({u, v, weight});
        }
    }
    vector<int> dist(n + 1, INF);
    if (n > 0) dist[1] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (const auto& edge : edges)
        {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
            {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }
    vector<int> inNegativeCycle(n + 1, 0);
    queue<int> q_cycle;
    for (const auto& edge : edges)
    {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v])
        {
            dist[edge.v] = dist[edge.u] + edge.weight;
            if (inNegativeCycle[edge.v] == 0)
            {
                inNegativeCycle[edge.v] = 1;
                q_cycle.push(edge.v);
            }
        }
    }
    while (!q_cycle.empty())
    {
        int u = q_cycle.front();
        q_cycle.pop();

        for (const auto& edge : edges)
        {
            if (edge.u == u)
            {
                if (inNegativeCycle[edge.v] == 0)
                {
                    inNegativeCycle[edge.v] = 1;
                    q_cycle.push(edge.v);
                }
            }
        }
    }
    int q;
    cin >> q;
    cout << "Set #" << caseNum << endl;
    for (int i = 0; i < q; ++i)
    {
        int dest;
        cin >> dest;
        if (dest > n || dist[dest] == INF || inNegativeCycle[dest] == 1 || dist[dest] < 3)
        {
            cout << "?" << endl;
        }
        else
        {
            cout << dist[dest] << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, caseNum = 1;
    while (cin >> n)
    {
        solve(caseNum++, n);
    }
    return 0;
}
