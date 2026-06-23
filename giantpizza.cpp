#include <bits/stdc++.h>
using namespace std;

#define int long long
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> adj, radj;
vector<int> vis, order, comp;
int negi(int val){
    return val^1;
}
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

    adj.resize(2*m +2);
    radj.resize(2*m + 2);
    for (int i = 0; i < n; i++) {
        char f,s;
        int af;
        int as;
        int b;
        int bq;
        cin>>f>>b>>s>>bq;
        if(f=='+'){
            af=(2*b);
        }
        else {
            af=(2*b)+1;
        }
        if(s=='+'){
            as=2*bq;
        }
        else {     
            as=(2*bq)+1;
        }
        adj[negi(af)].push_back(as);
        adj[negi(as)].push_back(af);
        radj[as].push_back(negi(af));
        radj[af].push_back(negi(as));
    }
    vis.assign(2*m + 2, 0);
    comp.assign(2*m + 2, 0);
    for (int i = 2; i <= 2*m+1; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    int scc = 0;
    for (int v : order) {
        if (comp[v] == 0) {
            scc++;
            dfs2(v, scc);
        }
    }
    for (int i = 1; i <= m; i++){
        if(comp[2*i]==comp[2*i +1]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <= m; i++){
        if(comp[2*i]>comp[2*i +1]){
            cout<<"+";
        }
        else {
            cout<<"-";
        }
        cout<<" ";
    }
    return 0;
}
