#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, l, r, c;
    long long ans = 0;

    cin >> n >> m;
    vector<pair<int, int>> st[n + 5], fn[n + 5];

    for(int i = 1; i <= m; i++){
        cin >> l >> r >> c;
        st[l].push_back({r, c});
        fn[r].push_back({l, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 1; i < n; i++){
        for(auto p : st[i]){
            pq.push({p.second, p.first});
        }
        while(!pq.empty() && pq.top().second <= i) pq.pop();

        if(pq.empty()) {
            cout << "0\n";
            return 0;
        }

        ans += pq.top().first;
    }
    cout << ans;

return 0;
}
