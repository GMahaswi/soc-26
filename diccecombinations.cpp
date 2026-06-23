#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long func(int v,vector<long long>&dp){
    if(v<=0)return 0;
    dp[v]=0;
    for(int i=1;i<=6;i++){
        if(v-i>=0){
            if(dp[v-i]>=0){
                dp[v]=(dp[v]+dp[v-i])%mod;
            }
            else dp[v]=(dp[v]+func(v-i,dp))%mod;
        }
    }
    return dp[v];
}
int main(){
    int n;
    cin>>n;
    vector<long long>dp(n+1,-1);
    dp[0]=1;
   
    cout<<func(n,dp);

}