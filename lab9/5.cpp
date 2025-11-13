#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0, i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len])
            lps[i++] = ++len;
        else if (len != 0)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;

        vector<int> lps = computeLPS(s);
        int n = s.size();
        int p = lps[lps.size()-1];

        long long res = n + (k - 1) * (n - p);
        cout << res << '\n';
    }
    return 0;
}
