
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> adj, radj;
vector<int> vis, order, comp;

void dfs1(int v) {
    vis[v] = 1;

    for (int u : adj[v]) {
        if (!vis[u]) dfs1(u);
    }

    order.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;

    for (int u : radj[v]) {
        if (comp[u] == 0) {
            dfs2(u, c);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    radj.resize(n + 1);
    vector<int>coins(n+1);
    for(int i=1;i<=n;i++){
        cin>>coins[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vis.assign(n + 1, 0);
    comp.assign(n + 1, 0);

    // First pass
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    reverse(order.begin(), order.end());

    // Second pass
    int scc = 0;

    for (int v : order) {
        if (comp[v] == 0) {
            scc++;
            dfs2(v, scc);
        }
    }

  
    vector<int>compo(scc+1,0);
    for (int i = 1; i <= n; i++) {
        compo[comp[i]]+=coins[i];
    }
    set<pair<int,int>>st;

    for(int i=1;i<=n;i++){
        for(int a:adj[i]){
            if(comp[a]==comp[i])continue;
            st.insert({comp[i],comp[a]});
        }
    }
    vector<vector<int>>readja(scc+1);
    vector<int>sz(scc+1);
    for(auto p:st){
        sz[p.first]++;
        readja[p.second].push_back(p.first);
    }
    vector<int>dp(scc+1);
    queue<int>q;
    for(int i=1;i<=scc;i++){
        dp[i]=compo[i];
        if(sz[i]==0)q.push(i);
    }
    int maxi=0;

    while(!q.empty()){
        auto p=q.front();
        q.pop();
        
        maxi=max(maxi,dp[p]);
        for(int ad:readja[p]){
            sz[ad]--;
            dp[ad]=max(dp[ad],dp[p]+compo[ad]);
            
            if(sz[ad]==0){
                q.push(ad);
            }
        }
    }
    cout<<maxi;
}