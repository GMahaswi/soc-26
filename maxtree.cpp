#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>sz(n+1,0);
    vector<vector<int>>rev(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(x>y){
            sz[u]++;
            rev[v].push_back(u);
        }
        else {
            sz[v]++;
            rev[u].push_back(v);
        }
    }
    queue<int>q;
 
    int count=1;
    vector<int>perm(n+1);
    for(int i=1;i<=n;i++){
        if(sz[i]==0)q.push(i);
    }
    while(!q.empty()){
        int t=q.front();
        perm[t]=count;
        count++;
        q.pop();
        for(int a:rev[t]){
            sz[a]--;
            if(sz[a]==0){
                q.push(a);
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<perm[i]<<" ";
    cout<<'\n';
}
}