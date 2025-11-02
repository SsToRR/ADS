#include <bits/stdc++.h>
#define dalshe ios_base::sync_with_stdio(false);
#define menshe cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define ll long long
#define ld long double
#define S second
#define mp make_pair
#define pb push_back
#define in insert
#define endl '\n'

using namespace std;

const ll N = 2e5 + 17;
const ll inf = 1e9 + 7;
const ll mod = 1e9 + 7;
const ll pw = 31;

vector<long long> prefix_hash(string s) {
    int n = s.size();
    vector<long long> h(n + 5, 0), p(n + 5, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return h;
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r) {
    ll res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

void solve(){
    dalshe menshe

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n = s1.size(), m = t.size();

    auto h1 = prefix_hash(s1);
    auto h2 = prefix_hash(s2);
    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++) p[i] = (p[i - 1] * pw) % mod;

    long long hash_t = 0;
    for (char c : t) hash_t = (hash_t * pw + (c - 'a' + 1)) % mod;

    int count = 0;
    for (int i = 0; i + m <= n; i++) {
        long long h_s1 = get_hash(h1, p, i, i + m);
        long long h_s2 = get_hash(h2, p, i, i + m);
        if (h_s1 == hash_t && h_s2 == hash_t) count++;
    }

    cout << count;

}


signed main() {

    dalshe menshe

    int tt = 1;

    //cin >> tt;

    while(tt--){

        solve();

    }

    return 0;
}