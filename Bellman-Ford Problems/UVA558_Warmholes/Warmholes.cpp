#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Wormhole {
    int start;
    int end;
    int time;
};

int bellman_ford(int N, int M, const vector<Wormhole>& wormholes) {
    vector<ll> dist(N, INF);
    dist[0] = 0;
    for (int i = 0; i < N - 1; ++i) {
        bool relaxed_in_pass = false;
        for (const auto& w : wormholes) {
            if (dist[w.start] != INF) {
                if (dist[w.start] + w.time < dist[w.end]) {
                    dist[w.end] = dist[w.start] + w.time;
                    relaxed_in_pass = true;
                }
            }
        }
        if (!relaxed_in_pass) break;
    }
    for (const auto& w : wormholes) {
        if (dist[w.start] != INF) {
            if (dist[w.start] + w.time < dist[w.end]) {
                return 1;
            }
        }
    }
    return 0;
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    vector<Wormhole> wormholes;
    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        wormholes.push_back({x, y, t});
    }
    if (bellman_ford(N, M, wormholes) == 1) {
        cout << "possible" << endl;
    } else {
        cout << "not possible" << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    if (!(cin >> C)) return 0;
    while (C--) {
        solve();
    }

    return 0;
}
