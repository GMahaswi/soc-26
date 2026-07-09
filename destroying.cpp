#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>as;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<n;i++)pq.push({vec[i],i});
        int vis=n;
        int ans=0;
        while(!pq.empty()){
           
            int f=pq.top()[1];
            
             int val=pq.top()[0];
            pq.pop();
            if(f>vis){
                continue;
            }
            ans=ans+(val*(vis-f));
            vis=f;
        }
        as.push_back(ans);
    }
    for(int a:as)cout<<a<<endl;
}