#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    vector<vector<int>>radj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        radj[b-1].push_back(a-1);
    }
    int N=1<<n;
    vector<vector<int>>dp(N,vector<int>(n,0));
    dp[1][0]=1;
    for(int i=1;i<N;i++){
        if(((i&(1<<n-1))&&(i!=N-1))){
            continue;
        }
        for(int u=0;u<n;u++){
            if((i&(1<<u))==0)continue;
            int prev=(i^(1<<u));
            for(int ind:radj[u]){
                dp[i][u]=(dp[i][u]+dp[prev][ind])%MOD;
            }
        }
    }
    cout<<dp[N-1][n-1];
}