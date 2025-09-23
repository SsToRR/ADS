#include <bits/stdc++.h>
using namespace std;

int main() {
    
    //дано что i % 2 == 1 - справа налево
    // i % 2 == 0 слева направо
    
    //1. map<int, pair<int, int>> -> first index of number, pair - pos
    //2. Binary search
    
    int n, m, t, x;
    int test[10005];
    map<int, pair<int, int>> mp; //for position
    map<int, bool> ok; //встречалось ли это число?
    
    cin >> t;
    
    for(int i = 1; i <= t; i++) cin >> test[i];

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
            mp[x] = {i - 1, j - 1};
            ok[x] = true;
        }
    }
    
    for(int i = 1; i <= t; i++){
        if(ok[test[i]] == 1) cout << mp[test[i]].first << ' ' << mp[test[i]].second << endl;
        else cout << -1 << endl;
    }
    
    
    return 0;
}