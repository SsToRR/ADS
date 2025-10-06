#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m, x;
    map<int, int> mp;
    vector<int> v;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        mp[x]++;
    }
    
    for(int i = 1; i <= m; i++){
        cin >> x;
        if(mp[x]){
            v.push_back(x);
            mp[x]--;
        }
    }
    sort(v.begin(), v.end());
    for(int i : v) cout << i << ' ';
    
    return 0;
}