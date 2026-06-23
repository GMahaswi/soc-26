
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long curr=0;
    vector<long long>psum(n);
    for(int i=0;i<n;i++){
        curr=curr+v[i];
        psum[i]=curr;
    }
    long long mini=0;
    long long maxi=INT_MIN;
    for(int i=0;i<n;i++){
        long long a=psum[i];
        
        maxi=max(psum[i]-mini,maxi);
        mini=min(a,mini);
    }
    cout<<maxi;
}