#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    
    vector<int>ans;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a%b==0){
            ans.push_back(1);
        }
        else {
            ans.push_back(0);
        }
    }
    for(int a:ans){
       
        if(a==0)cout<<"NO";
        else cout<<"YES";
        cout<<'\n';
    }
    return 0;
}