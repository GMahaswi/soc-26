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
        vector<int>veca(n);
        for(int i=0;i<n;i++)cin>>veca[i];
        vector<int>vecb(n);
        for(int i=0;i<n;i++)cin>>vecb[i];
        bool bobwin=true;
        for(int i=0;i<n;i++){
            if(veca[i]!=vecb[i]){
                bobwin=false;
                break;
            }
        }
        if(!bobwin){
            bool second=false;
            for(int i=0;i<n;i++){
                if(veca[i]!=vecb[n-1-i]){
                second=true;
                break;
            }
            }
            if(!second)bobwin=true;
        }
        if(bobwin)ans.push_back(2);
        else ans.push_back(1);
    }
    for(int a:ans){
        if(a==1){
            cout<<"Alice"<<endl;
        }
        else cout<<"Bob"<<endl;
    }
}