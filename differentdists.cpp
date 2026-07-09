#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int val=(4*n);
        vector<int>ans(val,-1);
        int p=0;
        for(int i=1;i<n;i++){
            int pre=p;
            ans[pre]=i;
            pre=pre+n+1;
            ans[pre]=i;
            pre=pre+(n);
            ans[pre]=i;
            pre+=(n-1);
            ans[pre]=i;
            p++;
        }
        for(int i=0;i<val;i++){
            if(ans[i]==-1)ans[i]=n;
        }
        for(int a:ans)cout<<a<<" ";
        cout<<endl;
    }
}