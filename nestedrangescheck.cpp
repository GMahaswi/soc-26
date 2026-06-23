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
    int maxi=INT_MIN;
    vector<int>sec(n,0);
    for(int i=0;i<n;i++){
        if(maxi>=vec[i][1])sec[mp[{vec[i][0],vec[i][1]}]]=1;
        maxi=max(vec[i][1],maxi);
    }
    sort(vec.begin(),vec.end(),cmp);
    int maxxi=INT_MIN;
    vector<int>fst(n,0);
    for(int i=0;i<n;i++){
        if(maxxi>=vec[i][0])fst[mp[{vec[i][0],vec[i][1]}]]=1;
        maxxi=max(vec[i][0],maxxi);
    }
    for(int a:fst)cout<<a<<" ";
    cout<<endl;
    for(int a:sec)cout<<a<<" ";
}