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

vector<string> v;
unordered_set<string> st;

string hashing(const string &s) {
    ll h = 0, p = 1;
    for (char c : s) {
        h = (h + ((c - 47) * p) % mod) % mod;
        p = (p * 11) % mod;
    }
    return to_string(h);
}

void solve(){
    dalshe menshe

    int n; string s;

    cin >> n;
    for(int i = 1; i <= n * 2; i++){
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int cnt = 0;

    for(int i = 0; i < v.size(); i++){
        if(cnt == n) break;
        string hs = hashing(v[i]);
        if(st.find(hs) != st.end()){
            cout << "Hash of string \"" << v[i] << "\"" << " is " << hs << endl;
            cnt++;
        }
    }
}

//@abdygalykov esep shygaruga komekteskenin ushin rahmet bro

signed main() {

    dalshe menshe

    int tt = 1;

    //cin >> tt;

    while(tt--){

        solve();

    }

    return 0;
}
