#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,vector<int>>mp;
map<long long,long long> dp;

long long func(long long size){
    if(dp.count(size)) return dp[size];

    long long ans = 0;

    for(auto p: mp[size]){
        ans=max(ans, func(size+p-1)+p-1);
    }

    return dp[size]=ans;
}

int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        for(int i=n;i>1;i--){
            int diff=vec[i-1]-1+i;
            mp[diff].push_back(i);
        }
        ans.push_back(n+func(n));
        mp.clear();
        dp.clear();
    }
    for(int a:ans)cout<<a<<endl;
}