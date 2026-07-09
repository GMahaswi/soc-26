#include<bits/stdc++.h>
using namespace std;
#define int long long
int func(){
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)cin>>vec[i];
    vector<int>vect;
    int i=0;
    while(i<n){
        int p=vec[i];
        int s=0;
        while(i<n&&((vec[i]*vec[i])>=0)){
            s+=vec[i];
            i++;
        }
        vect.push_back(s);
    }
    4
}
int main(){
    int t;
    cin>>t;
    while(t--){
        func();
    }
}