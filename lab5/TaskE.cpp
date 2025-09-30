#include <bits/stdc++.h>
using namespace std;

int main() {
    
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    
    long long n, m, x, sum = 0;
    string s;
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> s;
        if(s == "insert"){
            cin >> x;
            if(pq.size() == m){
                long long u = pq.top();
                sum -= u;
                pq.pop();
                pq.push(max(u, x));
                sum += max(u, x);
            } else {
                pq.push(x);
                sum += x;
            }
        }
        else {
            cout << sum << '\n';
        }
    }
    
    return 0;
}