#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        map<pair<int,int>,long long>mp;
        long long pairs=0;
        for(int i=0;i<n;i++){
            int xw=(x-((vec[i])%x))%x;
            int yw=(vec[i]%y);
            
            auto it=mp.find({xw,yw});
            if(it!=mp.end())pairs+=it->second;
            
            mp[{vec[i]%x,vec[i]%y}]++;
        }
        
        ans.push_back(pairs);

    }
    for(int a:ans)cout<<a<<endl;
}