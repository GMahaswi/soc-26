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
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        map<int,pair<int,int>>mp;
        map<int,vector<int>>mp2;
        bool t=true;
        for(int i=0;i<n;){
            int val=vec[i];
            int st=i;
            while(i<n&&vec[i]==val){
                i++;
            }
            int lst=i-1;
            if(mp.find(vec[i])!=mp.end()){
                if(mp2.find(vec[i])!=mp2.end()){
                    t=false;
                    break;
                }
                int st1=mp[vec[i]].first;
                int lst1=mp[vec[i]].second;
                int l1=lst1-st1+1;
                int l2=lst-st+1;
                if(l1>1&&l2>1){
                    t=false;
                    break;
                }
                if(l1==1){
                    mp2[val].push_back(l1);
                }
                if(l2==1){
                    mp2[val].push_back(l2);
                }
            }
            if(!t){
                break;
            }
        }
        if(!t){
            cout<<"NO";
        }
    }
}