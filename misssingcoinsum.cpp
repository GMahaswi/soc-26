#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long>vec(n);
    for(long long i=0;i<n;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    long long reachable=0;
    for(long long v:vec){
        if(reachable+1>=v){
            reachable=reachable+v;
        }
        else {
            cout<<reachable+1;
            return 0;
        }
    }
    cout<<reachable+1;
}
