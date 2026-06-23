#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<int>tel(n);
    for(int i=0;i<n;i++)cin>>tel[i];
    vector<vector<int>>dp(31,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        dp[0][i]=tel[i-1];
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    vector<int>ans;
    for(int i=0;i<q;i++){
        int x,k;
        cin>>x>>k;
        int mul=0;
        int start=x;
        while(k>0){
            if(k%2==1){
                start=dp[mul][start];
            }
            mul++;
            k=k/2;
        }
        cout<<start<<'\n';
    }
}