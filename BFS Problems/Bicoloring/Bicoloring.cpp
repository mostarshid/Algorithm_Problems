#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<int>& color, const vector<vector<int>>& adj) {
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

bool isBicolorable(int n, const vector<vector<int>>& adj) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bfs(i, color, adj)) return false;
        }
    }
    return true;
}

int main() {
    int n, e;
    while (cin >> n && n != 0) {
        cin >> e;
        vector<vector<int>> adj(n);

        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (isBicolorable(n, adj))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }
    return 0;
}

