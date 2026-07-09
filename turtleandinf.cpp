#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,m;
        cin>>n>>m;
        int min;
        int a=0;
        if(n>=m)min=n-m;
        else min=0;
        if(min>0)min=log2(min);
        int max=n+m;
        int lmax=log2(max);
        
        int lmin=0;
        if(min>0){
           lmin=log2(min);
        }
        if(lmax-lmin>)
        for(int j=min;j<=n+m;j++){
            a=a|j;
        }
        ans.push_back(a);
    }
    for(int a:ans)cout<<a<<endl;
}