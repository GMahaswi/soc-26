#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<int,int>> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }

        sort(a.begin(), a.end());

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i].first;
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int x = a[i].first;

            int left = x * i - pref[i];

            int right =
                (pref[n] - pref[i + 1])
                - x * (n - i - 1);

            ans[a[i].second] = n + left + right;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}