#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<pair<long long,int>> v;

        for (int i = 1; i <= n; i++) {
            long long x, y;
            cin >> x >> y;

            v.push_back({min(x, y), i});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n; i++) {
            cout << v[i].second << " ";
        }
        cout << '\n';
    }
}