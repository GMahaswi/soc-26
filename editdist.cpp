#include<bits/stdc++.h>
using namespace std;
int edit(vector<vector<int>>&dp,string& s1,string&3 s2,int n,int m){
    if(n<=0||m<=0)return max(s1.length(),s2.length());
    if(dp[n-1][m-1]!=-1)return dp[n-1][m-1];
    int ans=max(n,m);
    if(s1[n-1]==s2[m-1]){
        if(n-2<0||m-2<0){
            ans=ans-1;
        }
        else {
            if(dp[n-2][m-2]>=0){
                ans=min(ans,dp[n-2][m-2]);
            }
            else {
                ans=min(ans,edit(dp,s1,s2,n-1,m-1));
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
                ans=min(ans,dp[n-2][m-2]+1);
            }
            else {
                ans=min(ans,edit(dp,s1,s2,n-1,m-1)+1);
            }
        }
    }
    /*delete at s1*/
    if(n==1)ans=min(ans,m);
    else{
        if(dp[n-2][m-1]>=0)ans=min(ans,1+dp[n-2][m-1]);
        else {
            ans=min(ans,1+edit(dp,s1,s2,n-1,m));
        }
    }
    /*delete at s2*/
    if(m==1)ans=min(ans,n);
    else{
        if(dp[n-1][m-2]>=0)ans=min(ans,1+dp[n-1][m-2]);
        else {
            ans=min(ans,1+edit(dp,s1,s2,n,m-1));
        }
    }
    dp[n-1][m-1]=ans;
    return ans;

}
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<edit(dp,s1,s2,n,m);
}