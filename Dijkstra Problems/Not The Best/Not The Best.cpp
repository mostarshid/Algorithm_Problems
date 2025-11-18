#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int to;
    int weight;
};

int solve() {
    int N, R;
    if (!(cin >> N >> R)) return -1;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < R; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist1(N + 1, INF);
    vector<int> dist2(N + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist2[u]) {
            continue;
        }
        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;
            int d_new = d + w;

            if (d_new < dist1[v]) {
                dist2[v] = dist1[v];
                dist1[v] = d_new;

                pq.push({dist1[v], v});

                if (dist2[v] != INF) {
                    pq.push({dist2[v], v});
                }
            }
            else if (d_new > dist1[v] && d_new < dist2[v]) {
                dist2[v] = d_new;
                pq.push({dist2[v], v});
            }
        }
    }
    return dist2[N];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    for (int i = 1; i <= T; ++i) {
        int result = solve();
        if (result != -1) {
            cout << "Case " << i << ": " << result << "\n";
        }
    }

    return 0;
}
