#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int main() {
    
    long long n, f;
    long long a[N];
    
    cin >> n >> f;
    
    for(int i = 1; i <= n; i++) cin >> a[i];

    long long l = 0, r = INT_MAX;
    
    while(l + 1 < r){
        long long mid = (l + r) / 2;
        long long sum = 0;
        for(int i = 1; i <= n; i++){
            sum += (a[i] + mid - 1) / mid;
        }
        if(sum > f) l = mid;
        else r = mid;
    }
    cout << r;
    
    return 0;
}