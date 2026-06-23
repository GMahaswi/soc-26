#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }

    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<int> used(m, 0);
    vector<int> ptr(n + 1, 0);

    stack<int> st;
    vector<int> ans;

    st.push(1);

    while (!st.empty()) {
        int u = st.top();

        while (ptr[u] < adj[u].size() &&
               used[adj[u][ptr[u]].second])
            ptr[u]++;

        if (ptr[u] == adj[u].size()) {
            ans.push_back(u);
            st.pop();
        } else {
            auto [v, id] = adj[u][ptr[u]];
            used[id] = 1;
            st.push(v);
        }
    }

    if ((int)ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << ' ';
}