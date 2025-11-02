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

string s[155], long_str;
ll mx, str_cnt[155];

void solve(int n){
    dalshe menshe

    mx = INT_MIN;

    for(int i = 1; i <= n; i++) cin >> s[i];

    cin >> long_str;

    auto h = prefix_hash(long_str);

    vector<long long> p(long_str.size() + 1, 1);

    for (int i = 1; i <= long_str.size(); i++) p[i] = (p[i - 1] * pw) % mod;

    for(int i = 1; i <= n; i++){
        long long hash_s = 0, cnt = 0;
        for(char c : s[i]) hash_s = (hash_s * pw + (c - 'a' + 1)) % mod;
        for(int j = 0; j + s[i].size() <= long_str.size(); j++){
            long long substr_hash = get_hash(h, p, j, j + s[i].size());
            if(substr_hash == hash_s) cnt++;
        }
        mx = max(mx, cnt);
        str_cnt[i] = cnt;
    }
    cout << mx << '\n';
    for(int i = 1; i <= n; i++){
        if(str_cnt[i] == mx) cout << s[i] << '\n';
    }

}


signed main() {

    dalshe menshe

    int tt = 1;

    while(true){

        cin >> tt;

        if(tt == 0) break;
        else solve(tt);

    }

    return 0;
}