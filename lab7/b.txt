#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m, x;
    vector<int> v;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> x, v.push_back(x);
    
    cin >> m;
    
    for(int i = 1; i <= m; i++) cin >> x, v.push_back(x);
    
    sort(v.begin(), v.end());
    
    for(int i : v) cout << i << ' ';
    
    return 0;
}