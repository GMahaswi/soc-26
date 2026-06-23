#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++)cin>>heights[i];

    vector<int>dp(n,1);
    stack<int>st;
    
    for(int i=0;i<n;i++){
        int best=0;
        while(!st.empty()&&heights[st.top()]<heights[i]){
            best=max(best,dp[st.top()]);
            st.pop();
        }
        if(!st.empty()){
            dp[i]=max(dp[i],dp[st.top()]+1);
        }
        dp[i]=max(dp[i],best+1);
        st.push(i);
    }
    int best=1;
    for(int i=0;i<n;i++){
        best=max(best,dp[i]);
    }
    cout<<best;
}