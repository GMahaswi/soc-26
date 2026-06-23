#include<bits/stdc++.h>
using namespace std;
int func(int target,int n,vector<long long >&v,vector<int>&dp){
    if(target==0)return 0;
    if(dp[target]>=-1)return dp[target];
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(v[i]<=target){
        int val=func(target-v[i],n,v,dp);
        if(val!=-1){
            ans=min(ans,val+1);
        }
    }
    }

    if(ans==INT_MAX){
        dp[target]=-1;
        
    }
    else dp[target]=ans;
    return dp[target];

}
int main(){
    int n,x;
    cin>>n>>x;
    vector<long long >v(n);
    vector<int>dp(x+1,-2);
    dp[0]=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<func(x,n,v,dp);

}