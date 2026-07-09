#include<bits/stdc++.h>
using namespace std;
#define int long long
struct cmp {
    bool operator()(pair<int,int> a, pair<int,int> b) const {
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};
int32_t main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m,l;
        cin>>n>>m>>l;
        vector<vector<int>>hurdles(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>hurdles[i][0]>>hurdles[i][1];
        }
        vector<pair<int,int>>power;
        for(int i=0;i<m;i++){
            int x,v;
            cin>>x>>v;
            power.push_back({x,v});
        }
        sort(power.begin(),power.end(),cmp);
        priority_queue<int>pq;
        int curr=0;
        for(int i=0;i<n;i++){
            int s=hurdles[i][0];
            int end=hurdles[i][1];
            int req=end-s+2;
            if(curr<req){
                while(!pq.empty()){}
            }
        }

    }
}