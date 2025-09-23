#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int main() {
    
    int n, m, x;
    int a[N], pref[N];
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    cin >> m;
    
    int l = 1, r = n;
    
    while(l + 1 < r){
        int mid = (l + r) / 2;
        if(a[mid] > m) r = mid;
        else l = mid;
    }
    if(a[l] == m || a[r] == m) cout << "Yes";
    else cout << "No";

    
    
    return 0;
}