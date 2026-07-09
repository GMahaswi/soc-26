#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
int32_t main(){
    int t;
    cin>>t;
    
    vector<int>anss;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++)cin>>vec[i];
        int ans=0;
        int sf=0;
        for(int i=1;i<=n;i++){
            sf+=vec[i];
            if(sf<0)sf=0;
            ans=max(ans,sf);
        }
        int tsum=0;
        for(int i=1;i<=n;i++){tsum+=vec[i];
            tsum=(tsum%mod + mod)%mod;
        }
       
    
        ans = (ans + mod) % mod;
        int is=ans;
        sf=ans;
        for (int i = 1; i <= k; i++) {
    sf = (ans + sf) % mod;
    ans = sf;
}

        ans = ((ans + tsum - is) % mod + mod) % mod;
        anss.push_back(ans);
        
    }
    for(int a:anss){
       
        cout<<a<<'\n';
    }
    return 0;
}