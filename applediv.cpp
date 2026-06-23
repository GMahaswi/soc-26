#include<bits/stdc++.h>
using namespace std;
long long as=1e18;
void func(int i,vector<long long>v,long long total,long long sofar){
    if(i==v.size()){
        long long s1=total-sofar;
        as=min(as,abs(s1-sofar));
        
    }
    else{
    func(i+1,v,total,sofar+v[i]);
    func(i+1,v,total,sofar);
    }
}
int main(){
    int n;
    cin>>n;
    vector<long long >vec(n);
    long long total=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        total+=vec[i];
    }
    func(0,vec,total,0);
    cout<<as;
}