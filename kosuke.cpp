#include<bits/stdc++.h>
using namespace std;
#define int long long
struct cmp {
    bool operator()(const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    }
};
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n+1);
        
        for(int i=0;i<n;i++){
            cin>>vec[i+1];
        }
        vector<pair<int,int>>vecp;
        vector<int>prefix(n+1,0);
        prefix[0]=0;
        map<int,int>mp;
        mp[0]=0;
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+vec[i];
            if(mp.find(prefix[i])!=mp.end()){
                vecp.push_back({mp[prefix[i]]+1,i});
            }
            mp[prefix[i]]=i;
        }
        sort(vecp.begin(),vecp.end(),cmp());
        int last=0;
        int a=0;
        
        for(auto p:vecp){
         
            if(p.first>last){
                a++;
                last=p.second;
            }
        }
        ans.push_back(a);
    }
    for(int a:ans)cout<<a<<'\n';
}