#include<bits/stdc++.h>
using namespace std;
#define int long long
bool func(){
        int n,c,d;
        cin>>n>>c>>d;
        int sqr=n*n;
        vector<int>vec(sqr);
        
        for(int i=0;i<sqr;i++)cin>>vec[i];
        int mini=*min_element(vec.begin(), vec.end());
        
        map<int,int>mp;
        for(int i=0;i<sqr;i++){
            mp[vec[i]]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr=mini+(i*c)+(j*d);
                mp[curr]--;
                if(mp[curr]<0)return false;
            }
        }
        return true;
}
int32_t main(){
    int t;
    cin>>t;
    
    vector<bool>as;
    while(t--){
        as.push_back(func());
    }
    for(bool a:as){
        if(a)cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}