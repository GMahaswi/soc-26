#include<bits/stdc++.h>
using namespace std;
static bool cmp(vector<int>&v1,vector<int>&v2){
    if(v1[1]==v2[1])return v1[0]>v2[0];
    return v1[1]<v2[1];
}
static bool cmp1(vector<int>&v1,vector<int>&v2){
    if(v1[0]==v2[0])return v1[1]>v2[1];
    return v1[0]<v2[0];
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>vec(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>vec[i][0]>>vec[i][1];
    }
    map<pair<int,int>,int>mp;
    for(int i=0;i<n;i++){
        mp[{vec[i][0],vec[i][1]}]=i;
    }
    sort(vec.begin(),vec.end(),cmp1);
    
    multiset<int>set1;
    vector<int>sec(n,0);
    for(int i=0;i<n;i++){
        auto it=set1.lower_bound(vec[i][1]);
        int count=distance(it,set1.end());
        sec[mp[{vec[i][0],vec[i][1]}]]+=count;
        set1.insert(vec[i][1]);
        
    }
    sort(vec.begin(),vec.end(),cmp);
    multiset<int>set2;
    vector<int>fst(n,0);
    for(int i=0;i<n;i++){
      auto it=set2.lower_bound(vec[i][0]);
        int count=distance(it,set2.end());
        fst[mp[{vec[i][0],vec[i][1]}]]+=count;
        set2.insert(vec[i][0]);
    }
    for(int a:fst)cout<<a<<" ";
    cout<<endl;
    for(int a:sec)cout<<a<<" ";
}