#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int k = 0; k < m; ++k) {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        indeg[j]++;
    }

    queue<int> q;
    for (int v = 1; v <= n; ++v)
        if (indeg[v] == 0)
            q.push(v);

    vector<int> order;
    order.reserve(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    if ((int)order.size() != n) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << order[i];
        }
        cout << '\n';
    }

    return 0;
}
