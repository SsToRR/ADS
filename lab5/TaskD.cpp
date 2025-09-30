#include <bits/stdc++.h>
using namespace std;

int main() {
    
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    
    long long n, m, x, cnt = 0;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }
    
    while(pq.top() < m && pq.size() > 1){
        long long u = pq.top();
        pq.pop();
        long long v = pq.top();
        pq.pop();
        pq.push(u + 2 * v);
        cnt++;
    }
    if(pq.top() < m) cout << -1;
    else cout << cnt;
    
    return 0;
}