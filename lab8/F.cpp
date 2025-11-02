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
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll pw1 = 31;
const ll pw2 = 37;

vector<ll> h1(2002, 0), h2(2002, 0);
vector<ll> p1(2002, 1), p2(2002, 1);

pair<ll, ll> get_hash(int l, int r) {
    pair<ll, ll> res = {(h1[r] - h1[l] * p1[r - l]) % mod1, (h2[r] - h2[l] * p2[r - l]) % mod2};
    if (res.first < 0) res.first += mod1;
    if (res.second < 0) res.second += mod2;
    return res;
}

void solve(){
    dalshe menshe

    string s;
    unordered_set<uint64_t> st;

    cin >> s;

    int n = s.size();

    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * pw1 + (s[i] - 'a' + 1)) % mod1;
        h2[i + 1] = (h2[i] * pw2 + (s[i] - 'a' + 1)) % mod2;
    }

    for(int i = 1; i <= s.size(); i++){
        for(int j = 0; j + i <= s.size(); j++){
            pair<ll, ll> p = get_hash(j, j + i);
            uint64_t combine = ((uint64_t)p.F << 32) | ((uint64_t)p.S);
            st.insert(combine);
        }
    }
    cout << st.size();

}


signed main() {

    dalshe menshe

    int tt = 1;

    //cin >> tt;

    for (int i = 1; i < 2002; i++) {
        p1[i] = (p1[i-1] * pw1) % mod1;
        p2[i] = (p2[i-1] * pw2) % mod2;
    }

    while(tt--){

        solve();

    }

    return 0;
}