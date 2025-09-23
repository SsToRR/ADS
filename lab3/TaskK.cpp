#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    
    long long n, k, mn = INT_MAX;
    long long a[N], pref[N];
    
    cin >> n >> k;
    pref[0] = 0;
    
    for(int i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i-1] + a[i];
    
    int l = 1, r = n;
    
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        bool ok = 0;
        for(int i = 1; i <= n - mid + 1; i++){
            if(pref[i + mid - 1] - pref[i] >= k) ok = 1;
        }
        if(ok) r = mid;
        else l = mid;
    }
    cout << l;
    
    return 0;
}