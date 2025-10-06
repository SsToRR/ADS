#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, a[200005];
    int mn = INT_MAX, id1, id2;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + 1 + n);
    
    for(int i = 2; i <= n; i++) mn = min(mn, abs(a[i] - a[i-1]));
    
    for(int i = 2; i <= n; i++){
        if(abs(a[i] - a[i-1]) == mn) cout << a[i-1] << ' ' << a[i] << ' ';
    }
    
    return 0;
}