#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    vector<int>posi(n+1);
    int ans=n;
    for(int i=0;i<n;i++){
        posi[vec[i]]=i;
    }
    for(int i=1;i<=n-1;i++){
        if(posi[i]<posi[i+1])ans--;
    }
    cout<<ans;
}