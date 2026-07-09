#include <bits/stdc++.h>
using namespace std;

#define int long long

bool feasible(int s, long long A, long long k, long long M) {
    long long L = max(M, (A + s - 1) / s); // max(M, ceil(A/s))
    long long R = (A + k) / s;
    return L <= R;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long k;
        cin >> n >> k;

        long long A = 0;
        long long M = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            A += x;
            M = max(M, x);
        }

        int lo = 1, hi = n, ans = 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (feasible(mid, A, k, M)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}