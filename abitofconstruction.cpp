#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    
    vector<vector<int>>as(t);
    for(int j=0;j<t;j++){
        int n,k;
        cin>>n>>k;
        if(n==1){
           as[j].push_back(k);
        }
        else {
            int a,b;
            a=0;
            b=0;
            int last=log2(k);
            int c=0;
            for(int i=0;i<last;i++){
                int powi=(1<<i);
                if(k&(powi)){
                    if(c==0){
                        a=a|powi;
                    }
                    else {
                        a=a|powi;
                        b=b|powi;
                    }
                }
                else {
                    if(c!=0){
                        a=a|powi;
                        
                    }
                    else {
                        a=a|powi;
                        b=b|powi;
                        c=1;
                    }
                }
            }
            if(c!=1){
                a=a|(1<<(last));
            }
            as[j].push_back(a);
            as[j].push_back(b);
            for(int i=2;i<n;i++){
                as[j].push_back(0);
            }
        }
        
    }
    for(auto v:as){
        for(int val:v){
            cout<<val<<" ";
        }
        cout<<'\n';
    }
    return 0;
}