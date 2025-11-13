#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) lps[i++] = ++len;
        else if (len != 0) len = lps[len-1];
        else lps[i++] = 0;
    }

    return lps;
}

int kmpSearch(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
            if (j == m) {
                return i-j;
                j = lps[j-1];
            }
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;

    cin >> s >> t;

    if(s.size() != t.size()){
        cout << -1;
        return 0;
    }

    string s2 = s + s;

    if(kmpSearch(s2, t) == -1) cout << -1;
    else cout << s.size() - kmpSearch(s2, t);



    return 0;
}
