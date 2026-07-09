#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,x,y,z;
        cin>>n>>x>>y>>z;
        int withoutai=(n+(x+y)-1)/(x+y);
        int withai=withoutai;
        int done=(x*z);
        if(done<n){
          
           int left=n-done;
           y=10*y;
           int val=((left+(x+y)-1)/(x+y));
           
           withai=min(withai,z+val);
        }
        ans.push_back(withai);
    }
    for(int a:ans)cout<<a<<endl;
}