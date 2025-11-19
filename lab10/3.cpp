#include <bits/stdc++.h>
using namespace std;

int n, s, f, a[101][101];
vector<int> g[101];
vector<int> d(40005, -1);
vector<int> path(40005);
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> f;

    if(s == f){
        cout << 0;
        return 0;
    } else if(s > f){
        cout << s - f << endl;
        for(int i = s - 1; i >= f; i--) cout << i << ' ';
        return 0;
    }

    q.push(s);
    d[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v * 2 <= 40000 && d[v * 2] == -1) {
            d[v * 2] = d[v] + 1;
            path[v * 2] = v;
            q.push(v * 2);
        }

        if (v - 1 > 0 && d[v - 1] == -1) {
            d[v - 1] = d[v] + 1;
            path[v - 1] = v;
            q.push(v - 1);
        }

        if (d[f] != -1) break;
    }

    vector<int> ans;
    int cur = f;
    while (cur != -1 && cur != s) {
        ans.push_back(cur);
        cur = path[cur];
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    return 0;
}
