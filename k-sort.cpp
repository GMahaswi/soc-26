#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int maxi=0;
        int coins=0;
        int last=vec[0];
        for(int i=0;i<n;i++){
            if(last>vec[i]){
                int diff=last-vec[i];
                maxi=max(maxi,diff);
                coins+=(diff);
            }
            else last=vec[i];
        }
        ans.push_back(coins+maxi);
    }
    for(int a:ans)cout<<a<<'\n';
}