#include<bits/stdc++.h>
using namespace std;
#define int long long
bool func(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<vector<int>>nums(n,vector<int>(3,0));
    
    vector<int>sum(3,0);
    for(int i=0;i<n;i++){
        sum[vec[i]-1]++;
        for(int j=0;j<3;j++){
            nums[i][j]=sum[j];
        }
    }
    int l=-1;
    for(int i=0;i<n-1;i++){
        if(l!=-1){
            int ones=nums[i][0];
            int twos=nums[i][1];
            int three=nums[i][2];
            int left=l;
            if(ones+twos-left>=three){
                
                return true;
            }
        }
            int ones=nums[i][0];
            int twos=nums[i][1];
            int three=nums[i][2];
            if(ones>=twos+three){
                if(l==-1)l=(ones+twos-three);
                else l=min(l,(ones+twos-three));
            }
        
    }
    return false;
}
int32_t main(){
    int t;
    cin>>t;
    
    vector<bool>ans;
    while(t--){
        ans.push_back(func());

    }
    for(int a:ans){
       
        if(!a)cout<<"NO";
        else cout<<"YES";
        cout<<'\n';
    }
    return 0;
}