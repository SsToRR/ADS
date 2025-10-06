#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[30];
char c;
    
int main() {
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> c;
        cnt[c - 'a']++;
    }
    cin >> c;
    for(int i = c - 'a' + 1; i <= 26; i++){
        if(cnt[i]) {
            cout << char(i + 'a');
            return 0;
        }
    }
    for(int i = 1; i < c - 'a'; i++){
        if(cnt[i]){
            cout << char(i + 'a');
            return 0;
        }
    }
    
    return 0;
}