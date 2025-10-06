#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, m;
    int a[101][101];
    vector<int> v;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        v.clear();
        for(int j = 1; j <= n; j++){
            v.push_back(a[j][i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int j = 1; j <= n; j++){
            a[j][i] = v[j-1];
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}