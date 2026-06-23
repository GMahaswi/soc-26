#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[vec[i]]=-1;
    }
    int s=0;
    int l=0;
    long long ans=0;
    while(l<n){
        if(mp[vec[l]]!=-1){
            
            for(int j=s;j<=mp[vec[l]];j++){
                s++;
                mp[vec[j]]=-1;
            }
            
        }
        mp[vec[l]]=l;
        ans=ans+(l-s+1);
        l++;
    }
    
    cout<<ans;
}