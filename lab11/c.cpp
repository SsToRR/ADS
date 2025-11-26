#include <bits/stdc++.h>
using namespace std;

struct Edge {
    long long to;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m, x, y, a, b, c;

    cin >> n >> m;
    cin >> x >> y;

    vector<vector<Edge>> g(n + 1);

    for (int i = 0; i < m; i++) {
        string type;
        long long cost;

        cin >> type >> a >> b >> c;

        if (type == "big")
            cost = 1ll * x * c;
        else if (type == "small")
            cost = 1ll * y * c;
        else
            cost = 1ll * min(x, y) * c;

        g[a].push_back({b, cost});
        g[b].push_back({a, cost});
    }

    vector<bool> used(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    pq.push({0, 1});//first - cost, second - node
    long long total = 0;

    while (!pq.empty()) {
        auto [w, v] = pq.top();
        pq.pop();

        if (used[v]) continue;
        used[v] = true;
        total += w;

        for (auto &e : g[v]) {
            if (!used[e.to]) {
                pq.push({e.w, e.to});
            }
        }
    }

    cout << total;
    return 0;
}
