#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long k;
    cin >> k;
    if(k>0){
        cout<<0<<endl;
    }
    for(long long i=2;i<=k;i++){
        long long s=i*i;
        long long t=((s)*(s-1))/2;
        long long r=4*(i-3+1)*(i-2+1);
        cout<<t-r<<endl;
    }
    return 0;
}