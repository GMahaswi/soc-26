#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    vector<int> topo;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        topo.push_back(u);

        for (int v : adj[u]) {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    vector<long long> dp(n, -1e18);
    vector<int> parent(n, -1);

    dp[0] = 1;

    for (int u : topo) {
        if (dp[u] < 0) continue;

        for (int v : adj[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if (dp[n - 1] < 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;

    for (int cur = n - 1; cur != -1; cur = parent[cur])
        path.push_back(cur);

    reverse(path.begin(), path.end());

    cout << path.size() << '\n';

    for (int x : path)
        cout << x + 1 << ' ';
}