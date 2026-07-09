#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>ans;
    int m=INT_MAX;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        vector<int>seen(n,-1);
        vector<int>grups;
        map<int,int>mp;
        int d=0;
        for(int i=0;i<n;i++){
           int val=(m^vec[i]);
         
            auto it=mp.find(val);
            if(it!=mp.end()){
                
                mp[val]--;
                if(mp[val]==0)mp.erase(it);  
            }
            else {
                d++;
                mp[vec[i]]++;
            }
            }
        ans.push_back(d);
    }
    for(int a:ans)cout<<a<<endl;
}