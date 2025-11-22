#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indeg0;

bool topo_with_remove_to(int remove_to) {
    vector<int> indeg = indeg0;

    if (remove_to != -1) {
        if (indeg[remove_to] != 0) {
            indeg[remove_to]--;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indeg[i] == 0)
            q.push(i);
    }

    int processed = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        processed++;

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    return (processed == n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.assign(n, {});
    indeg0.assign(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        indeg0[v]++;
    }

    if (topo_with_remove_to(-1)) {
        cout << "YES\n";
        return 0;
    }

    for (int v = 0; v < n; ++v) {
        if (indeg0[v] == 0) continue;

        if (topo_with_remove_to(v)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
