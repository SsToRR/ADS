#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long a[N];

int lowerBound(long long a[], int n, long long x) {
    int l = 1, r = n, ans = n + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upperBound(long long a[], int n, long long x) {
    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int main() {

    long long n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    while (m--) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int L1 = lowerBound(a, n, l1);
        int R1 = upperBound(a, n, r1);
        int cnt1 = max(0, R1 - L1 + 1);

        int L2 = lowerBound(a, n, l2);
        int R2 = upperBound(a, n, r2);
        int cnt2 = max(0, R2 - L2 + 1);

        int L = max(l1, l2), R = min(r1, r2);
        int cnt_inter = 0;
        if (L <= R) {
            int Li = lowerBound(a, n, L);
            int Ri = upperBound(a, n, R);
            cnt_inter = max(0, Ri - Li + 1);
        }

        cout << cnt1 + cnt2 - cnt_inter << "\n";
    }

    return 0;
}