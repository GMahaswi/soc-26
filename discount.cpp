#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    int t;
    cin>>t;
    vector<int>ans;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<int>b(k);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<k;i++)cin>>b[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        sort(b.begin(),b.end());
        int as=0;
        int bs=0;
        int curr=0;
        int sum=0;
        for(int av:a){
            sum+=av;
        }
        while(curr<n&&bs<k){
            int bv=b[bs];
           
            if(bv+curr-1>=n){
                break;
            }
            sum=sum-a[bv+curr-1];
            curr=bv+curr;
            bs++;

        }
        ans.push_back(sum);
    }
    for(int a:ans)cout<<a<<'\n';

}