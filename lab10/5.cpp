#include <bits/stdc++.h>
using namespace std;

int n, m, qu, l, r, x;
vector<int> g[5005];
vector<int> type(5005, 0);
vector<int> path(40005);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> qu;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= qu; i++){
        int y, z;
        cin >> x >> y >> z;

        bool ok1, ok2, ok3;
        ok1 = ok2 = ok3 = 0;
        for(int to : g[x]){
            if(to == y) ok1 = 1;
            if(to == z) ok2 = 1;
        } for(int to : g[y]){
            if(to == z) ok3 = 1;
        }
        if(ok1 && ok2 && ok3) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}
