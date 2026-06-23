#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18; // Use a clean infinity constant for long long

int32_t main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<int, int>>> adj(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
    }

    // dist[city][coupon_used] initialized to INF
    vector<vector<int>> dist(n, vector<int>(2, INF));
    
    // Priority Queue stores: {cost, city, coupon_used}
    // Using a std::tuple or a custom struct is faster and cleaner than vector<int>
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [cost, u, coupon_used] = pq.top();
        pq.pop();

        // CRITICAL VISITED GUARD: If we found a shorter path to this state already, skip it!
        if (cost > dist[u][coupon_used]) {
            continue;
        }

        // Relax neighbors
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Option 1: Don't use the coupon (or coupon already used)
            if (dist[u][coupon_used] + weight < dist[v][coupon_used]) {
                dist[v][coupon_used] = dist[u][coupon_used] + weight;
                pq.push({dist[v][coupon_used], v, coupon_used});
            }

            // Option 2: Use the coupon right now (only valid if coupon_used is currently 0)
            if (coupon_used == 0) {
                if (dist[u][0] + (weight / 2) < dist[v][1]) {
                    dist[v][1] = dist[u][0] + (weight / 2);
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    // The answer is the absolute minimum cost to reach the destination city
    cout << min(dist[n - 1][0], dist[n - 1][1]) << "\n";

    return 0;
}