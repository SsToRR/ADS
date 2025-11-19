
#include <bits/stdc++.h>
using namespace std;

    int n, m, ans;
    char c[101][101];
    bool used[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] == '1' && !used[i][j]){
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()){
                    auto [l, r] = q.front();
                    q.pop();
                    if(!used[l + 1][r] && c[l + 1][r] == '1'){
                        q.push({l + 1, r});
                        used[l + 1][r] = 1;
                    }
                    if(!used[l - 1][r] && c[l - 1][r] == '1'){
                        q.push({l - 1, r});
                        used[l - 1][r] = 1;
                    }
                    if(!used[l][r + 1] && c[l][r + 1] == '1'){
                        q.push({l, r + 1});
                        used[l][r + 1] = 1;
                    }
                    if(!used[l][r - 1] && c[l][r - 1] == '1'){
                        q.push({l, r - 1});
                        used[l][r - 1] = 1;
                    }
                }
            }
        }
    }
    cout << ans;

}
