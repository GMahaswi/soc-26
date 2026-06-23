#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(const std::vector<int>& a, const std::vector<int>& b){
    if(a[0]==b[0])return a[1]<b[1];
    return a[0]>b[0];
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    vector<int>priceofticket(n);
    vector<int>maxprice(m);
    for(int i=0;i<n;i++)cin>>priceofticket[i];
    for(int i=0;i<m;i++)cin>>maxprice[i]; 

    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[priceofticket[i]]++;
    }

    vector<int>ans(m,-1);
  
    for(int i=0;i<m;i++){
        int target=maxprice[i];
        auto it=mp.lower_bound(maxprice[i]);
        if (it != mp.end() && it->first == target) {
            ans[i]=it->first;
            mp[it->first]--;
            if(mp[it->first]==0)mp.erase(it);
    } 
    else if (it != mp.begin()) {
        // Step back because lower_bound gave us something strictly greater (or end())
        --it; 
        ans[i]=it->first;
            mp[it->first]--;
            if(mp[it->first]==0)mp.erase(it);
    } 
    }
    for(int a:ans)cout<<a<<'\n';
}