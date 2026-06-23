#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(long long i=0;i<n;i++){
        if(i!=0&&v[i]==v[i-1])continue;
        ans++;
    }
    cout<<ans;
}