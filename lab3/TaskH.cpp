#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int main() {
    
    int n, m, x;
    int a[N], pref[N];
    
    cin >> n >> m;
    
    pref[0] = 0;
    
    for(int i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i-1] + a[i];
    
    for(int i = 1; i <= m; i++){
        cin >> x;
        int l = 1, r = n;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(pref[mid] > x) r = mid;
            else l = mid;
        }
        if(l > 1) l--;
        if(r < n) r++;
        for(; l <= r; l++){
            if(x <= pref[l] && x > pref[l-1]){
                cout << l << '\n';
                break;
            }
        }
    }
    
    return 0;
}