#include <bits/stdc++.h>
using namespace std;

int n, m, qu, l, r, x;
vector<int> g[100005];
bool used[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }

    cin >> l >> r;

    queue<int> q;

    q.push(l);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int to : g[v]){
            if(!used[to]){
                used[to] = 1;
                q.push(to);
            }
        }
    }
    if(used[r]) cout << "YES";
    else cout << "NO";


    return 0;
}
