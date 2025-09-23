#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long n, k, a[100005], sum = 0, mx = INT_MIN;
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i], sum += a[i], mx = max(mx, a[i]);
    }
    
    long long l = mx, r = sum;
    
    while(l < r){
        
        long long mid = (l + r) / 2;
        long long cur_sum = 0, total_block = 0;
        
        for(int i = 1; i <= n; i++){
            if(cur_sum + a[i] <= mid){
                cur_sum += a[i];
            } else {
                total_block++;
                cur_sum = a[i];
            }
        }
        total_block++;
        if(total_block > k) l = mid + 1;
        else r = mid;
        
    }
    cout << r;
    
    /*
    10 3
    3 4 2 1 3 4 5 2 2 3
    
    ans = [5, 29]
    
    (5 + 29) / 2 = 17
    (5 + 17) / 2 = 11
    
    3 + 4 + 2 + 1 + 3 + 4
    5 + 2 + 2 + 3
    #
    
    3 + 4 + 2 + 1 -> 10
    1 + 3 + 4 -> 8
    5 + 2 + 2 -> 9
    3 - no place
    
    (11 + 17) / 2 = 14
    3 + 4 + 2 + 1 + 3
    4 + 5 + 2 + 2
    3
    
    */
    
    
    
    return 0;
}