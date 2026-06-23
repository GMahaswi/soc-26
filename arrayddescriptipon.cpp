#include<bits/stdc++.h>
using namespace std;
long long di = 1e9 + 7;

long long func(int s, int l, int k, int m) {
    vector<long long> dp(m + 2, 0);

    if (s == 0) {
        // First unknown is free — init counts as placing it, run k-1 more
        for (int i = 1; i <= m; i++) dp[i] = 1;
        for (int i = 0; i < k - 1; i++) {
            vector<long long> ndp(m + 2, 0);
            for (int j = 1; j <= m; j++) {
                if (!dp[j]) continue;
                for (int y = j-1; y <= j+1; y++)
                    if (y >= 1 && y <= m)
                        ndp[y] = (ndp[y] + dp[j]) % di;
            }
            dp = ndp;
        }
    } else {
        // Left neighbor is known = s, transition k times from it
        dp[s] = 1;
        for (int i = 0; i < k; i++) {
            vector<long long> ndp(m + 2, 0);
            for (int j = 1; j <= m; j++) {
                if (!dp[j]) continue;
                for (int y = j-1; y <= j+1; y++)
                    if (y >= 1 && y <= m)
                        ndp[y] = (ndp[y] + dp[j]) % di;
            }
            dp = ndp;
        }
    }

    if (l == 0) {
        // No right neighbor — all endings valid
        long long ans = 0;
        for (int v = 1; v <= m; v++) ans = (ans + dp[v]) % di;
        return ans;
    } else {
        // Last unknown must land within +-1 of right neighbor l
        long long ans = 0;
        for (int v = max(1, l-1); v <= min(m, l+1); v++)
            ans = (ans + dp[v]) % di;
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int i = 0;
    long long ans = 1;

    while (i < n) {
        if (arr[i] == 0) {
            int left = (i == 0) ? 0 : arr[i-1];
            int k = 0;
            while (i < n && arr[i] == 0) { i++; k++; }
            int right = (i < n) ? arr[i] : 0;
            ans = (ans * func(left, right, k, m)) % di;
        } else {
            // Check adjacency between consecutive known values
            if (i > 0 && arr[i-1] != 0 && abs(arr[i] - arr[i-1]) > 1) {
                cout << 0 << "\n";
                return 0;
            }
            i++;
        }
    }

    cout << ans << "\n";
    return 0;
}