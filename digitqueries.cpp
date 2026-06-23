#include<bits/stdc++.h>
using namespace std;
int func(long long ind){
    long long g=1;
    long long sum=0;
    long long gh=1;
    long long old=0;
    while(1){
        long long curr=9*g;
        long long ns=sum+(curr*gh);
        if(ind<=ns){
            long long n=(ind-sum-1)/gh;
            long long m=(ind-sum-1)%gh;
            long long val=g+n;
            string s = to_string(val);
            cout<<s[m]<<endl;
            return 0;

        }
        sum=ns;
        old=curr;
        g=g*10;
        gh++;
    }
    return 0;
}
int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        long long ind;
        cin>>ind;
        func(ind);
    }
}