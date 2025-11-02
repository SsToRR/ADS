#include <bits/stdc++.h>
#define dalshe ios_base::sync_with_stdio(false);
#define menshe cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define endl '\n'
using namespace std;

const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll pw1 = 31;
const ll pw2 = 37;

int k;

pair<vector<ll>, vector<ll>> prefix_hash(const string &s, ll mod, ll pw) {
    int n = s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return {h, p};
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r, ll mod) {
    ll res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

string get_common_substring(vector<string> &v, int len) {
    if (len == 0) return "";

    auto [h1, p1] = prefix_hash(v[1], mod1, pw1);
    auto [h2, p2] = prefix_hash(v[1], mod2, pw2);

    unordered_set<uint64_t> common;

    for (int i = 0; i + len <= v[1].size(); i++) {
        ll x1 = get_hash(h1, p1, i, i + len, mod1);
        ll x2 = get_hash(h2, p2, i, i + len, mod2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        common.insert(key);
    }

    for (int idx = 2; idx <= k; idx++) {
        auto [h1, p1] = prefix_hash(v[idx], mod1, pw1);
        auto [h2, p2] = prefix_hash(v[idx], mod2, pw2);

        unordered_set<uint64_t> cur;
        int n = v[idx].size();
        for (int i = 0; i + len <= n; i++) {
            ll x1 = get_hash(h1, p1, i, i + len, mod1);
            ll x2 = get_hash(h2, p2, i, i + len, mod2);
            uint64_t key = ((uint64_t)x1 << 32) ^ x2;
            cur.insert(key);
        }

        unordered_set<uint64_t> next;
        for (auto &x : common)
            if (cur.count(x)) next.insert(x);

        common.swap(next); //common = next, but O(1)
        if (common.empty()) return "";
    }

    auto [ha1, pa1] = prefix_hash(v[1], mod1, pw1);
    auto [ha2, pa2] = prefix_hash(v[1], mod2, pw2);
    int n = v[1].size();

    for (int i = 0; i + len <= n; i++) {
        ll x1 = get_hash(ha1, pa1, i, i + len, mod1);
        ll x2 = get_hash(ha2, pa2, i, i + len, mod2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        if (common.count(key)) return v[1].substr(i, len);
    }

    return "";
}

void solve() {
    dalshe menshe

    int l = 0, r = INT_MAX;

    cin >> k;
    vector<string> v(k+5);
    for (int i = 1, x; i <= k; i++) cin >> v[i], r = min<int>(r, v[i].size());

    string ans = "";
    while (l <= r) {
        int mid = (l + r) / 2;
        string temp = get_common_substring(v, mid);
        if (!temp.empty()) {
            ans = temp;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << ans;
}

signed main() {
    dalshe menshe

    int tt = 1;

    while(tt--) solve();


    return 0;
}