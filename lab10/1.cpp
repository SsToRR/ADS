#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001][1001], cnt = 0, check = 0;
int d[1001][1001], ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int, int>> q;

    cin >> m >> n;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            d[i][j] = INT_MAX;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                q.push({i, j});
                d[i][j] = 0;
            }
            if (a[i][j] == 1) cnt++;
        }
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto &dir : dirs) {
            int nx = p.first + dir[0];
            int ny = p.second + dir[1];

            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && a[nx][ny] == 1) {
                a[nx][ny] = 2;
                d[nx][ny] = d[p.first][p.second] + 1;
                ans = max(ans, d[nx][ny]);
                check++;
                q.push({nx, ny});
            }
        }
    }

    if (check == cnt) cout << ans;
    else cout << -1;

    return 0;
}
