#include <bits/stdc++.h>
using namespace std;
const long long modi = 1000000007LL;
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        adj[b].push_back(a);
        indeg[a]++;
    }

    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0||i==n-1)
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

    vector<long long> dp(n,0);
   

    dp[n-1] = 1;

    for (int u : topo) {
        if (dp[u]<=0) continue;

        for (int v : adj[u]) {
            dp[v]=(dp[u]+dp[v])%modi;
        }
    }

    cout<<dp[0];
}