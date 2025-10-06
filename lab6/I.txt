#include <bits/stdc++.h>
using namespace std;

string s, t;
int cnt[30];

int main() {
    
    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a']++;
    }
    
    for(int i = 0; i < 26; i++){
        for(int j = 1; j <= cnt[i]; j++){
            t += char(i + 'a');
        }
    }
    cout << t;
    
    return 0;
}