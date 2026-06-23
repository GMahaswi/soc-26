#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<int>prefixsum;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=vec[i];
        prefixsum.push_back(sum);
    }
    map<int,int>mp;
    for(int i=a-1;i<=b-1;i++){
        mp[prefixsum[i]]++;
    }
    int maxi = -1e18;
    int last=0;
    for(int i=0;i<n;i++){

        if(i+1<=b&&i+1>=a){
            maxi=max(prefixsum[i],maxi);
        }
        if (!mp.empty()) {
            auto max_it = mp.rbegin(); // Now this is 100% safe to dereference
         
            maxi = max(maxi, max_it->first - last);
        }
        last=prefixsum[i];
        if(i+a-1<n){
            mp[prefixsum[i+a-1]]--;
            
            if(mp[prefixsum[i+a-1]]==0)mp.erase(prefixsum[i+a-1]);
        }
        if(i+b<n){
            
            mp[prefixsum[i+b]]++;
        }
    }
    cout<<maxi;
}