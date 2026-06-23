#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    map<int,int>frequency;
    for(int i:vec)frequency[i]=0;
    long long ans=1;
    for(int i=0;i<n;i++){
        frequency[vec[i]]++;
        
    }
    for (auto const& [element, count] : frequency) {
        ans = (ans * (count + 1)) % mod;
    }

    cout<<ans-1;
}