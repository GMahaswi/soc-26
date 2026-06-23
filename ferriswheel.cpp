
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,x;
    cin>>n>>x;
    vector<long long >vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    int p1=0;
    int p2=n-1;
    int ans=0;
    while(p2>=p1){
        if(p2==p1){
            ans++;
            break;
        }
        if(vec[p2]+vec[p1]<=x){
            ans++;
            p1++;
            p2--;
        }
        else {
            p2--;
            ans++;
        }
    }
    cout<<ans;
}