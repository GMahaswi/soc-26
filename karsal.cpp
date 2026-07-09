#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>vec(n);
        int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++){cin>>vec[i];sum+=vec[i];maxi=max(maxi,vec[i]);}
        int val;
        if(sum%x==0){
            val=sum/x;
        }
        else {
            val=(sum/x)+1;
        }
        val=max(maxi,val);
       ans.push_back(val);
        
    }
    for(int a:ans)cout<<a<<endl;
}