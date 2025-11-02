#include <bits/stdc++.h>
#define dalshe ios_base::sync_with_stdio(false);
#define menshe cin.tie(NULL);cout.tie(NULL);
#define all(x) x.begin(), x.end()
#define pii pair<int,int>
#define F first
#define ll long long
#define ld long double
#define S second
//#define mp make_pair
#define pb push_back
#define in insert
#define endl '\n'

using namespace std;

const ll N = 2e5 + 17;
const ll inf = 1e9 + 7;
const ll mod = 1e9 + 7;
const ll pw = 37;

const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll pw1 = 31;
const ll pw2 = 37;

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


ll hashify(string tmp){
    long long hash_tmp = 0;
    for(char c : tmp) hash_tmp = (hash_tmp * pw + (c - 'a' + 1)) % mod;
    return hash_tmp;
}

string s;
int n, l, r;
unordered_map<uint64_t, int> mp;

void solve(){
    dalshe menshe

    cin >> s >> n;

    auto [h1, p1] = prefix_hash(s, mod1, pw1);
    auto [h2, p2] = prefix_hash(s, mod2, pw2);

    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j <= s.size(); j++){
            ll x1 = get_hash(h1, p1, i, j, mod1);
            ll x2 = get_hash(h2, p2, i, j, mod2);
            uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
            mp[key]++;
        }
    }

    for(int i = 1; i <= n; i++){
        cin >> l >> r;
        l--;
        ll x1 = get_hash(h1, p1, l, r, mod1);
        ll x2 = get_hash(h2, p2, l, r, mod2);

        uint64_t combine = (((uint64_t)x1 << 32) ^ (uint64_t)x2);
        cout << mp[combine] << '\n';
    }

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