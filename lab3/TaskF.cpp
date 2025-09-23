#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int main() {
    
    int n, m, x;
    int a[N], pref[N];
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    
    pref[0] = 0;
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];
    
    cin >> m;
    
    for(int i = 1; i <= m; i++){
        cin >> x;
        int l = 0, r = n+1;
        while(l + 1 < r){
            int mid = (l + r) / 2;
            if(a[mid] > x) r = mid;
            else l = mid;
        }
        cout << l << " " << pref[l] << "\n";
    }
    
    return 0;
}
