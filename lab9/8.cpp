#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> ans;

void kmpSearch(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                ans.push_back(i - m + 1);
                j = lps[j-1];
            }
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> lps = computeLPS(s);

    long long cnt = 0;

    for (int L = 1; L * 2 < n; ++L) {
        bool ok = true;
        for (int i = 0; i < L; ++i) {
            if (s[i] != s[L + i]) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    }

    cout << cnt;
    return 0;
}
