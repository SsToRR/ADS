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

    string s, t, check;
    int n;

    cin >> s;

    for(int i = 0; i < s.size(); i++) check += '0';

    auto h = prefix_hash(s);
    vector<long long> p(s.size() + 1, 1);
    for (int i = 1; i <= s.size(); i++) p[i] = (p[i - 1] * pw) % mod;

    cin >> n;

    for(int i = 1;i <= n; i++){
        cin >> t;
        long long hash_t = 0;
        for (char c : t) hash_t = (hash_t * pw + (c - 'a' + 1)) % mod;
        for(int j = 0; j + t.size() <= s.size(); j++){
            long long substr_hash = get_hash(h, p, j, j + t.size());
            if(substr_hash == hash_t)
                for(int k = j; k < j + t.size(); k++) check[k] = '1';
        }
    }
    for(int i = 0; i < check.size(); i++){
        if(check[i] == '0'){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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