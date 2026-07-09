#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<vector<int>>ans(t);
    int test=0;
    while(test<t){
        int n,q;
        cin>>n>>q;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        vector<int>query(q);
        for(int i=0;i<q;i++)cin>>query[i];
        map<int,int>mp;
        
        mp[n-1]++;
         
        for(int i=1;i<n;i++){
           int diff=vec[i]-vec[i-1]-1;
            int before=i;
            int after=n-i;
            int mul=before*after;
            mp[mul]=mp[mul]+diff;
            mp[mul+after-1]++;
        }
        
        for(int i=0;i<q;i++){
           
            auto it=mp.find(query[i]);
            if(it==mp.end()){
                ans[test].push_back(0);
            }
            else {
                ans[test].push_back(it->second);
            }
        }
        test++;
    }
    for(int i=0;i<t;i++){
        for(int q:ans[i])cout<<q<<" ";
        cout<<endl;
    }
    }