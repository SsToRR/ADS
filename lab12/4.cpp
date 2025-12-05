
#include <bits/stdc++.h>
using namespace std;

const long long INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 2), y(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    vector<long long> dist(n + 2, INF);
    vector<bool> used(n, false);

    dist[1] = 0;

    for (int it = 1; it <= n; it++) {
        int v = -1;
        for (int i = 1; i <= n; i++) {
            if (!used[i] && (v == -1 || dist[i] < dist[v])) {
                v = i;
            }
        }

        if (v == -1 || dist[v] == INF) break;

        used[v] = true;

        for (int to = 1; to <= n; to++) {
            if (used[to] || to == v) continue;
            long long w = abs(x[v] - x[to]) + abs(y[v] - y[to]);
            long long mx = max(dist[v], w);
            if (mx < dist[to]) {
                dist[to] = mx;
            }
        }
    }

    if(dist[n] >= INT_MAX) cout << 0;
    else cout << dist[n];

    return 0;
}
