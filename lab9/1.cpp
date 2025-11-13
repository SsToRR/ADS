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

bool kmpSearch(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                return true;
            }
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

int minRepetitions(string s, string t) {
    string repeated = s;
    int cnt = 1;

    while (repeated.size() < t.size()) {
        repeated += s;
        cnt++;
    }

    if (kmpSearch(repeated, t)) return cnt;
    if (kmpSearch(repeated + s, t)) return cnt + 1;

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    cout << minRepetitions(s, t) << "\n";
    return 0;
}
