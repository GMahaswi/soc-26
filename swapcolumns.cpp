#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>vec(2,vector<int>(n));
        for(int i=0;i<n;i++){
            cin>>vec[0][i];
        }
        for(int i=0;i<n;i++){
            cin>>vec[1][i];
        }
       
        int maxval=min(vec[0][0],vec[1][0]);
        for(int i=1;i<n;i++){
            int mini=min(vec[0][i],vec[1][i]);
            if(mini>maxval){
                maxval=mini;
                            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            
                sum+=(max(vec[0][i],vec[1][i]));
            
        }
        cout<<maxval+sum<<'\n';
    }
}