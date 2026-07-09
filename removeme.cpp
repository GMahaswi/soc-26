#include<bits/stdc++.h>
using namespace std;
#define int long long
bool palindrome(string s){
    int l=s.length();
    for(int i=0;i<l;i++){
        if(s[i]!=s[l-1-i])return false;
    }
    return true;
} 
int func(string& s,int st,vector<int>&dp,int n){
    if(st==n)return 0;
    int mini=INT_MAX;
    for(int i=st+1;i<n;i++){
        if(palindrome(s.substr(st,i-st))){
            if(dp[i]==-1)func(s,i,dp,n);
            mini=min(mini,dp[i]);
        }
    }
    if(mini==INT_MAX){
        mini=1+func(s,st+1,dp,n);
    }
    dp[st]=mini;
    return mini;
}
int32_t main(){
    int t;
    cin>>t;
    
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>dp(n,-1);
        ans.push_back(func(s,0,dp,n));
        
    }
    for(int a:ans){
       
        cout<<a<<'\n';
    }
    return 0;
}