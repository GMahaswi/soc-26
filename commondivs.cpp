#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    int ans=1;
    for(int j=0;j<n;j++){
        int p=arr[j];
        int sqt=sqrt(p);   
        int i=1;   
        for(;i<=sqt-1;i++){
            if(p%i==0){    
                if(i>ans){
                mp[i]++;
                if(mp[i]>=2)ans=i;
                }
                if(p/i >ans){
                mp[p/i]++;
                if(mp[p/i]>=2)ans=p/i;
                }
            }
        }
        if((p%i==0)){
                mp[i]++;
                if(mp[i]>=2)ans=max(ans,i);   
                if(i*i !=p){
                    mp[p/i]++;
                if(mp[p/i]>=2)ans=max(ans,p/i);
                }                
        }
    }
    cout<<ans;
}