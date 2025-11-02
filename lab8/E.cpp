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

ll n, h[55], power[55], a[55];
string ans;

void solve(){
    dalshe menshe


    cin >> n;

    power[0] = 1;

    for(int i = 1; i <= 51; i++){
        power[i] = power[i-1] * 2;
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ll cur;
        if(i > 0) cur = (a[i] - a[i-1]) / power[i] + 97;
        else cur = a[i] + 97;
        cout << char(cur);
    }
    //h[i] = h[i-1] + 2^i * (s[i] - 97);
    //h[i] = h[i-1] + s[i] * 2^i - 97 * 2^i
    //(h[i] - h[i-1])/2^i + 97 = s[i]
    //7 = 0 + s[i] * 2^0 - 97 * 2^0

    //7 = x - 97

    //x = 104



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