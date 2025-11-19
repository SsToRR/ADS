#include <bits/stdc++.h>
using namespace std;

int n, m, query, l, r;
vector<int> g[5005];
vector<int> type(5005, 0);
vector<int> path(40005);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> query;

    for(int i = 1; i <= m; i++){
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    for(int i = 1; i <= query; i++){
        cin >> l >> r;
        if(l == 1) type[r] = 1;
        else {
            queue<int> q;
            vector<int> d(n + 2, -1);

            q.push(r);
            d[r] = 0;
            int ans = -1;

            while(!q.empty()){
                int v = q.front();
                q.pop();
                if(type[v] == 1){
                    ans = d[v];
                    break;
                }

                for(int to : g[v]){
                    if(d[to] == -1){
                        d[to] = d[v] + 1;
                        q.push(to);
                    }
                }
            }
            cout << ans << '\n';
        }

    }

    return 0;
}
