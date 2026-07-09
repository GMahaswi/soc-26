#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        int sum=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=vec[i];
            if(vec[i]!=0)mp[sum]=i;
        }
        int q;
        cin>>q;
        while(q--){
            int l,u;
            cin>>l>>>u;
            int val=vec[l-1];
            int search=val+u;
            
        }
    }
}