#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(){
 
    ll t;
    cin>>t;
    while(t--){
 
        ll n,k;
        cin>>n>>k;
        if(n==1){
            cout<<1<<endl;
            cout<<1<<endl;
            continue;
        }
        if(k==1 || k==n){
            cout<<-1<<endl;
            continue;
        }
        bool a=((k-1)%2==1);
        bool b=((n-k)%2==1);
        if(a && b){
            cout<<3<<endl;
            cout<<1<<" "<<k<<" "<<k+1<<endl;     
        }
        else{
            cout<<3<<endl;
            cout<<1<<" "<<k-1<<" "<<k+2<<endl;
        }
    }
}