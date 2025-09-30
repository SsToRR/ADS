#include <bits/stdc++.h>
using namespace std;

int main() {
    
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    
    long long n, x, sum = 0;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> x;
        pq.push(x);
    }
    
    //3 5 6 9
    
    while(pq.size() != 1){
        long long u = pq.top();
        pq.pop();
        long long v = pq.top();
        pq.pop();
        pq.push(u + v);
        sum += u + v;
    }
    cout << sum;
    
    return 0;
}