#include<bits/stdc++.h>
using namespace std;
#define int long long
bool func(){
    int k;
    cin>>k;
    vector<int>vec(k);
    for(int i=0;i<k;i++)cin>>vec[i];
    int cnt=0;
    for(int i=0;i<k;i++){
        if(vec[i]>=3)return true;
        if(vec[i]==2)cnt++;
    }
    if(cnt>=2)return true;
    return false;
}
int32_t main(){
    int t;
    cin>>t;
    
    vector<bool>ans;
    while(t--){
        ans.push_back(func());

    }
    for(int a:ans){
       
        if(!a)cout<<"NO";
        else cout<<"YES";
        cout<<'\n';
    }
    return 0;
}