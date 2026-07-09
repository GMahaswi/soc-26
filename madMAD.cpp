#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(){
 
    ll t;
    cin>>t;
    while(t--){
 
        ll n;
        cin>>n;
        vector<ll> a(n);
        for(ll i=0;i<n;i++) cin>>a[i];
        ll res=accumulate(a.begin(),a.end(),0ll);
        set<ll> s;
        vector<ll> b(n);
        ll MAD=0;
        for(ll i=0;i<n;i++){
            if(s.find(a[i])!=s.end()) MAD=max(MAD,a[i]);
            s.insert(a[i]);
            b[i]=MAD;
        }
        res+=accumulate(b.begin(),b.end(),0ll);
 
        vector<ll> c(n);
        MAD=0;
        s.clear();
        for(ll i=0;i<n;i++){
            if(s.find(b[i])!=s.end()) MAD=max(MAD,b[i]);
            s.insert(b[i]);
            c[i]=MAD;
        }
        vector<ll> pfx(n);
        pfx[0]=c[0];
        for(ll i=1;i<n;i++) pfx[i]=pfx[i-1]+c[i];
        res+=accumulate(pfx.begin(),pfx.end(),0ll);
        cout<<res<<endl;
    }
}