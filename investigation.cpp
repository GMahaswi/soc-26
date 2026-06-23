#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1000000007;
const long long INF = 1e18;

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        adj[a].push_back({b, c});
    }

    vector<long long> dist(n, INF);
    vector<long long> cnt(n, 0);
    vector<long long> mn(n, INF);
    vector<long long> mx(n, 0);

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    dist[0] = 0;
    cnt[0] = 1;
    mn[0] = 0;
    mx[0] = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto [v, w] : adj[u]) {

            if (dist[v] > dist[u] + w) {

                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                mn[v] = mn[u] + 1;
                mx[v] = mx[u] + 1;

                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w) {

                cnt[v] = (cnt[v] + cnt[u]) % MOD;

                mn[v] = min(mn[v], mn[u] + 1);
                mx[v] = max(mx[v], mx[u] + 1);
            }
        }
    }

    cout << dist[n - 1] << " "
         << cnt[n - 1] << " "
         << mn[n - 1] << " "
         << mx[n - 1] << "\n";
}