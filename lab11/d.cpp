#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    const int INF = 1e9;

    vector<int> dist(n, INF);
    vector<bool> used(n, false);

    dist[0] = 0;
    long long total = 0;

    for (int it = 0; it < n; it++) {
        int v = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] && (v == -1 || dist[i] < dist[v]))
                v = i;
        }

        used[v] = true;
        total += dist[v];

        for (int u = 0; u < n; u++) {
            if (!used[u] && a[v][u] < dist[u]) {
                dist[u] = a[v][u];
            }
        }
    }

    cout << total;
    return 0;
}
