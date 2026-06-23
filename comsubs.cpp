#include<bits/stdc++.h>
using namespace std;

int edit(vector<vector<int>>&dp,vector<int>& s1,vector<int>& s2,int n,int m){
    if(n<=0||m<=0)return 0;
    if(dp[n-1][m-1]!=-1)return dp[n-1][m-1];
    int ans=0;
    if(s1[n-1]==s2[m-1]){
        ans++;
        if(n-2<0||m-2<0){
            
        }
        else {
            if(dp[n-2][m-2]>=0){
                ans=max(ans,1+dp[n-2][m-2]);
            }
            else {
                ans=max(ans,1+edit(dp,s1,s2,n-1,m-1));
            }
        }
          dp[n-1][m-1]=ans;
    return ans;
        
    }
    else {
        if(n-2<0||m-2<0){
            ans=ans-1+1;
        }
        else {
            if(dp[n-2][m-2]>=0){
                ans=max(ans,dp[n-2][m-2]);
            }
            else {
                ans=max(ans,edit(dp,s1,s2,n-1,m-1));
            }
        }
        
    }
    /*delete at s1*/
    if(n==1)ans=ans;
    else{
        if(dp[n-2][m-1]>=0)ans=max(ans,dp[n-2][m-1]);
        else {
            ans=max(ans,edit(dp,s1,s2,n-1,m));
        }
    }
    /*delete at s2*/
    if(m==1)ans=ans;
    else{
        if(dp[n-1][m-2]>=0)ans=max(ans,dp[n-1][m-2]);
        else {
            ans=max(ans,edit(dp,s1,s2,n,m-1));
        }
    }
    dp[n-1][m-1]=ans;
    return ans;

}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<int>s1(n);
    vector<int>s2(m);
    for(int i=0;i<n;i++){
        cin>>s1[i];
    }
    for(int j=0;j<m;j++){
        cin>>s2[j];
    }
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<edit(dp,s1,s2,n,m);
}