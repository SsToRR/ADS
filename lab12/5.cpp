
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    long long u, v, w;
};

const long long INF = 1e18 + 3;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Edge> edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long w;
            cin >> w;
            if (w != 100000) {
                edges.push_back({i, j, w});
            }
        }
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int x = -1;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    int y = x;
    for (int i = 0; i < n; ++i) {
        y = parent[y];
    }

    vector<int> cycle;
    int cur = y;
    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != y);
    cycle.push_back(y);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    cout << cycle.size() << "\n";
    for (int v : cycle) {
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}
