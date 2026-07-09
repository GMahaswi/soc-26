#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    
    vector<int>ans;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n+1);
        for(int i=1;i<=n;i++)cin>>vec[i];
        vector<int>seen(n+1,0);
        int nom=0;
        for(int i=1;i<=n;i++){
            if(vec[i]==0){
                nom++;
            }
            seen[vec[i]]=1;
        }
        vector<int>ns;
        if(nom==1){
        for(int i=1;i<=n;i++){
            if(vec[i]==0){
                if(seen[i]==0)vec[i]=i;
                break;
            }
        }
        }
        int st=-1;
        int end=-1;
        for(int i=1;i<=n;i++){
            if(vec[i]==i)continue;
            if(st==-1){
                st=i;
                end=i;
            }
            else {
                end=i;
            }
        }
        if(st==-1)ans.push_back(0);
        else ans.push_back(end-st+1);
    }
    for(int a:ans){
       
        cout<<a<<'\n';
    }
    return 0;
}