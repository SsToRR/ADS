
#include <bits/stdc++.h>
using namespace std;

    int n, m, ans;
    vector<int> g[100005];
    int sons[100005];
    bool used[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;

    for(int i = 1, l, r; i <= m; i++){
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(r);
        sons[l]++;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            queue<int> q;
            q.push(i);
            used[i] = 1;
            ans++;
            while(!q.empty()){
                int v = q.front();
                q.pop();

                for(int to : g[v]){
                    if(!used[to]){
                        if(sons[v] < sons[to]) ans++;
                        used[to] = 1;
                        q.push(to);
                    }
                }
            }
        }
    }
    cout << ans;

}
